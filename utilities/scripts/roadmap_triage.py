#!/usr/bin/env python3
"""Triage the roadmap tickets: scan, classify, prune, assign status labels.

Scans every open issue labeled `roadmap` and checks it against ROADMAP.md and
the artifacts its body links to, then assigns one status label:

  status/ready        in the roadmap, unblocked, all linked artifacts check out
  status/pending      open, but missing linked files / incomplete reports / setup
  status/blocked      gated (hardware safety) or waiting on another open ticket
  status/in-progress  claimed by an agent via --pick; PR work ongoing
  status/pruned       no longer referenced by ROADMAP.md, or a duplicate (closed)
  status/stale        no activity for --stale-days (informational, stays open)

Without --apply the run is a dry run and only prints the plan.
--pick selects the top status/ready ticket (milestone order, then issue
number) and prints it as a context pack for an agent session; with --apply
it also claims the ticket by moving it to status/in-progress.

Usage:
  python utilities/scripts/roadmap_triage.py --repo owner/repo [--apply] [--stale-days N] [--pick]
"""
import argparse
import json
import os
import re
import subprocess
import sys
import tempfile
from dataclasses import dataclass, field
from datetime import datetime, timedelta, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

STATUS_LABELS = {
    "status/ready": ("2ea043", "triage: ready to pick up"),
    "status/pending": ("d29922", "triage: open, missing pieces before pickup"),
    "status/blocked": ("d73a4a", "triage: gated or waiting on another ticket"),
    "status/in-progress": ("8250df", "triage: claimed by an agent, PR work ongoing"),
    "status/pruned": ("6e7781", "triage: pruned (left the roadmap or duplicate)"),
    "status/stale": ("0969da", "triage: no activity for a long time"),
}

GROUP_FEASIBILITY = {
    "C": "static labeling & gap closure: feasible offline (pipeline validators + emulator harness)",
    "D": "docs/data discrepancy: feasible as a desk investigation against ROM bytes and docs",
    "E": "reimplementation: feasible with host tests + emulator cross-checks",
    "F": "toward hardware: gated - bench validation required before any flash (AGENTS.md rule 10)",
}
REGISTER_FEASIBILITY = {
    "E": "emulator fidelity: feasible inside the SH-2E emulator",
    "D": "docs/data discrepancy: feasible as a desk investigation",
}

DEPENDS = {"F2": ["D9"]}

ITEM_ID_RE = re.compile(r"^\s*([A-Z]\d+)\b")
LINK_RE = re.compile(r"\]\(([^)]+)\)")
ADDR_RE = re.compile(r"0x[0-9a-fA-F]{4,8}\b")
REQUIRED_REPORT_SECTIONS = ["executive summary", "pseudocode", "memory map", "validation", "limits"]


def gh(*args, check=True):
    return subprocess.run(["gh", *args], capture_output=True, text=True, check=check)


def parse_item_id(title):
    m = ITEM_ID_RE.match(title or "")
    return m.group(1) if m else None


def extract_repo_paths(body, repo):
    prefix = f"https://github.com/{repo}/blob/main/"
    paths = []
    for target in LINK_RE.findall(body or ""):
        t = target.split("#")[0].strip()
        if t.startswith(prefix):
            t = t[len(prefix):]
        elif t.startswith("http"):
            continue
        t = t.lstrip("/")
        if t:
            paths.append(t)
    return paths


def extract_addresses(body):
    return ADDR_RE.findall(body or "")


def norm_addr(a):
    return a.lower().removeprefix("0x").zfill(8)


def load_known_addresses(root):
    known = set()
    for rel in (
        "reverse-engineered/decompiled/60E15120_N3J1E/function_index.tsv",
        "docs/investigations/60E15120_N3J1E/source_review/accepted_ram_aliases.tsv",
    ):
        p = root / rel
        if not p.exists():
            continue
        with p.open(newline="") as f:
            header = f.readline().rstrip("\n").split("\t")
            if "address" not in header:
                continue
            i = header.index("address")
            for line in f:
                parts = line.rstrip("\n").split("\t")
                if len(parts) > i and parts[i]:
                    known.add(norm_addr(parts[i]))
    return known


