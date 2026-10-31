#!/usr/bin/env python3
"""Direct agent-facing CLI for the HEE RE tooling — no MCP needed when the agent
has local repo access (e.g. inside Vibe via run_typescript/bash).

    python utilities/scripts/hee.py <tool> '<json args>'
    python utilities/scripts/hee.py --list

Same tool set as the heeRe MCP plugin (.vibe/plugins/hee-re/mcp_server.py), which
reuses this module's call_tool — one source of truth. Sessions are per-process, so
for multi-step debugging use the interactive debug.py / ui.py instead.

Examples:
    python utilities/scripts/hee.py hee_rom_list '{}'
    python utilities/scripts/hee.py hee_rom_info '{"path": "binaries/dumps/aron-N3ZHEC-2026-10-31.bin"}'
    python utilities/scripts/hee.py hee_boot '{"profile": "60E15120_N3J1E", "cycles": 200000}'
    python utilities/scripts/hee.py hee_disasm_rom '{"rom_id": "60E15120_N3J1E", "addr": "0x31c", "n": 6}'
    python utilities/scripts/hee.py hee_labels '{"rom_id": "60E15120_N3J1E", "query": "engine_load"}'
    python utilities/scripts/hee.py hee_diff_roms '{"a": "binaries/dumps/aron-N3ZHEC-2026-10-31.bin", "b": "binaries/dumps/aron-N3ZHEC-streetportv1_24_approx_5500max-2026-10-31.bin"}'
"""
import json
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", ".vibe", "plugins", "hee-re"))

from mcp_server import TOOLS, call_tool  # noqa: E402


def main(argv=None):
    argv = argv if argv is not None else sys.argv[1:]
    if not argv or argv[0] in ("--list", "-l"):
        for t in TOOLS:
            print(f"{t['name']:20s} {t['description']}")
        return 0
    name = argv[0]
    args = json.loads(argv[1]) if len(argv) > 1 else {}
    result = call_tool(name, args)
    print(json.dumps(result, indent=2, default=str))
    return 0


if __name__ == "__main__":
    sys.exit(main())
