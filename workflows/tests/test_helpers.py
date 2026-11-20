import os
import shutil
import sys
from datetime import datetime, timezone
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "apps" / "worker" / "src"))

import worker.workflows.upstream_submodule_sync as us
from worker.workflows.upstream_submodule_sync import (
    SubmoduleChange,
    SyncInput,
    _content_to_text,
    ai_audit,
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


def test_content_to_text_skips_non_text_chunks():
    from mistralai.client.models import TextChunk, ThinkChunk

    think = ThinkChunk(
        type="thinking",
        thinking=[{"type": "text", "text": "internal reasoning"}],
        signature="sig",
        closed=True,
    )
    parts = [think, TextChunk(type="text", text="audit"), TextChunk(type="text", text=" report")]
    assert _content_to_text(parts) == "audit report"
    assert _content_to_text([think]) == ""
    assert _content_to_text("plain string") == "plain string"
    assert _content_to_text(None) == ""


async def test_ai_audit_joins_only_text_chunks(monkeypatch):
    import mistralai.client
    from mistralai.client.models import TextChunk, ThinkChunk

    think = ThinkChunk(
        type="thinking",
        thinking=[{"type": "text", "text": "internal reasoning"}],
        signature="sig",
        closed=True,
    )

    class _Message:
        content = [think, TextChunk(type="text", text="audit"), TextChunk(type="text", text=" report")]

    class _Choice:
        message = _Message()

    class _Response:
        choices = [_Choice()]

    class _Chat:
        def complete(self, **kwargs):
            return _Response()

    class _FakeMistral:
        def __init__(self, *args, **kwargs):
            self.chat = _Chat()

    monkeypatch.setattr(mistralai.client, "Mistral", _FakeMistral)

    report = await ai_audit(SyncInput(), [_change()], "our context")
    assert report == "audit report"


def test_ensure_repo_reuses_existing_clone(monkeypatch, tmp_path):
    repo = tmp_path / "hee-sync-existing"
    (repo / ".git").mkdir(parents=True)
    commands = []
    monkeypatch.setattr(us, "_run", lambda cmd, cwd=None: commands.append(cmd) or "")
    assert us._ensure_repo(SyncInput(), str(repo)) == str(repo)
    assert commands == []


def test_ensure_repo_reclones_when_clone_is_gone(monkeypatch, tmp_path):
    commands = []

    def fake_run(cmd, cwd=None):
        commands.append((cmd, cwd))
        return ""

    monkeypatch.setattr(us, "_run", fake_run)
    repo = tmp_path / "hee-sync-gone"
    input = SyncInput(repo_url="https://github.com/o/r.git", base_branch="dev")
    out = us._ensure_repo(input, str(repo))
    assert out == str(repo)
    assert commands[0] == (
        ["git", "clone", "--quiet", "--branch", "dev", "https://github.com/o/r.git", str(repo)],
        None,
    )
    assert commands[1] == (["git", "submodule", "update", "--init", "--quiet"], str(repo))


def test_ensure_repo_creates_fresh_dir_when_repo_dir_unset(monkeypatch, tmp_path):
    commands = []
    monkeypatch.setattr(us, "_run", lambda cmd, cwd=None: commands.append(cmd) or "")
    monkeypatch.setattr(us.tempfile, "mkdtemp", lambda prefix: str(tmp_path / "hee-sync-fresh"))
    out = us._ensure_repo(SyncInput(repo_url="https://github.com/o/r.git"), "")
    assert out == str(tmp_path / "hee-sync-fresh")
    assert commands[0][:4] == ["git", "clone", "--quiet", "--branch"]
    shutil.rmtree(out, ignore_errors=True)


def test_run_rejects_missing_cwd(tmp_path):
    with pytest.raises(RuntimeError, match="does not exist"):
        us._run(["git", "status"], cwd=str(tmp_path / "missing"))
