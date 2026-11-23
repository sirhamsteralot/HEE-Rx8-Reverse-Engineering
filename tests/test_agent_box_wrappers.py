"""Test the agent-box launch wrappers (sandbox/agent/vibe.sh, sandbox/agent/vibe.ps1).

Both wrappers drive the same compose file: start the allowlisting egress proxy,
then run the `agent` service with the `vibe` CLI, forwarding the caller's
arguments and returning the container's exit code. The forwarding test runs only
where a PowerShell host is on PATH (Windows PowerShell 5.1 or PowerShell 7);
it uses a stub `docker` so it needs no Docker daemon and no built image.
"""
import os
import shutil
import subprocess

import pytest

REPO = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
AGENT_DIR = os.path.join(REPO, "sandbox", "agent")
VIBE_SH = os.path.join(AGENT_DIR, "vibe.sh")
VIBE_PS1 = os.path.join(AGENT_DIR, "vibe.ps1")
COMPOSE_FILE = os.path.join(AGENT_DIR, "compose.yaml")

POWERSHELL = shutil.which("powershell") or shutil.which("pwsh")

# Stub `docker`: logs every argument on its own line to STUB_LOG (the wrapper
# silences the proxy call, so stdout alone would only show the run), then exits 0
# for a `... up ...` call and STUB_EXIT for anything else - which tells the two
# compose calls apart and makes the exit code observable.
STUB_DOCKER_CMD = """@echo off
setlocal enableextensions
set is_up=0
>>"%STUB_LOG%" echo === call
:loop
if "%~1"=="" goto end
>>"%STUB_LOG%" echo %~1
if "%~1"=="up" set is_up=1
shift
goto loop
:end
if "%is_up%"=="1" exit /b 0
if "%STUB_EXIT%"=="" exit /b 0
exit /b %STUB_EXIT%
"""


def read_text(path):
    with open(path, encoding="utf-8") as fh:
        return fh.read()


def test_wrappers_drive_the_same_compose_service():
    """Neither wrapper may drift from the compose file's service names."""
    with open(COMPOSE_FILE, encoding="utf-8") as fh:
        compose = fh.read()
    assert "  egress:" in compose and "  agent:" in compose
    for path in (VIBE_SH, VIBE_PS1):
        text = read_text(path)
        assert "up -d egress" in text, path
        assert "run --rm agent vibe" in text, path


@pytest.mark.skipif(POWERSHELL is None, reason="no PowerShell host on PATH")
def test_vibe_ps1_forwards_arguments_and_exit_code(tmp_path):
    stub_dir = tmp_path / "bin"
    stub_dir.mkdir()
    (stub_dir / "docker.cmd").write_text(STUB_DOCKER_CMD, encoding="ascii", newline="\r\n")

    log = tmp_path / "docker-calls.log"
    env = dict(os.environ)
    env["PATH"] = str(stub_dir) + os.pathsep + env["PATH"]
    env["STUB_LOG"] = str(log)
    env["STUB_EXIT"] = "3"

    r = subprocess.run(
        [POWERSHELL, "-NoProfile", "-ExecutionPolicy", "Bypass", "-File", VIBE_PS1,
         "-p", "two words"],
        capture_output=True, text=True, timeout=120, env=env,
    )
    assert r.returncode == 3, r.stderr

    # One logged block per compose invocation: proxy start, then the run.
    calls, current = [], []
    for line in (l.strip() for l in log.read_text(encoding="ascii").splitlines()):
        if line == "=== call":
            if current:
                calls.append(current)
            current = []
        elif line:
            current.append(line)
    if current:
        calls.append(current)
    assert len(calls) == 2, calls

    up, run = calls
    assert up[1:3] == ["-f", COMPOSE_FILE], up
    assert "up" in up and "-d" in up and "egress" in up, up
    # A quoted prompt stays one argument; flags reach vibe verbatim.
    assert run[1:3] == ["-f", COMPOSE_FILE], run
    assert run[3:] == ["run", "--rm", "agent", "vibe", "-p", "two words"], run
