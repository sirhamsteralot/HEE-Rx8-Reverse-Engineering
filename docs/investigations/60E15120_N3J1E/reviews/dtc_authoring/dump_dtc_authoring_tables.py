#!/usr/bin/env python3
"""Re-runnable evidence dump for the DTC-authoring report (60E15120_N3J1E).

Reads the raw ROM (submodule, pinned commit) and prints the DTC table region,
the UDS service dispatch table, literal-pool references to the DTC tables,
and the stock enable/type/mask bytes for every slot. Run from the repo root:

    python docs/investigations/60E15120_N3J1E/reviews/dtc_authoring/dump_dtc_authoring_tables.py

Output is recorded in tables_dump.txt next to this script.
"""
import hashlib
import struct

ROM = "submodules/Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin"

rom = open(ROM, "rb").read()
print(f"rom {ROM} len {hex(len(rom))} sha256 {hashlib.sha256(rom).hexdigest()}")


def u16(a):
    return struct.unpack(">H", rom[a:a + 2])[0]


def u32(a):
    return struct.unpack(">I", rom[a:a + 4])[0]


ID2SLOT = 0x7DF42
CODE = 0x7E560
PREFIX = 0x7E55A
TYPE = 0x7E32A
EN1, EN2, EN3 = 0x7E678, 0x7E704, 0x7E790
CONF = 0x7E81C
STATUS = 0x7E934
MONSRC = 0x7E29E
RELATED = 0x7E06C
SVC = 0x5EB40

print("\n== arg -> slot map (0x7df42, BE u16 per arg 0x00..0x8b) ==")
id2slot = {i: u16(ID2SLOT + 2 * i) for i in range(0x8C)}
shared = {a: s for a, s in id2slot.items() if sum(1 for v in id2slot.values() if v == s) > 1}
print(f"args 0x00..0x8b; slots reached: {min(id2slot.values()):#x}..{max(id2slot.values()):#x}")
print(f"args sharing a slot (many-to-one) from arg {min(shared):#x} on; "
      f"e.g. 0x7b/0x7c/0x7d -> {[hex(id2slot[i]) for i in (0x7B, 0x7C, 0x7D)]}")
print(f"entries at 0x7e05a (arg 0x8c..): {[hex(u16(0x7E05A + 2 * i)) for i in range(9)]}")

print("\n== code table (0x7e560, BE u16 per slot 0..0x8b) ==")
codes = {s: u16(CODE + 2 * s) for s in range(140)}
free = [s for s, c in codes.items() if c == 0xFFFF]
real_disabled = [s for s in range(140) if rom[EN1 + s] == 0 and rom[EN2 + s] == 0 and codes[s] != 0xFFFF]
print(f"prefix codes 0x7e55a: {[hex(u16(PREFIX + 2 * i)) for i in range(3)]}")
print(f"slots with code 0xffff (free): {[hex(s) for s in free]} ({len(free)} slots)")
print(f"slots with a real code but stock enable#1=#2=0: "
      f"{[(hex(s), hex(codes[s])) for s in real_disabled]}")
for s in (id2slot[0x7B], id2slot[0x7C], id2slot[0x7D]):
    print(f"arg 0x7b/0x7c/0x7d chain: slot {hex(s)} -> code {hex(codes[s])}")

print("\n== per-slot config bytes (stock) ==")
print("nonzero type bytes:", {hex(s): rom[TYPE + s] for s in range(140) if rom[TYPE + s]})
for s in (0x71, 0x72, 0x73, 0x79, 0x8B):
    print(f"slot {s:#04x}: code {codes[s]:#06x} e1={rom[EN1+s]:#04x} e2={rom[EN2+s]:#04x} "
          f"e3={rom[EN3+s]:#04x} type={rom[TYPE+s]:#04x} conf={u16(CONF+2*s):#06x} "
          f"status={u32(STATUS+4*s):#010x} monsrc={rom[MONSRC+s]:#04x} rel={u32(RELATED+4*s):#010x}")

print("\n== UDS service dispatch table (0x5eb40, 29 x 12-byte records) ==")
svcs = []
for i in range(29):
    a = SVC + 12 * i
    svcs.append(rom[a])
    print(f"  {hex(a)}: svc {rom[a]:#04x} handler {u32(a+4):#010x} param {u32(a+8):#010x}")
print(f"service 0x19 present: {0x19 in svcs}; service 0x1a present: {0x1A in svcs}")

print("\n== literal-pool references to the DTC tables (mov.l pool words in ROM) ==")
targets = {ID2SLOT: "id2slot", CODE: "code_table", TYPE: "type", EN1: "enable1", EN2: "enable2",
           EN3: "enable3", CONF: "conf_mask", STATUS: "status_mask", MONSRC: "monitor_mask",
           PREFIX: "prefix", RELATED: "related", 0x7E05A: "tail_0x7e05a"}
for a in range(0, len(rom) - 4, 2):
    v = u32(a)
    if v in targets:
        print(f"  pool word {hex(a)} = {hex(v)} ({targets[v]})")
