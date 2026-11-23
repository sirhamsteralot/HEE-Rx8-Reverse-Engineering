#!/usr/bin/env python3
"""The committed raw-ROM re-verification log must match a fresh verifier run.

`utilities/scripts/rx8-pcm-pipeline/verify_starting_cranking_chain.py` re-reads
every literal-pool word, instruction word, ROM float and table descriptor cited
by `docs/subsystem-logic/starting_cranking_report.md` and
`data/labels/60E15120_N3J1E/starting_cranking_labels.json`, and writes

  docs/investigations/60E15120_N3J1E/reviews/starting_cranking/rawbin_reverify_log.txt

The log is a committed artifact (AGENTS.md rule 6d), so a report or label edit
that changes a cited address has to ship the regenerated log — otherwise the
committed evidence describes numbers the ROM no longer backs.

Rewriting it after an intentional change:
  python utilities/scripts/rx8-pcm-pipeline/verify_starting_cranking_chain.py --write

Run: python -m pytest tests/test_starting_cranking_chain.py
"""
import os
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / 'utilities' / 'scripts' / 'rx8-pcm-pipeline' / 'verify_starting_cranking_chain.py'
LOG = (ROOT / 'docs' / 'investigations' / '60E15120_N3J1E' / 'reviews'
       / 'starting_cranking' / 'rawbin_reverify_log.txt')


def test_verifier_passes_and_log_is_current():
    before = LOG.read_text(encoding='utf-8')
    proc = subprocess.run([sys.executable, str(SCRIPT)], cwd=str(ROOT),
                          capture_output=True, text=True)
    assert proc.returncode == 0, proc.stdout + proc.stderr
    assert 'result PASS' in proc.stdout, proc.stdout
    after = LOG.read_text(encoding='utf-8')
    assert before == after, (
        'reviews/starting_cranking/rawbin_reverify_log.txt is stale — re-run '
        'utilities/scripts/rx8-pcm-pipeline/verify_starting_cranking_chain.py --write')


def test_log_covers_the_reports_cited_checks():
    text = LOG.read_text(encoding='utf-8')
    assert 'SHA-256 a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1' in text
    # every check line is marked ok and the totals add up
    lines = [ln for ln in text.splitlines() if ln.startswith(('ok ', 'FAIL'))]
    assert lines, 'log carries no check lines'
    assert not [ln for ln in lines if ln.startswith('FAIL')]
    assert f"({len(lines)}/{len(lines)} checks)" in text
