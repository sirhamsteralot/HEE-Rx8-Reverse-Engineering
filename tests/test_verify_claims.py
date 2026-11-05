"""verify_claims.py must PASS on the committed reports, label TSVs and
labels-pass records.

The checker machine-verifies the prose claim classes that hand-writing got
wrong in the C-item-7 pass (PR #30): batch call counts vs the disassembly,
peripheral register name<->address pairs vs symbols.tsv, literal-pool ranges
vs the classified non-instruction ranges + resolved call targets, and
labels-JSON <-> accepted TSV coverage. Run: python -m pytest tests/test_verify_claims.py
"""
import json
import os
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
SCRIPT = os.path.join(ROOT, "utilities", "scripts", "rx8-pcm-pipeline", "verify_claims.py")


def test_verify_claims_pass_on_committed_tree():
    r = subprocess.run([sys.executable, SCRIPT], capture_output=True, text=True, cwd=ROOT)
    out = json.loads(r.stdout)
    assert out["result"] == "PASS", out["failures"]
    assert r.returncode == 0
    assert out["checks"]["tsv_rows"] > 300
    assert out["checks"]["labels_json_checked"] > 0