def check_report(path):
    problems = []
    p = Path(path)
    if not p.exists():
        return ["missing file"]
    text = p.read_text(errors="replace")
    low = text.lower()
    if "further investigation needed" in low:
        problems.append("report itself is marked FURTHER INVESTIGATION NEEDED")
    for section in REQUIRED_REPORT_SECTIONS:
        if section not in low:
            problems.append(f"report lacks a '{section}' section")
    return problems


def in_roadmap(item_id, roadmap_text):
    letter, num = item_id[0], item_id[1:]
    pattern = rf"\b{re.escape(item_id)}\b|\b{re.escape(letter)}\s+item\s+{re.escape(num)}\b"
    return re.search(pattern, roadmap_text, re.IGNORECASE) is not None


@dataclass
class Triage:
    number: int
    item_id: str | None
    title: str
    status: str
    feasibility: str = ""
    report_problems: list = field(default_factory=list)
    missing: list = field(default_factory=list)
    unverified: list = field(default_factory=list)
    blockers: list = field(default_factory=list)
    stale: bool = False


def feasibility_for(issue, item_id):
    label_names = {l["name"] for l in issue.get("labels", [])}
    if "register" in label_names:
        return REGISTER_FEASIBILITY.get(item_id[0], "register item: desk investigation")
    return GROUP_FEASIBILITY.get(item_id[0], "unknown group")


def classify(issue, roadmap_text, open_item_ids, duplicate_numbers, root, repo, known_addresses, stale_days):
    number = issue["number"]
    title = issue.get("title", "")
    item_id = parse_item_id(title)
    t = Triage(number=number, item_id=item_id, title=title, status="status/pending")
    if item_id is None:
        t.missing.append("title carries no item id")
        return t
    label_names = {l["name"] for l in issue.get("labels", [])}
    if "status/in-progress" in label_names:
        t.status = "status/in-progress"
        return t
    t.feasibility = feasibility_for(issue, item_id)
    if not in_roadmap(item_id, roadmap_text):
        t.status = "status/pruned"
        t.missing.append(f"{item_id} no longer referenced in ROADMAP.md (record lives in its git history)")
        return t
    if number in duplicate_numbers:
        t.status = "status/pruned"
        t.missing.append(f"duplicate of a lower-numbered ticket for {item_id}")
        return t
    body = issue.get("body", "")
    t.blockers = [d for d in DEPENDS.get(item_id, []) if d in open_item_ids]
    if "gated" in label_names:
        t.blockers.append("gated label (bench validation required)")
    for path in extract_repo_paths(body, repo):
        full = root / path
        if not full.exists():
            t.missing.append(f"linked file missing in repo: {path}")
        elif path.endswith("_report.md"):
            for prob in check_report(full):
                t.report_problems.append(f"{path}: {prob}")
    unresolved = sorted({a for a in extract_addresses(body) if norm_addr(a) not in known_addresses})
    if unresolved:
        shown = ", ".join(unresolved[:5]) + (" ..." if len(unresolved) > 5 else "")
        t.unverified.append(f"{len(unresolved)} address(es) not in the export/label indexes: {shown}")
    if issue.get("milestone") is None:
        t.missing.append("no milestone assigned")
    if not any(n.startswith("group-") or n == "register" for n in label_names):
        t.missing.append("no group label (group-c/e/f or register)")
    if t.blockers:
        t.status = "status/blocked"
    elif t.missing or t.report_problems:
        t.status = "status/pending"
    else:
        t.status = "status/ready"
    if stale_days > 0:
        updated = issue.get("updatedAt")
        if updated:
            dt = datetime.fromisoformat(updated.replace("Z", "+00:00"))
            if dt < datetime.now(timezone.utc) - timedelta(days=stale_days):
                t.stale = True
    return t


