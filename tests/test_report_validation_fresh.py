#!/usr/bin/env python3
"""The committed report-validation stats must match a fresh validator run.

`utilities/scripts/rx8-pcm-pipeline/validate_reports.py` writes
`data/labels/<rom-id>/report_validation.json` on every run: per report, the
memory-map row counts, how many rows resolved against a tracked label, and the
declared/unnamed/grouped split. The file is a generated artifact (AGENTS.md rule
6d), so a report edit that adds or renames map rows has to ship the regenerated
stats with it - otherwise the committed numbers describe a report shape that no
longer exists and nothing notices.

This test re-runs the validator from the repo root and asserts the committed file
comes back unchanged. Run: python -m pytest tests/test_report_validation_fresh.py
"""
import json
import os
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
SCRIPT = os.path.join(ROOT, 'utilities', 'scripts', 'rx8-pcm-pipeline', 'validate_reports.py')
STATS = os.path.join(ROOT, 'data', 'labels', '60E15120_N3J1E', 'report_validation.json')


def _read():
    with open(STATS, encoding='utf-8') as f:
        return json.load(f)


def test_committed_stats_match_a_fresh_validator_run():
    before = _read()
    proc = subprocess.run([sys.executable, SCRIPT], cwd=ROOT,
                          capture_output=True, text=True)
    assert proc.returncode == 0, proc.stdout + proc.stderr
    after = _read()

    assert json.loads(proc.stdout)['result'] == 'PASS'

    drift = {k: (before['reports'].get(k), after['reports'].get(k))
             for k in set(before['reports']) | set(after['reports'])
             if before['reports'].get(k) != after['reports'].get(k)}
    assert not drift, (
        'data/labels/60E15120_N3J1E/report_validation.json is stale - the report '
        'shape changed without regenerating the stats. Re-run '
        'utilities/scripts/rx8-pcm-pipeline/validate_reports.py and commit the '
        'result. Drifted reports: %s' % json.dumps(drift, indent=2, sort_keys=True))

    assert before == after, 'report_validation.json differs outside the per-report stats'
