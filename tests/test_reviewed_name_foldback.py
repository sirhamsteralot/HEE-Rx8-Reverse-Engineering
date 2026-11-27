#!/usr/bin/env python3
"""Regeneration and consistency checks for the reviewed-name fold-back.

The decompiled export is generated (AGENTS.md rule 6d). Its naming chain is
`annotate_source_review.py` -> `integrate_reviewed_names.py` ->
`refine_comment_merge.py` in
[`rebuild.sh`](../utilities/scripts/rx8-pcm-pipeline/rebuild.sh), so:

  * the chain must regenerate the committed export unchanged - otherwise a
    re-run silently drops or mangles reviewed names (the drift the fold-back
    pass exists to remove);
  * every function body must declare the name `function_index.tsv` carries for
    it, and every body must occur verbatim in both monoliths;
  * no accepted alias may be left as an address-based identifier in the code,
    and no alias may name two functions (the export would be ambiguous).

The comparison is on normalized text (CRLF folded to LF, what git stores under
the repository's `text=auto` attribute): individual passes write LF, a few of the
older ones CRLF, so a raw byte compare would fail on line-ending churn alone. The
only whitelisted volatile field is `files_changed_this_run` in
`integrated_names.json`, which records what the last run touched; the
comment-merge pass writes per-run counters into its own validation.json.

Run: python -m pytest tests/test_reviewed_name_foldback.py
"""
import csv
import json
import re
import subprocess
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[1]
EXPORT = REPO / "reverse-engineered/decompiled/60E15120_N3J1E"
LABELS = REPO / "data/labels/60E15120_N3J1E"
PIPELINE = REPO / "utilities/scripts/rx8-pcm-pipeline"
CHAIN = ["annotate_source_review.py", "integrate_reviewed_names.py", "refine_comment_merge.py"]
ADDRESS_IDENT = re.compile(r"\b(jump_to_FUN_|thunk_FUN_|FUN_|DAT_)([0-9A-Fa-f]{8})\b")
COMMENT = re.compile(r"/\*.*?\*/|//[^\n]*", re.S)

pytestmark = pytest.mark.skipif(not EXPORT.is_dir(), reason="decompiled export not present")


def read_tsv(path):
    with path.open(newline="", encoding="utf-8", errors="surrogateescape") as fh:
        return list(csv.DictReader(fh, delimiter="\t"))


def index_rows():
    return read_tsv(EXPORT / "function_index.tsv")


def accepted_aliases():
    """address -> alias exactly as integrate_reviewed_names.py applies it."""
    aliases = {}
    for r in read_tsv(
        REPO / "docs/investigations/60E15120_N3J1E/labeling/source_review/accepted_function_aliases.tsv"
    ):
        aliases[r["address"]] = ("candidate_" if r["confidence"] == "medium" else "") + r["alias"]
    return aliases


def test_foldback_chain_regenerates_the_committed_export():
    """Re-running annotation + integration + comment-merge must be a no-op."""
    touched = sorted(EXPORT.rglob("*.c")) + [EXPORT / "function_index.tsv",
                                             EXPORT / "callgraph.tsv", EXPORT / "symbols.tsv",
                                             LABELS / "integrated_names.json"]
    def normalized(path):
        return path.read_bytes().replace(b"\r\n", b"\n")

    before = {p: normalized(p) for p in touched}
    try:
        for script in CHAIN:
            subprocess.run([sys.executable, str(PIPELINE / script)], cwd=REPO, check=True,
                           capture_output=True)
        drifted = []
        for path, raw in before.items():
            if path.name == "integrated_names.json":
                committed = json.loads(raw)
                regenerated = json.loads(path.read_text(encoding="utf-8"))
                volatile = ("files_changed_this_run",)
                committed = {k: v for k, v in committed.items() if k not in volatile}
                regenerated = {k: v for k, v in regenerated.items() if k not in volatile}
                if committed != regenerated:
                    drifted.append(path)
            elif normalized(path) != raw:
                drifted.append(path)
        assert not drifted, (
            "re-running the reviewed-name chain changed %d committed file(s), first: %s - "
            "edit the generators and re-run them instead of hand-editing the export (rule 6d)"
            % (len(drifted), drifted[0].relative_to(REPO))
        )
    finally:
        for path, content in before.items():
            path.write_bytes(content)


def test_every_body_declares_the_index_name():
    """`integrate_reviewed_names.py` asserts this; the committed tree must hold it."""
    broken = []
    for r in index_rows():
        body = (EXPORT / r["file"]).read_text(encoding="utf-8", errors="surrogateescape")
        if not re.search(r"\b" + re.escape(r["name"]) + r"\s*\(", body):
            broken.append((r["address"], r["name"], r["file"]))
    assert not broken, "body does not declare the index name: %r" % broken[:5]


def test_bodies_are_present_in_both_monoliths():
    mono = (EXPORT / "firmware_decompiled.c").read_text(encoding="utf-8", errors="surrogateescape")
    named = (EXPORT / "named/firmware_named.c").read_text(encoding="utf-8", errors="surrogateescape")
    assert mono == named, "the canonical listing and the named view diverged"
    missing = []
    for r in index_rows():
        body = (EXPORT / r["file"]).read_text(encoding="utf-8", errors="surrogateescape")
        anchor = "/* ROM address: 0x" + r["address"] + ";"
        if body[body.index(anchor):].strip() not in mono:
            missing.append(r["address"])
    assert not missing, "function body missing from firmware_decompiled.c: %r" % missing[:5]


def test_no_accepted_alias_stays_address_based():
    """A named function's address identity must be gone from the code, comments aside."""
    aliases = accepted_aliases()
    byaddr = {r["address"]: r for r in index_rows()}
    left = []
    for addr, alias in aliases.items():
        row = byaddr.get(addr)
        assert row is not None, "accepted alias for a function missing from the index: %s" % addr
        body = (EXPORT / row["file"]).read_text(encoding="utf-8", errors="surrogateescape")
        code = COMMENT.sub("", body)
        for m in ADDRESS_IDENT.finditer(code):
            prefix, hexaddr = m.group(1), m.group(2).lower()
            if prefix in ("jump_to_FUN_", "thunk_FUN_"):
                # the thunk identity names its target, not its own address
                continue
            if prefix == "FUN_" and hexaddr == addr and alias != "FUN_" + hexaddr:
                left.append((addr, m.group(0), alias))
    assert not left, "address-based identifier survived the fold-back: %r" % left[:5]


def test_no_alias_names_two_functions():
    """Two rows with one name make the C listing ambiguous."""
    rows = index_rows()
    seen = {}
    for r in rows:
        seen.setdefault(r["name"], []).append(r)
    duplicates = {name: [r["address"] for r in rs] for name, rs in seen.items() if len(rs) > 1}
    # Thunks that jump to the same target share one target-derived identity in the
    # export (their file names carry the address); nothing else may collide.
    unexplained = {
        name: addrs for name, addrs in duplicates.items()
        if not all(Path(r["file"]).stem.split("_", 1)[1].startswith("thunk_FUN_")
                   for r in rows if r["address"] in addrs)
    }
    assert not unexplained, "one alias names several functions: %r" % unexplained
