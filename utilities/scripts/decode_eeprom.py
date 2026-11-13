#!/usr/bin/env python3
"""Decode a 93C56 (IC420) EEPROM dump (256 B) into its mapped contents.

The content map comes from
docs/investigations/60E15120_N3J1E/eeprom_content_map_report.md: the chip is
read by the PCM over SCI4 as 128 big-endian u16 words (device frame
0x6000000 + word*0x10000), so dump byte i is the high byte of word i/2 for
even i.

Usage:
    python utilities/scripts/decode_eeprom.py <dump.bin> [--json]
    python utilities/scripts/decode_eeprom.py <dump.bin> --compare <other.bin>

Prints the decoded regions (immobilizer key/code, param block, learned
correction table with values, ECU ID string, VIN, tire data, config bits,
erased ranges, tail), plus warnings where the content deviates from the
mapped expectations (marker words, erased ranges). --json emits the decoded
structure for scripting; --compare lists the offsets where two dumps differ.
Exit code 0 on success, 2 on bad input (wrong size, unreadable file).
"""
import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path

SIZE = 256
MARKER_WORD0 = 0x5AFF          # dump byte 0-1 in both known dumps
TAIL_MARKER = 0x30             # dump byte 0xff in both known dumps
TIRE_MARKER = 0x2A             # '*' at 0x95 -> default tire size
LEARNED_OFF = 0x20             # learned table: 34 x (u8 value, u8 flag)
LEARNED_PAIRS = 0x22
LEARNED_UNITS_PER_COUNT = 0.5  # value = -63.0 + raw * 0.5 (ROM pools 0x27c80/0x27c84)
LEARNED_OFFSET = -63.0
VIN_OFF = 0x80                 # 17 ASCII chars
VIN_LEN = 17


def u16be(data, off):
    return struct.unpack(">H", data[off:off + 2])[0]


def erased(data, off, length):
    return all(b == 0xFF for b in data[off:off + length])


def printable(data, off, length):
    chunk = data[off:off + length]
    return all(32 <= b < 127 for b in chunk), chunk


