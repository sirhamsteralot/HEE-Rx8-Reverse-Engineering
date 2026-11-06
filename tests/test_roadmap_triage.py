"""Tests for the roadmap ticket triage script (utilities/scripts/roadmap_triage.py).

Covers the pure classification logic: item-id parsing, link extraction,
report-quality checks, address resolution, and the status decision
(ready / pending / blocked / pruned / stale). Uses synthetic item ids.

Run: python -m pytest tests/test_roadmap_triage.py
"""
import os
import sys

import pytest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "utilities", "scripts"))

import roadmap_triage as rt  # noqa: E402

REPO = "octo/demo"


def make_issue(number=1, title="Q7 - synthetic ticket", body="", labels=None, milestone={"title": "m"}, updated="2026-01-01T00:00:00Z"):
    return {
        "number": number,
        "title": title,
        "body": body,
        "labels": [{"name": n} for n in (labels or ["roadmap", "group-q"])],
        "milestone": milestone,
        "updatedAt": updated,
    }


def make_root(tmp_path, report_text=None):
    docs = tmp_path / "docs" / "investigations"
    docs.mkdir(parents=True)
    if report_text is not None:
        (docs / "demo_report.md").write_text(report_text)
    return tmp_path


GOOD_REPORT = (
    "# Demo report\n\n## Executive summary\n\nx\n\n## Pseudocode\n\nx\n\n"
    "## Memory map\n\nx\n\n## Validation\n\nx\n\n## Limits\n\nx\n"
)


def test_in_roadmap_both_forms():
    assert rt.in_roadmap("Q7", "- **Q item 7 (open)** - scope")
    assert rt.in_roadmap("Q7", "work item Q7 is listed")
    assert not rt.in_roadmap("Q7", "- **Q item 8 (open)** only")
    assert not rt.in_roadmap("Q7", "nothing here")


def test_classify_unverified_addresses_are_informational(tmp_path):
    root = make_root(tmp_path)
    t = rt.classify(make_issue(body="addr 0xDEADBEEF"), "Q7", {"Q7"}, set(), root, REPO, set(), 0)
    assert t.status == "status/ready"
    assert t.unverified and "0xDEADBEEF" in t.unverified[0]


def test_parse_item_id():
    assert rt.parse_item_id("Q7 - synthetic ticket") == "Q7"
    assert rt.parse_item_id("D12 — em dash title") == "D12"
    assert rt.parse_item_id("no id here") is None
    assert rt.parse_item_id("") is None


def test_extract_repo_paths():
    body = (
        f"[r](https://github.com/{REPO}/blob/main/docs/a_report.md) "
        "[ext](https://example.com/x.md) "
        "[rel](docs/b_report.md#frag)"
    )
    assert rt.extract_repo_paths(body, REPO) == ["docs/a_report.md", "docs/b_report.md"]


def test_extract_and_norm_addresses():
    assert rt.extract_addresses("call 0x08001234 and 0xFFFFD1EA") == ["0x08001234", "0xFFFFD1EA"]
    assert rt.norm_addr("0xFFFFD1EA") == "ffffd1ea"


def test_check_report(tmp_path):
    good = tmp_path / "good_report.md"
    good.write_text(GOOD_REPORT)
    assert rt.check_report(good) == []
    bad = tmp_path / "bad_report.md"
    bad.write_text("# T\n\nFURTHER INVESTIGATION NEEDED\n\n## Executive summary\n")
    problems = rt.check_report(bad)
    assert any("FURTHER INVESTIGATION NEEDED" in p for p in problems)
    assert any("memory map" in p for p in problems)
    assert rt.check_report(tmp_path / "nope_report.md") == ["missing file"]


def test_load_known_addresses(tmp_path):
    d = tmp_path / "reverse-engineered" / "decompiled" / "60E15120_N3J1E"
    d.mkdir(parents=True)
    (d / "function_index.tsv").write_text("address\tname\n00000040\tFUN_00000040\n")
    known = rt.load_known_addresses(tmp_path)
    assert known == {"00000040"}


def test_classify_ready(tmp_path):
    root = make_root(tmp_path, GOOD_REPORT)
    body = f"see [report](https://github.com/{REPO}/blob/main/docs/investigations/demo_report.md) addr 0x00000040"
    issue = make_issue(body=body)
    t = rt.classify(issue, "open work: Q7 is listed", {"Q7"}, set(), root, REPO, {"00000040"}, 0)
    assert t.status == "status/ready"
    assert t.missing == [] and t.report_problems == []


def test_classify_pending_missing_file_and_report(tmp_path):
    root = make_root(tmp_path, "# T\n\n## Executive summary\nonly\n")
    body = f"[a](https://github.com/{REPO}/blob/main/docs/gone.md) [b](https://github.com/{REPO}/blob/main/docs/investigations/demo_report.md)"
    t = rt.classify(make_issue(body=body), "Q7 listed", {"Q7"}, set(), root, REPO, set(), 0)
    assert t.status == "status/pending"
    assert any("missing in repo" in m for m in t.missing)
    assert t.report_problems


def test_classify_blocked_gated_and_dep(tmp_path, monkeypatch):
    monkeypatch.setattr(rt, "DEPENDS", {"Q7": ["Q8"]})
    root = make_root(tmp_path)
    t = rt.classify(make_issue(labels=["roadmap", "group-q", "gated"]), "Q7 Q8", {"Q7", "Q8"}, set(), root, REPO, set(), 0)
    assert t.status == "status/blocked"
    assert any("gated" in b for b in t.blockers) and "Q8" in t.blockers
    t2 = rt.classify(make_issue(), "Q7 Q8", {"Q7", "Q8"}, set(), root, REPO, set(), 0)
    assert t2.status == "status/blocked" and t2.blockers == ["Q8"]


def test_classify_pruned_not_in_roadmap_and_duplicate(tmp_path):
    root = make_root(tmp_path)
    t = rt.classify(make_issue(number=5), "Q7 listed", {"Q7"}, {5}, root, REPO, set(), 0)
    assert t.status == "status/pruned" and any("duplicate" in m for m in t.missing)
    t2 = rt.classify(make_issue(number=4), "some other text", {"Q7"}, set(), root, REPO, set(), 0)
    assert t2.status == "status/pruned" and any("no longer referenced" in m for m in t2.missing)


def test_classify_stale(tmp_path):
    root = make_root(tmp_path)
    issue = make_issue(updated="2020-01-01T00:00:00Z")
    t = rt.classify(issue, "Q7", {"Q7"}, set(), root, REPO, set(), 30)
    assert t.stale
    t2 = rt.classify(issue, "Q7", {"Q7"}, set(), root, REPO, set(), 0)
    assert not t2.stale


def test_render_comment_mentions_status(tmp_path):
    t = rt.Triage(number=1, item_id="Q7", title="t", status="status/ready", feasibility="f")
    out = rt.render_comment(t)
    assert "status/ready" in out and "ready" in out


def test_missing_setup_flags(tmp_path):
    root = make_root(tmp_path)
    issue = make_issue(labels=["roadmap"], milestone=None)
    t = rt.classify(issue, "Q7", {"Q7"}, set(), root, REPO, set(), 0)
    assert t.status == "status/pending"
    assert any("milestone" in m for m in t.missing) and any("group label" in m for m in t.missing)


if __name__ == "__main__":
    sys.exit(pytest.main([__file__, "-q"]))