def select_next(pairs):
    ready = [(i, t) for i, t in pairs if t.status == "status/ready"]
    if not ready:
        return None
    return min(ready, key=lambda p: ((p[0].get("milestone") or {}).get("number", 10**9), p[0]["number"]))


def render_comment(t):
    lines = [
        "### Triage report",
        f"- **Status:** `{t.status}`",
        f"- **Feasibility:** {t.feasibility}",
    ]
    if t.report_problems:
        lines.append("- **Report quality:**")
        lines += [f"  - {p}" for p in t.report_problems]
    else:
        lines.append("- **Report quality:** all linked reports pass the section checks")
    if t.blockers:
        lines.append(f"- **Blockers:** {', '.join(t.blockers)}")
    if t.missing:
        lines.append("- **Missing before pickup:**")
        lines += [f"  - {m}" for m in t.missing]
    else:
        lines.append("- **Missing before pickup:** nothing - ready")
    if t.unverified:
        lines.append("- **Unverified references (informational):**")
        lines += [f"  - {u}" for u in t.unverified]
    if t.stale:
        lines.append("- **Stale:** no activity for the configured threshold")
    return "\n".join(lines)


def ensure_labels(repo):
    out = gh("label", "list", "--repo", repo, "--limit", "200", "--json", "name", check=False).stdout
    existing = {l["name"] for l in json.loads(out)} if out.strip() else set()
    for name, (color, desc) in STATUS_LABELS.items():
        if name not in existing:
            gh("label", "create", name, "--repo", repo, "--color", color, "--description", desc, check=False)


def apply_triage(repo, issue, t, comment_always=False):
    current = [l["name"] for l in issue.get("labels", []) if l["name"].startswith("status/")]
    new_status = t.status
    changed = new_status not in current or (t.stale and "status/stale" not in current) or (not t.stale and "status/stale" in current)
    args = ["issue", "edit", str(t.number), "--repo", repo]
    for l in current:
        keep = l == new_status or (l == "status/stale" and t.stale)
        if not keep:
            args += ["--remove-label", l]
    if new_status not in current:
        args += ["--add-label", new_status]
    if t.stale and "status/stale" not in current:
        args += ["--add-label", "status/stale"]
    gh(*args)
    if new_status == "status/pruned":
        with tempfile.NamedTemporaryFile("w", suffix=".md", delete=False) as f:
            f.write(render_comment(t) + "\n\nPruned automatically: the item is no longer tracked in ROADMAP.md or is a duplicate. The full record stays in ROADMAP.md git history and in this ticket.\n")
            path = f.name
        gh("issue", "close", str(t.number), "--repo", repo, "--reason", "completed", "--comment", "Closed by roadmap-triage: pruned.", check=False)
        gh("issue", "comment", str(t.number), "--repo", repo, "--body-file", path)
        os.unlink(path)
    elif changed or comment_always:
        with tempfile.NamedTemporaryFile("w", suffix=".md", delete=False) as f:
            f.write(render_comment(t) + "\n")
            path = f.name
        gh("issue", "comment", str(t.number), "--repo", repo, "--body-file", path)
        os.unlink(path)


