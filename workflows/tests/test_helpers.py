import sys
from datetime import datetime, timezone
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "apps" / "worker" / "src"))

from worker.workflows.upstream_submodule_sync import (
    SubmoduleChange,
    SyncInput,
    audit_prompt,
    branch_name_for,
    pr_body_for,
    pr_title_for,
    _truncate,
)


def _change(name="RX8Defs", pinned="a" * 40, latest="b" * 40, count=3):
    return SubmoduleChange(
        name=name,
        path=f"submodules/{name}",
        pinned_sha=pinned,
        latest_sha=latest,
        new_commit_count=count,
        commit_log=f"{latest[:7]} upstream fix\n{pinned[:7]} old",
        diff_stat=" 2 files changed",
        changed_files=["defs/60E.xml", "README.md"],
        xml_diff="--- a/defs/60E.xml\n+++ b/defs/60E.xml\n@@\n-<Scalar id=\"1\">",
    )


def test_truncate():
    assert _truncate("abc", 5) == "abc"
    out = _truncate("x" * 10, 5)
    assert out.startswith("xxxxx") and "truncated" in out


def test_branch_name():
    when = datetime(2026, 3, 1, tzinfo=timezone.utc)
    name = branch_name_for("research/upstream-submodule-sync-", [_change()], when)
    assert name == "research/upstream-submodule-sync-20260301-bbbbbbb"


def test_pr_title_and_body():
    changes = [_change(), _change("Rx8Man", "c" * 40, "d" * 40, 1)]
    title = pr_title_for(changes)
    assert title.startswith("research: sync submodules to RX8Defs bbbbbbb")
    body = pr_body_for(changes, "AUDIT TEXT")
    assert "RX8Defs" in body and "3 new upstream commits" in body
    assert "AUDIT TEXT" in body
    assert "read-only context" in body


def test_audit_prompt_sections():
    prompt = audit_prompt([_change()], "our context files")
    assert "Our repository context" in prompt
    assert "RX8Defs" in prompt and "Recommended actions" in prompt
    assert "our context files" in prompt