def decode(data: bytes) -> dict:
    """Decode a 256-byte 93C56 image into a structured dict."""
    if len(data) != SIZE:
        raise ValueError("expected %d bytes, got %d" % (SIZE, len(data)))
    out = {"size": SIZE, "sha256": hashlib.sha256(data).hexdigest(), "warnings": []}
    w = out["warnings"]

    marker = u16be(data, 0x00)
    out["marker_word0"] = {"offset": "0x00-0x01", "value": "0x%04x" % marker,
                           "expected": "0x%04x" % MARKER_WORD0}
    if marker != MARKER_WORD0:
        w.append("word0 is 0x%04x, expected 0x%04x" % (marker, MARKER_WORD0))

    key = data[0x02:0x0A]
    out["immobilizer_secret_key"] = {
        "offset": "0x02-0x09", "hex": key.hex(" "),
        "erased": erased(data, 0x02, 8)}
    if out["immobilizer_secret_key"]["erased"]:
        w.append("immobilizer key area is erased (0xff)")

    status = u16be(data, 0x0A)
    out["immobilizer_status_word"] = {"offset": "0x0a-0x0b", "value": "0x%04x" % status}

    out["config_param_bytes"] = {"offset": "0x0c-0x15", "hex": data[0x0C:0x16].hex(" ")}

    code = data[0x16:0x1A]
    out["immobilizer_code_id"] = {
        "offset": "0x16-0x19", "hex": code.hex(" "),
        "u16": ["0x%04x" % u16be(data, 0x16), "0x%04x" % u16be(data, 0x18)],
        "erased": erased(data, 0x16, 4)}

    out["param_block_tail"] = {"offset": "0x1a-0x1f", "hex": data[0x1A:0x20].hex(" ")}

    table = []
    for i in range(LEARNED_PAIRS):
        off = LEARNED_OFF + 2 * i
        raw, flag = data[off], data[off + 1]
        entry = {"index": i, "offset": "0x%02x" % off, "raw": "0x%02x" % raw,
                 "flag": 0 if flag == 0xFF else flag, "flag_raw": "0x%02x" % flag}
        if raw == 0xFF:
            entry["erased"] = True
        else:
            entry["value"] = LEARNED_OFFSET + raw * LEARNED_UNITS_PER_COUNT
        table.append(entry)
    out["learned_correction_table"] = {
        "offset": "0x20-0x63", "entries": table,
        "decode": "value = %.1f + raw * %.1f" % (LEARNED_OFFSET, LEARNED_UNITS_PER_COUNT)}

    id_offs = [0x64, 0x65, 0x66, 0x68, 0x6A, 0x6B, 0x6C]
    id_chars = bytes(data[o] for o in id_offs)
    ok, _ = printable(data, 0x64, 0x0A)
    out["ecu_id_string"] = {
        "offset": "0x64-0x6d (chars at 0x64-0x66, 0x68, 0x6a-0x6b, 0x6c)",
        "hex": data[0x64:0x6E].hex(" "),
        "string": id_chars.decode("ascii", "replace") if all(32 <= b < 127 for b in id_chars) else None}

    out["field_6e"] = {"offset": "0x6e-0x76", "hex": data[0x6E:0x77].hex(" "),
                       "erased": erased(data, 0x6E, 9)}
    out["field_78"] = {"offset": "0x78-0x79", "u16": "0x%04x" % u16be(data, 0x78)}
    out["field_7a"] = {"offset": "0x7a-0x7b", "u16": "0x%04x" % u16be(data, 0x7A)}

    ok, vin_raw = printable(data, VIN_OFF, VIN_LEN)
    out["vin"] = {"offset": "0x80-0x90", "hex": vin_raw.hex(" "),
                  "value": vin_raw.decode("ascii") if ok else None}
    if not ok:
        w.append("VIN field 0x80-0x90 is not printable ASCII")

    marker95 = data[0x95]
    out["tire_size_marker"] = {
        "offset": "0x95", "value": "0x%02x" % marker95,
        "meaning": "'*' -> default tire size" if marker95 == TIRE_MARKER else "non-default (custom tire size set)"}
    if marker95 != TIRE_MARKER:
        w.append("tire marker 0x95 is 0x%02x, expected '*' (0x2a)" % marker95)

    revs = u16be(data, 0x9A)
    out["tire_revolutions_per_mile"] = {"offset": "0x9a-0x9b", "u16": revs}

    cfg = data[0x9F]
    out["config_bits_9f"] = {"offset": "0x9f", "value": "0x%02x" % cfg, "bit0": cfg & 1}

    out["reserve_a0_fb"] = {"offset": "0xa0-0xfb", "erased": erased(data, 0xA0, 0x5C)}
    if not out["reserve_a0_fb"]["erased"]:
        nonff = ["0x%02x" % (0xA0 + i) for i in range(0x5C) if data[0xA0 + i] != 0xFF]
        w.append("0xa0-0xfb expected erased, non-ff at: %s" % ", ".join(nonff))

    out["tail"] = {"offset": "0xfc-0xff",
                   "u16_fc_fd": "0x%04x" % u16be(data, 0xFC),
                   "byte_fe": "0x%02x" % data[0xFE],
                   "marker_ff": "0x%02x" % data[0xFF]}
    if data[0xFF] != TAIL_MARKER:
        w.append("tail byte 0xff is 0x%02x, expected 0x30" % data[0xFF])

    return out


