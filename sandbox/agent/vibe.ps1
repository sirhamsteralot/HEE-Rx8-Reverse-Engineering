<#
.SYNOPSIS
Runs Vibe inside the agent box instead of on the host.

.DESCRIPTION
Starts the allowlisting egress proxy, then runs the `agent` service with the
`vibe` CLI. Arguments are passed through unchanged, so everything the bash
wrapper accepts works here as well:

  .\vibe.ps1                              interactive session in /work/repo
  .\vibe.ps1 "add a test for X"           session with an initial prompt
  .\vibe.ps1 -p "list the files"          headless, one answer, exit
  .\vibe.ps1 -- "anything"                everything after -- is passed to vibe

The box has no host home, no SSH keys, no docker socket and no network route
except the allowlisting proxy (see README.md), so a session started this way
cannot touch the host beyond the read-only /src mount.

The exit code of `docker compose run` becomes the exit code of this script.

.EXAMPLE
.\vibe.ps1

.EXAMPLE
.\vibe.ps1 --resume

.EXAMPLE
.\vibe.ps1 -p "list the ROM profiles"

.NOTES
PowerShell port of vibe.sh; both wrappers drive the same compose file and the
same container. Windows PowerShell 5.1 and PowerShell 7 are supported.
#>

# Exit codes are checked explicitly after every native call instead of relying
# on $ErrorActionPreference, which behaves differently for stderr on 5.1.
$ErrorActionPreference = 'Continue'

# `docker compose` takes the project directory from the compose file, so the
# script works from any working directory and still picks up sandbox/agent/.env.
$composeFile = Join-Path -Path $PSScriptRoot -ChildPath 'compose.yaml'

if (-not (Get-Command docker -CommandType Application -ErrorAction SilentlyContinue)) {
    $host.UI.WriteErrorLine('vibe.ps1: docker was not found on PATH - install Docker Desktop (or the docker CLI) and retry.')
    exit 127
}

# Nothing is declared as a script parameter, so $args holds exactly what the
# caller wrote: -p, --resume, "--" and quoted prompts all reach vibe verbatim.
$vibeArgs = @($args)

# Keep the egress proxy (the only route out) up for the session.
docker compose -f $composeFile up -d egress | Out-Null
if ($LASTEXITCODE -ne 0) {
    $host.UI.WriteErrorLine("vibe.ps1: 'docker compose up -d egress' failed (exit $LASTEXITCODE)")
    exit $LASTEXITCODE
}

docker compose -f $composeFile run --rm agent vibe @vibeArgs
exit $LASTEXITCODE
