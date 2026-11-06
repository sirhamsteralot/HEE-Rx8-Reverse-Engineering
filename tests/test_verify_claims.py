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


def _load_verify_claims_module():
    import importlib.util
    sys.path.insert(0, os.path.dirname(SCRIPT))
    spec = importlib.util.spec_from_file_location("verify_claims_under_test", SCRIPT)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


def test_new_claim_classes_catch_known_transcription_errors():
    """Negative tests: the claim classes added after the claims-verification
    pass must flag the exact hand-transcription errors that pass found
    (pool words cited one word off, wrong DLC, wrong callee count, quoted
    byte string offset by one word) and must accept the corrected claims."""
    vc = _load_verify_claims_module()
    assert vc.failures == [], vc.failures  # committed tree passes all classes

    # class 5: 0x216f8 pool words cited one word off (0x21744 holds 0x2068)
    vc.scan_line("test", "pool 0x21740-0x2175c words 0x21744=0x6a218, 0x21748=0x6a240", fn_hint="000216f8")
    assert len(vc.failures) == 2, vc.failures
    # class 5: cooling-fan pool words shifted (0x2f240 holds 0xe0, not 0xf754)
    vc.scan_line("test", "pool words of 0x2f1dc (0x2f240=0xf754, 0x2f242=0x800, 0x2f246=0x10)", fn_hint="0002f1dc")
    assert len(vc.failures) == 5, vc.failures
    # class 5: alternator float at the wrong word (100.0f is at 0x25780)
    vc.scan_line("test", "pool 0x2578c = 0xffff9f44, 0x25788 = f32 100.0", fn_hint="00025710")
    assert len(vc.failures) == 6, vc.failures
    # class 6: callee count (batch resolves 13 signal callees, not 12)
    vc.scan_line("test", "`ref_updateDSCRelatedCANStuff__` 0x2a2ae confirmed: its 12 callees", fn_hint="0002a2ae")
    assert len(vc.failures) == 7, vc.failures
    # class 7 + 8: quoted byte string offset by one word and wrong DLC 8
    bad = ("mailbox descriptor at ROM 0x4e21c: bytes 00000000 00000212 01210700 ffffbbc0 01000000 "
           "= ID 0x212, DLC 8, buffer 0xffffbbc0")
    vc.scan_text("test", bad)
    vc.scan_line("test", bad)
    assert len(vc.failures) == 9, vc.failures

    # positive controls: the corrected claims must not add failures
    vc.scan_line("test", "pool words 0x21744=0x2068, 0x21748=0x6a218", fn_hint="000216f8")
    vc.scan_line("test", "its 13 callees all process", fn_hint="0002a2ae")
    good = ("mailbox descriptor at ROM 0x4e21c: bytes 00000212 01210700 ffffbbc0 01000000 "
            "= ID 0x212, ctrl 0x07 = DLC 7, buffer 0xffffbbc0")
    vc.scan_text("test", good)
    vc.scan_line("test", "at ROM 0x4e21c: record (ID 0x212, ctrl 0x07 = DLC 7, buffer 0xffffbbc0)")
    assert len(vc.failures) == 9, vc.failures
