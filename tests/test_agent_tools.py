"""Test the agent-facing tool layer (utilities/scripts/hee.py -> mcp_server.call_tool)
and the MCP server protocol over stdio."""
import json
import os
import subprocess
import sys

REPO = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
HEE = os.path.join(REPO, "utilities", "scripts", "hee.py")
MCP = os.path.join(REPO, ".vibe", "plugins", "hee-re", "mcp_server.py")


def run_hee(tool, args):
    r = subprocess.run([sys.executable, HEE, tool, json.dumps(args)],
                       capture_output=True, text=True, timeout=120)
    assert r.returncode == 0, r.stderr
    return json.loads(r.stdout)


def test_hee_rom_list_and_info():
    lst = run_hee("hee_rom_list", {})
    assert "60E15120_N3J1E" in lst["profiles"]
    assert lst["own_dumps"]
    info = run_hee("hee_rom_info", {"path": "binaries/dumps/60E0G500_N3ZHEC.bin"})
    assert info["firmware_id_at_0x2000"] == "60E0G500"
    assert info["sha256"].startswith("a33f79a4")


def test_hee_boot_state_labels_disasm_diff():
    # sessions persist per process: drive boot+state through call_tool in-process
    sys.path.insert(0, os.path.join(REPO, ".vibe", "plugins", "hee-re"))
    import mcp_server
    boot = mcp_server.call_tool("hee_boot", {"profile": "60E15120_N3J1E", "cycles": 50000})
    assert boot["icount"] == 50000 and "cycle limit" in boot["stop"]
    st = mcp_server.call_tool("hee_state", {"profile": "60E15120_N3J1E"})
    assert st["heartbeats"] > 0
    lab = run_hee("hee_labels", {"rom_id": "60E15120_N3J1E", "query": "56b8a"})
    assert lab["matches"]
    d = run_hee("hee_disasm_rom", {"rom_id": "60E15120_N3J1E", "addr": "0x31c", "n": 4})
    assert any("tst" in l for l in d["lines"])
    diff = run_hee("hee_diff_roms", {
        "a": "binaries/dumps/60E0G500_N3ZHEC.bin",
        "b": "submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin"})
    assert diff["bytes_differing"] > 1000
    assert diff["ranges"]


def test_mcp_protocol_over_stdio():
    proc = subprocess.Popen([sys.executable, MCP], stdin=subprocess.PIPE,
                            stdout=subprocess.PIPE, text=True)
    def send(obj):
        proc.stdin.write(json.dumps(obj) + "\n")
        proc.stdin.flush()
    send({"jsonrpc": "2.0", "id": 1, "method": "initialize", "params": {}})
    resp = json.loads(proc.stdout.readline())
    assert resp["result"]["serverInfo"]["name"] == "hee-re"
    send({"jsonrpc": "2.0", "method": "notifications/initialized"})
    send({"jsonrpc": "2.0", "id": 2, "method": "tools/list"})
    resp = json.loads(proc.stdout.readline())
    names = [t["name"] for t in resp["result"]["tools"]]
    assert "hee_boot" in names and "hee_break" in names
    send({"jsonrpc": "2.0", "id": 3, "method": "tools/call",
          "params": {"name": "hee_manifest_check", "arguments": {}}})
    resp = json.loads(proc.stdout.readline())
    text = resp["result"]["content"][0]["text"]
    assert "manifest OK" in text
    proc.stdin.close()
    proc.terminate()