def claim_ticket(repo, issue, t):
    gh("issue", "edit", str(t.number), "--repo", repo, "--remove-label", "status/ready", "--add-label", "status/in-progress")
    body = (
        "Claimed for pickup (`roadmap_triage.py --pick`).\n\n"
        "An agent works this ticket on its own branch per AGENTS.md (branch + PR against `main`, never direct commits); "
        "the PR link is posted here when opened. The next triage run leaves this ticket at `status/in-progress` until the item is pruned from ROADMAP.md, which closes the ticket as `status/pruned`.\n\n"
        + render_comment(t)
    )
    with tempfile.NamedTemporaryFile("w", suffix=".md", delete=False) as f:
        f.write(body + "\n")
        path = f.name
    gh("issue", "comment", str(t.number), "--repo", repo, "--body-file", path)
    os.unlink(path)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--repo", default=os.environ.get("GITHUB_REPOSITORY", "sirhamsteralot/HEE-Rx8-Reverse-Engineering"))
    ap.add_argument("--apply", action="store_true", help="apply labels/comments/closes (default: dry run)")
    ap.add_argument("--stale-days", type=int, default=0)
    ap.add_argument("--comment-always", action="store_true")
    ap.add_argument("--pick", action="store_true", help="print the top status/ready ticket as an agent context pack (with --apply: claim it as status/in-progress)")
    args = ap.parse_args()

    roadmap_text = (ROOT / "ROADMAP.md").read_text()
    known_addresses = load_known_addresses(ROOT)
    issues = json.loads(gh("issue", "list", "--repo", args.repo, "--label", "roadmap", "--state", "open", "--limit", "200", "--json", "number,title,body,labels,milestone,updatedAt,url").stdout)

    by_id = {}
    for i in issues:
        iid = parse_item_id(i.get("title", ""))
        if iid:
            by_id.setdefault(iid, []).append(i["number"])
    duplicate_numbers = {n for nums in by_id.values() if len(nums) > 1 for n in sorted(nums)[1:]}
    open_item_ids = set(by_id)

    sorted_issues = sorted(issues, key=lambda i: i["number"])
    triages = []
    for issue in sorted_issues:
        triages.append(classify(issue, roadmap_text, open_item_ids, duplicate_numbers, ROOT, args.repo, known_addresses, args.stale_days))

    if args.pick:
        sel = select_next(list(zip(sorted_issues, triages)))
        if sel is None:
            print("no status/ready ticket available")
            return 0
        issue, t = sel
        pack = {
            "issue": issue["number"],
            "url": issue.get("url"),
            "title": t.title,
            "item_id": t.item_id,
            "milestone": (issue.get("milestone") or {}).get("title"),
            "feasibility": t.feasibility,
            "linked_paths": extract_repo_paths(issue.get("body", ""), args.repo),
            "report_problems": t.report_problems,
            "missing": t.missing,
            "unverified": t.unverified,
            "blockers": t.blockers,
            "body": issue.get("body", ""),
        }
        print(json.dumps(pack, indent=2))
        if args.apply:
            ensure_labels(args.repo)
            claim_ticket(args.repo, issue, t)
            print(f"claimed #{t.number} -> status/in-progress")
        return 0

    order = {"status/ready": 0, "status/pending": 1, "status/in-progress": 2, "status/blocked": 3, "status/pruned": 4}
    lines = ["## Roadmap triage plan", ""]
    for t in sorted(triages, key=lambda t: (order.get(t.status, 9), t.number)):
        lines.append(f"- #{t.number} `{t.item_id or '?'}` -> **{t.status}**" + (" (stale)" if t.stale else ""))
        lines.append(f"  - {t.title}")
        lines.append(f"  - feasibility: {t.feasibility}")
        for p in t.report_problems:
            lines.append(f"  - report: {p}")
        for m in t.missing:
            lines.append(f"  - missing: {m}")
        for u in t.unverified:
            lines.append(f"  - unverified: {u}")
        for b in t.blockers:
            lines.append(f"  - blocker: {b}")
        lines.append("")
    summary = "\n".join(lines)
    print(summary)
    if os.environ.get("GITHUB_STEP_SUMMARY"):
        with open(os.environ["GITHUB_STEP_SUMMARY"], "a") as f:
            f.write(summary + "\n")

    if args.apply:
        ensure_labels(args.repo)
        for issue, t in zip(sorted_issues, triages):
            apply_triage(args.repo, issue, t, comment_always=args.comment_always)
        print(f"applied to {len(triages)} ticket(s)")
    else:
        print("dry run - no changes made (pass --apply to apply)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