def render_text(dec: dict) -> str:
    lines = []
    add = lines.append
    add("93C56 EEPROM decode — %d bytes, SHA-256 %s" % (dec["size"], dec["sha256"]))
    add("")
    add("marker word0 (0x00-0x01): %s (expected %s)" % (
        dec["marker_word0"]["value"], dec["marker_word0"]["expected"]))
    k = dec["immobilizer_secret_key"]
    add("immobilizer secret key (0x02-0x09): %s%s" % (k["hex"], " [ERASED]" if k["erased"] else ""))
    add("immobilizer status word (0x0a-0x0b): %s" % dec["immobilizer_status_word"]["value"])
    add("config/param bytes (0x0c-0x15): %s" % dec["config_param_bytes"]["hex"])
    c = dec["immobilizer_code_id"]
    add("immobilizer code/ID (0x16-0x19): %s  u16 %s%s" % (
        c["hex"], " ".join(c["u16"]), " [ERASED]" if c["erased"] else ""))
    add("param block tail (0x1a-0x1f): %s" % dec["param_block_tail"]["hex"])
    add("")
    add("learned correction table (0x20-0x63), %s:" % dec["learned_correction_table"]["decode"])
    for e in dec["learned_correction_table"]["entries"]:
        if e.get("erased"):
            add("  #%02d @%s: raw=%s flag=%d [erased]" % (e["index"], e["offset"], e["raw"], e["flag"]))
        else:
            add("  #%02d @%s: raw=%s -> value %+7.1f  flag=%d" % (
                e["index"], e["offset"], e["raw"], e["value"], e["flag"]))
    add("")
    ident = dec["ecu_id_string"]
    add("ECU ID string (0x64-0x6d): %s  %s" % (
        ident["hex"], repr(ident["string"]) if ident["string"] is not None else "(non-ASCII)"))
    add("field 0x6e-0x76 (9 B): %s%s" % (dec["field_6e"]["hex"], " [erased]" if dec["field_6e"]["erased"] else ""))
    add("field 0x78-0x79: %s   field 0x7a-0x7b: %s" % (dec["field_78"]["u16"], dec["field_7a"]["u16"]))
    vin = dec["vin"]
    add("VIN (0x80-0x90): %s" % (vin["value"] if vin["value"] is not None else vin["hex"] + " (non-ASCII)"))
    add("tire size marker (0x95): 0x%02x — %s" % (int(dec["tire_size_marker"]["value"], 16), dec["tire_size_marker"]["meaning"]))
    add("tire revolutions per mile (0x9a-0x9b): %d" % dec["tire_revolutions_per_mile"]["u16"])
    add("config bits (0x9f): %s (bit0=%d)" % (dec["config_bits_9f"]["value"], dec["config_bits_9f"]["bit0"]))
    add("reserve 0xa0-0xfb: %s" % ("erased" if dec["reserve_a0_fb"]["erased"] else "HAS DATA"))
    add("tail (0xfc-0xff): u16=%s byte_fe=%s marker_ff=%s" % (
        dec["tail"]["u16_fc_fd"], dec["tail"]["byte_fe"], dec["tail"]["marker_ff"]))
    if dec["warnings"]:
        add("")
        add("warnings:")
        for warn in dec["warnings"]:
            add("  - %s" % warn)
    return "\n".join(lines)


def compare(a: bytes, b: bytes):
    if len(a) != SIZE or len(b) != SIZE:
        raise ValueError("both dumps must be %d bytes" % SIZE)
    return ["0x%02x" % i for i in range(SIZE) if a[i] != b[i]]


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description="Decode a 93C56 (IC420) 256-byte EEPROM dump.")
    ap.add_argument("dump", help="path to the 256-byte EEPROM dump (.bin)")
    ap.add_argument("--json", action="store_true", help="emit the decoded structure as JSON")
    ap.add_argument("--compare", metavar="OTHER", help="also list offsets differing from OTHER")
    args = ap.parse_args(argv)

    path = Path(args.dump)
    try:
        data = path.read_bytes()
    except OSError as e:
        print("error: cannot read %s: %s" % (path, e), file=sys.stderr)
        return 2
    try:
        dec = decode(data)
    except ValueError as e:
        print("error: %s: %s" % (path, e), file=sys.stderr)
        return 2

    if args.json:
        out = dict(dec)
        if args.compare:
            other = Path(args.compare).read_bytes()
            out["diff_vs"] = {"file": str(args.compare), "diff_offsets": compare(data, other)}
        print(json.dumps(out, indent=2))
    else:
        print(render_text(dec))
        if args.compare:
            try:
                other = Path(args.compare).read_bytes()
            except OSError as e:
                print("error: cannot read %s: %s" % (args.compare, e), file=sys.stderr)
                return 2
            try:
                diffs = compare(data, other)
            except ValueError as e:
                print("error: %s" % e, file=sys.stderr)
                return 2
            print("")
            print("diff vs %s: %d offsets differ: %s" % (args.compare, len(diffs), ", ".join(diffs)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
