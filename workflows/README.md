# HEE workflow worker

Mistral Workflows worker for the HEE RX-8 reverse-engineering repository.

## `upstream-submodule-sync`

Runs biweekly (see the schedule on the deployment). Per run it:

1. Clones the repo and inits the pinned submodules (`RX8Defs`, `Rx8Man`,
   `Mazda_RX8_PCM_ReverseEngineering`), then fetches each submodule's
   upstream default branch and compares it to the pinned gitlink.
2. If nothing moved, the run ends with the up-to-date list.
3. If a submodule moved, it collects the new commit log, diff stat and
   changed-file list (with diffs of XML/definition files) per submodule.
4. Runs an AI-assisted audit (Mistral chat) comparing the upstream changes
   against our own artifacts: `data/definitions`, `data/labels`,
   `data/maps`, `docs/investigations`, `docs/learnings.md`, `ROADMAP.md` —
   flagging conflicts, stale references and follow-up actions.
5. Updates the gitlinks on a `research/upstream-submodule-sync-*` branch,
   pushes it, and opens a draft PR with the audit report attached.

Submodules stay read-only context (AGENTS.md §4b): only gitlinks are updated.

### Inputs (`SyncInput`)

- `dry_run` (default `false`): check + audit only, no push / PR.
- `audit_model` (default `mistral-large-latest`): model for the audit pass.
- `repo_url`, `base_branch`, `branch_prefix`: defaults target this repo / `main`.

### Credentials

The unattended run needs a GitHub PAT with repo contents write + pull requests
write, bound from a Mistral workspace secret on the deployment as `HEE_GITHUB_TOKEN`
(or `hee_github_token`; both env var spellings are accepted). Reads of the
(public) submodules need no token.

## Local development

```sh
uv sync
uv run pytest tests/          # workflow + helper tests (in-memory Temporal)
```

Worker entrypoint: `apps/worker/src/worker/entrypoints/worker.py`.
Deployment image: `deploy/docker/Dockerfile.worker` (build context: this
`workflows/` directory).
