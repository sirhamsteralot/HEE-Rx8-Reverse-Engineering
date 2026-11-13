import sys
import uuid
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "apps" / "worker" / "src"))

import mistralai.workflows as workflows
import mistralai.workflows.testing as wftest
from worker.workflows.upstream_submodule_sync import (
    SubmoduleChange,
    SyncInput,
    SyncResult,
    UpstreamCheck,
    UpstreamSubmoduleSyncWorkflow,
)

TASK_QUEUE = "test-task-queue"


@pytest.fixture
def fake_activities():
    calls = []

    async def check_upstream(input: SyncInput) -> UpstreamCheck:
        calls.append("check")
        return UpstreamCheck(
            repo_dir="/tmp/hee-fake",
            changes=[
                SubmoduleChange(
                    name="RX8Defs",
                    path="submodules/RX8Defs",
                    pinned_sha="a" * 40,
                    latest_sha="b" * 40,
                    new_commit_count=2,
                )
            ],
            up_to_date=["submodules/Rx8Man"],
        )

    async def collect_our_context(check: UpstreamCheck) -> str:
        calls.append("collect")
        return "context"

    async def ai_audit(input: SyncInput, changes: list, our_context: str) -> str:
        calls.append("audit")
        assert our_context == "context"
        return "AUDIT REPORT"

    async def push_branch_and_open_pr(input: SyncInput, check: UpstreamCheck, changes: list, audit_report: str) -> SyncResult:
        calls.append("push")
        assert audit_report == "AUDIT REPORT"
        return SyncResult(
            changes=changes,
            audit_report=audit_report,
            branch_name="research/upstream-submodule-sync-x",
            pr_url="https://github.com/sirhamsteralot/HEE-Rx8-Reverse-Engineering/pull/999",
            pr_number=999,
        )

    async def cleanup_repo(check: UpstreamCheck) -> None:
        calls.append("cleanup")

    def wrap(name, fn):
        return workflows.activity(name=name, _skip_registering=True)(fn)

    return {
        "check_upstream": wrap("check_upstream", check_upstream),
        "collect_our_context": wrap("collect_our_context", collect_our_context),
        "ai_audit": wrap("ai_audit", ai_audit),
        "push_branch_and_open_pr": wrap("push_branch_and_open_pr", push_branch_and_open_pr),
        "cleanup_repo": wrap("cleanup_repo", cleanup_repo),
    }, calls, wrap


async def _run(temporal_env, input: SyncInput, activities):
    async with wftest.create_test_worker(
        temporal_env,
        workflows=[UpstreamSubmoduleSyncWorkflow],
        activities=list(activities.values()),
        task_queue=TASK_QUEUE,
    ):
        handle = await temporal_env.client.start_workflow(
            "upstream-submodule-sync",
            input,
            id=f"test-sync-{uuid.uuid4()}",
            task_queue=TASK_QUEUE,
        )
        return await handle.result()


async def test_workflow_runs_all_steps(temporal_env, fake_activities):
    activities, calls, _wrap = fake_activities
    result = SyncResult.model_validate(await _run(temporal_env, SyncInput(), activities))
    assert calls == ["check", "collect", "audit", "push", "cleanup"]
    assert result.pr_number == 999
    assert result.audit_report == "AUDIT REPORT"
    assert result.checked == ["submodules/Rx8Man"]
    assert result.changes[0].name == "RX8Defs"


async def test_workflow_no_changes_short_circuits(temporal_env, fake_activities):
    activities, calls, wrap = fake_activities

    async def no_changes(input: SyncInput) -> UpstreamCheck:
        calls.append("check")
        return UpstreamCheck(repo_dir="/tmp/hee-fake", up_to_date=["submodules/RX8Defs"])

    activities["check_upstream"] = wrap("check_upstream", no_changes)
    result = SyncResult.model_validate(await _run(temporal_env, SyncInput(), activities))
    assert calls == ["check", "cleanup"]
    assert result.changes == []
    assert result.pr_url == ""
