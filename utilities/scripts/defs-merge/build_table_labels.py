#!/usr/bin/env python3
"""Build data/labels/60E15120_N3J1E/defs_table_labels.json — the curated
descriptor -> editor-label map used by the defs relabel pass (relabel.py).

Sources, in priority order (later overrides earlier on the same descriptor):
  1. lookup_aliases in data/labels/60E15120_N3J1E/{knock_loop,ignition_timing,
     fueling}_labels.json (machine-readable labeling passes, 2026-10-29/31)
  2. REPORT_ENTRIES below — hand-transcribed from the subsystem reports
     (knock_control_report.md §8.4, ignition_timing_report.md §3,
     fueling_control_report.md §7.3/§10.7, load_fueling_report.md §4) with
     per-entry citations. Every entry is keyed by the lookup DESCRIPTOR
     address (the tbl_XXXXXXXX name in data/maps/<rom>/index.tsv).

Each entry: {name, category, note, desc, evidence, source, confidence}.
  name       RomRaider table name to use (" (candidate)" suffix marks unproven)
  category   RomRaider category = the grouping (existing RX8Defs category names)
  note       detailed semantics/provenance note — NOT editor-facing (stays here)
  desc       short editor-facing <description> text (AGENTS.md rule 6b): a
             simplified description of what the table does, only when accurately
             known; no addresses, no structural-match/derivation details
  confidence "high" = binary-verified role; "candidate" = hypothesis (label ladder)

The output also carries a "scalar_entries" section: provenance for the
literal-pool float32 "Scalar - ..." 1-cell entries that
extend_defs_all_roms.inject_scalar_tables adds to every per-ROM def (editor
name/units/description from extend_defs_all_roms.SCALAR_ENTRIES; value/bits/
evidence/per-ROM addresses from data/maps/cross_rom_scalars.json).

Run from the repo root:
  python utilities/scripts/defs-merge/build_table_labels.py
"""
from pathlib import Path
import json, re

ROOT = Path(__file__).resolve().parents[3]
LABELS = ROOT / "data" / "labels" / "60E15120_N3J1E"
OUT = LABELS / "defs_table_labels.json"

REPORT = "docs/investigations/60E15120_N3J1E"

# ---------------------------------------------------------------------------
# Curated entries transcribed from the investigation reports (citations in
# `source`). Descriptor addresses are the tbl_XXXXXXXX keys of
# data/maps/60E15120_N3J1E/index.tsv.
# ---------------------------------------------------------------------------
REPORT_ENTRIES = {
    # ---- Knock control (knock_control_report.md §8.4; knock_loop_labels.json)
    "0x6af54": dict(name="Knock Enable Load Floor (RPM)", category="Knock Control",
        note="12 cells, 0.5 flat; axis 0x795e8 (RPM 800-9600); gates knock enable 0xffffa73d (0x13826).",
        source=f"{REPORT}/knock_control_report.md §8.4; knock_loop_labels.json"),
    "0x6af68": dict(name="Knock Retard Clamp Min (RPM)", category="Knock Control",
        note="u8 cells x mult + offset(-64): -10..0 deg; axis 0x79624 (RPM 2000-5000); clamped by 0x13bd2 = [-10,0] deg (bug fixed 2026-10-29).",
        source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6af7c": dict(name="Knock Retard Clamp Min Alt (RPM)", category="Knock Control",
        note="alt min: -10/-7.5/-5x4/0; axis 0x79648.", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6af90": dict(name="Knock Retard Clamp Max (RPM)", category="Knock Control",
        note="0.0 deg x15; axis 0x7966c (RPM 800-6400).", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6afa4": dict(name="Knock Recovery Target (RPM)", category="Knock Control",
        note="fail-safe target -10..0 deg; axis 0x796b8 (RPM 500-5500); written to 0xffffa744.",
        source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6afb8": dict(name="Knock Learned Retard Scale", category="Knock Control",
        note="0.0 x13; axis 0x79704 = learned retard -8.4..+8.4 deg.", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6b250": dict(name="Knock Voltage To Magnitude Scale", category="Knock Control",
        note="knock voltage -> magnitude scale.", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6b264": dict(name="Knock Transient Hold (cycles)", category="Knock Control",
        note="raw u8 0x0a -> <<1 = 20-cycle hold (0xffffc0ac).", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6b270": dict(name="Knock Ignition Threshold A (RPM)", category="Knock Control",
        note="raw u16 vs RPM (normal) -> 0xffffc090 -> 0xffffa37e; default 94 (0xc1f8).",
        source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6b27c": dict(name="Knock Ignition Threshold A Alt (RPM)", category="Knock Control",
        note="raw u16 vs RPM (alt) -> 0xffffc090 -> 0xffffa37e.", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6b288": dict(name="Knock Ignition Threshold B (RPM)", category="Knock Control",
        note="raw u16 vs RPM (normal) -> 0xffffc092 -> 0xffffa37c; default 193.", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6b294": dict(name="Knock Ignition Threshold B Alt (RPM)", category="Knock Control",
        note="raw u16 vs RPM (alt) -> 0xffffc092 -> 0xffffa37c.", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6b2a0": dict(name="Knock Noise Threshold Min", category="Knock Control",
        note="clamp floor for 0xffffa350[2].", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6b2ac": dict(name="Knock Noise Floor (RPM)", category="Knock Control",
        note="lookup vs raw RPM -> 0xffffa358.", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6b2b8": dict(name="Knock Level 3D A (load x RPM)", category="Knock Control",
        note="3D knock level vs load/RPM (20x12 scaled).", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6b2d4": dict(name="Knock Level 3D B (load x RPM)", category="Knock Control",
        note="3D knock level vs load/RPM.", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6b2f0": dict(name="Knock Level 3D C (load x RPM)", category="Knock Control",
        note="3D knock level vs load/RPM.", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6b304": dict(name="Knock Level 3D D (load x RPM)", category="Knock Control",
        note="3D knock level vs load/RPM (1x1 raw).", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x6b83c": dict(name="Cold-Start Advance Reduction (RPM)", category="Ignition Timing",
        note="min(c9a8, lookup(RPM)) in 0x12630 (cranking + out-of-band path).", source=f"{REPORT}/knock_control_report.md §8.4"),
    # ---- Ignition timing (ignition_timing_report.md §3 + ignition_timing_labels.json)
    "0x69078": dict(name="Ignition Leading - Base Timing", category="Ignition Leading",
        note="3D float, deg; main leading base map, read by 0x11f00.", source=f"{REPORT}/ignition_timing_report.md §3"),
    "0x690cc": dict(name="Ignition Leading Advance Cap", category="Ignition Leading",
        note="cap applied by 0x11f00.", source=f"{REPORT}/ignition_timing_report.md §3"),
    "0x69120": dict(name="Ignition Trailing - Base Timing", category="Ignition Trailing",
        note="trailing base map, read by 0x1206c.", source=f"{REPORT}/ignition_timing_report.md §3"),
    "0x69174": dict(name="Ignition Trailing Advance", category="Ignition Trailing",
        note="trailing advance, read by 0x1206c.", source=f"{REPORT}/ignition_timing_report.md §3"),
    "0x69018": dict(name="Coolant Timing Multiplier - Leading (candidate)", category="Ignition Leading",
        note="2D u8 n=9, data 0x6c7a0; 0x11f00: a618 = lookup_2d(ECT, 0x69018).", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x6902c": dict(name="Coolant Timing Multiplier - Trailing (candidate)", category="Ignition Trailing",
        note="2D u8 n=9, data 0x6c7d0; 0x1206c trailing mirror.", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x69040": dict(name="Off-Throttle Leading Timing 3D (candidate)", category="Ignition Leading",
        note="3D float n=16, data 0x6c81c; 0x11f00: a608 = lookup_3d(a7ac, a834, 0x69040).", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x6905c": dict(name="Leading Advance 3D Alt (candidate)", category="Ignition Leading",
        note="3D float n=10, data 0x6c920; 0x11f00: a60c = lookup_3d(load, rpm, 0x6905c), multiplied by b-weight.", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x69094": dict(name="Safe Mode Cap - Single (candidate)", category="Ignition Leading",
        note="1-cell float, data 0x6cb94; 0x11f00 safe-mode (cd60) cap lookup 3D.", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x690b0": dict(name="Safe Mode Advance Cap 3D - Leading (candidate)", category="Ignition Leading",
        note="3D float n=20, data 0x6cbec; 0x11f00 safe-mode (b12d) advance cap.", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x690e8": dict(name="Off-Throttle Trailing Timing 3D (candidate)", category="Ignition Trailing",
        note="3D float n=16, data 0x6cfdc; 0x1206c trailing mirror of 0x69040.", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x69104": dict(name="Trailing Advance 3D Alt (candidate)", category="Ignition Trailing",
        note="3D float n=10, data 0x6d0e0; 0x1206c trailing mirror of 0x6905c.", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x6913c": dict(name="Safe Mode Cap - Single Trailing (candidate)", category="Ignition Trailing",
        note="1-cell float, data 0x6d354; 0x1206c safe-mode cap.", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x69158": dict(name="Safe Mode Advance Cap 3D - Trailing (candidate)", category="Ignition Trailing",
        note="3D float n=20, data 0x6d3ac; 0x1206c safe-mode advance cap.", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x69190": dict(name="Max Advance vs RPM - Leading (candidate)", category="Ignition Leading",
        note="2D u8 n=9, data 0x6d7c4; 0x121fc: a660 = lookup_2d(rpm, 0x69190) = leading max advance.", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x691cc": dict(name="Max Advance vs RPM - Trailing (candidate)", category="Ignition Trailing",
        note="2D u8 n=9, data 0x6d844; 0x12300 trailing max advance.", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x691a4": dict(name="Min Advance vs Coolant A (candidate)", category="Ignition Timing",
        note="2D u8 n=8, data 0x6d7f0; 0x12630 lookup_2d(ECT,...) cranking+out-of-band branch.", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x691b8": dict(name="Min Advance vs Coolant B (candidate)", category="Ignition Timing",
        note="2D u8 n=8, data 0x6d818; 0x12630 else branch (normal running min advance).", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x69208": dict(name="Idle Base Timing - Cranking (candidate)", category="Idle Control",
        note="2D u8 n=9, data 0x6d8e4; read only when cranking (0x14100, aa62==1).", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x6921c": dict(name="Idle Base Timing - Cold Low Load (candidate)", category="Idle Control",
        note="2D u8 n=9, data 0x6d914; 0x14100 ECT<90 or load<0.5 branch.", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x69230": dict(name="Idle Base Timing - Warm High Load (candidate)", category="Idle Control",
        note="2D u8 n=4, data 0x6d930; 0x14100 else branch.", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3; ignition_timing_labels.json"),
    "0x6a060": dict(name="Idle Error Timing Correction - Leading Off (deg)", category="Ignition Leading",
        note="bool false/true bank, leading; 0x135b4.", source=f"{REPORT}/ignition_timing_report.md §3"),
    "0x6a074": dict(name="Idle Error Timing Correction - Leading On (deg)", category="Ignition Leading",
        note="bool true bank, leading; 0x135b4.", source=f"{REPORT}/ignition_timing_report.md §3"),
    "0x6a088": dict(name="Idle Error Timing Correction - Trailing Off (deg)", category="Ignition Trailing",
        note="bool false bank, trailing; 0x136e4.", source=f"{REPORT}/ignition_timing_report.md §3"),
    "0x6a09c": dict(name="Idle Error Timing Correction - Trailing On (deg)", category="Ignition Trailing",
        note="bool true bank, trailing; 0x136e4.", source=f"{REPORT}/ignition_timing_report.md §3"),
    "0x6a0d8": dict(name="IAT Compensation - On Throttle (deg)", category="Ignition Timing",
        note="0x14090.", source=f"{REPORT}/ignition_timing_report.md §3"),
    "0x6a0ec": dict(name="IAT Compensation - Cranking (deg) (candidate)", category="Ignition Timing",
        note="upstream 'Table 2D - 113'; 0x14090 cranking branch.", confidence="candidate",
        source=f"{REPORT}/ignition_timing_report.md §3"),
    "0x6af2c": dict(name="Ignition Leading - Cranking Timing Advance (ECT)", category="Ignition Leading",
        note="deg vs ECT; 0x43934 via 0x6b630.", source=f"{REPORT}/ignition_timing_report.md §3"),
    "0x6b644": dict(name="Ignition Trailing - Cranking Timing Advance (ECT)", category="Ignition Trailing",
        note="deg vs ECT; 0x439b2 via 0x6b630.", source=f"{REPORT}/ignition_timing_report.md §3"),
    "0x6b630": dict(name="Off-Throttle Leading Timing vs ECT (deg)", category="Ignition Leading",
        note="upstream 'Off Throttle Leading Timing Realted'; 0x43934.", source=f"{REPORT}/ignition_timing_report.md §3"),
    "0x6a7a4": dict(name="Ignition Leading - DSC Mode A Base", category="Ignition Leading",
        note="0x2cc2c.", source=f"{REPORT}/ignition_timing_report.md §3"),
    "0x6957c": dict(name="Ignition Leading - DSC Mode A Map 4", category="Ignition Leading",
        note="0x1815c.", source=f"{REPORT}/ignition_timing_report.md §3"),
    # ---- Fueling / load (fueling_control_report.md §7.3/§10.7/§10.8; load_fueling_report.md §4)
    "0x68ef8": dict(name="Injector Max Open Angle 1 (deg)", category="Fuel Injection",
        note="per-injector max open-angle degrees, consumer 0xff32; upstream name 'Max Injection Angle1???' was a guess - ROM scale is deg x2.",
        source=f"{REPORT}/fueling_control_report.md §10.7, §10 (0x68ef8/f0c/f20 = per-injector max open-angle)"),
    "0x68f0c": dict(name="Injector Max Open Angle 2 (deg)", category="Fuel Injection",
        note="per-injector max open-angle degrees, consumer 0xff32.", source=f"{REPORT}/fueling_control_report.md §10.7"),
    "0x68f20": dict(name="Injector Max Open Angle 3 (deg)", category="Fuel Injection",
        note="per-injector max open-angle degrees, consumer 0xff32.", source=f"{REPORT}/fueling_control_report.md §10.7"),
    "0x69788": dict(name="MAF Scaling", category="Sensors",
        note="MAF volts -> g/s (ADC AN3 via 0x6884 sweep).", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x69794": dict(name="MAF Density-Cap Window vs RPM (candidate)", category="Engine Load",
        note="read by 0x1a086.", confidence="candidate", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x697a0": dict(name="Transient-Detection Threshold vs Throttle (candidate)", category="Engine Load",
        note="read by 0x1a1dc.", confidence="candidate", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x697b4": dict(name="MAF Filter Coefficient vs RPM (candidate)", category="Engine Load",
        note="read by 0x1a418.", confidence="candidate", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x69cac": dict(name="OL Fuelling Base Correction - Baro", category="Fuel Injection - Open Loop",
        note="0x1ee4a: b170 = lookup(baro) [safe-mode pair with 0x69cc0]; b130 = max(b170*b190, b194).",
        source=f"{REPORT}/fueling_control_report.md §10.8"),
    "0x69cc0": dict(name="OL Fuelling Base Correction - Baro [Safe Mode]", category="Fuel Injection - Open Loop",
        note="safe-mode pair of 0x69cac.", source=f"{REPORT}/fueling_control_report.md §10.8"),
    "0x69cd4": dict(name="OL Target - Coolant Temperature Correction", category="Fuel Injection - Open Loop",
        note="b134 = lookup(coolant); b120 = b130*b134.", source=f"{REPORT}/fueling_control_report.md §10.8"),
    "0x69ce8": dict(name="OL Fuelling Rich Limit", category="Fuel Injection - Open Loop",
        note="rich-limit pair with 0x69cfc [safe mode].", source=f"{REPORT}/fueling_control_report.md §10.8"),
    "0x69cfc": dict(name="OL Fuelling Rich Limit [Safe Mode]", category="Fuel Injection - Open Loop",
        note="safe-mode pair of 0x69ce8.", source=f"{REPORT}/fueling_control_report.md §10.8"),
    "0x69d10": dict(name="OL Temperature Correction #B", category="Fuel Injection - Open Loop",
        note="", source=f"{REPORT}/fueling_control_report.md §10.7"),
    "0x69e00": dict(name="OL Changeover Enrichment", category="Fuel Injection - Open Loop",
        note="", source=f"{REPORT}/fueling_control_report.md §10.7"),
    "0x69e80": dict(name="OL Target - Throttle Tip In", category="Fuel Injection - Open Loop",
        note="b190 = lookup(rpm, tps) [safe-mode pair 0x69eb8].", source=f"{REPORT}/fueling_control_report.md §10.8"),
    "0x69eb8": dict(name="OL Target - Throttle Tip In [Safe Mode]", category="Fuel Injection - Open Loop",
        note="safe-mode pair of 0x69e80.", source=f"{REPORT}/fueling_control_report.md §10.8"),
    "0x69e9c": dict(name="OL Target - Main (load x RPM)", category="Fuel Injection - Open Loop",
        note="b194 = lookup_3d(load, rpm); stores lambda-1 (the +1.0 is added at the 0x1cc34 clamp [0.85,1.05]); [safe-mode pair 0x69ed4].",
        source=f"{REPORT}/fueling_control_report.md §10.8; load_fueling_report.md"),
    "0x69ed4": dict(name="OL Target - Main [Safe Mode]", category="Fuel Injection - Open Loop",
        note="safe-mode pair of 0x69e9c; lambda-1 storage.", source=f"{REPORT}/fueling_control_report.md §10.8"),
    "0x69ef0": dict(name="OL Target - Tip In - Coolant Implausible B", category="Fuel Injection - Open Loop",
        note="implausible-coolant blend A/B by fuel_blend_weight_ffffb11c.", source=f"{REPORT}/fueling_control_report.md §10.8"),
    "0x69f28": dict(name="OL Target - Tip In - Coolant Implausible A", category="Fuel Injection - Open Loop",
        note="", source=f"{REPORT}/fueling_control_report.md §10.8"),
    "0x69f0c": dict(name="OL Target - Coolant Implausible - Gear 5-6", category="Fuel Injection - Open Loop",
        note="gear 1-4 counterpart 0x69f44.", source=f"{REPORT}/fueling_control_report.md §10.8"),
    "0x69f44": dict(name="OL Target - Coolant Implausible - Gear 1-4", category="Fuel Injection - Open Loop",
        note="", source=f"{REPORT}/fueling_control_report.md §10.8"),
    "0x699b8": dict(name="Closed Loop WOT Enrichment", category="Fuel Target (Closed Loop)",
        note="upstream name had '??'.", source=f"{REPORT}/fueling_control_report.md §10.7"),
    "0x69a60": dict(name="Closed Loop Target Bank A (3D)", category="Fuel Target (Closed Loop)",
        note="upstream 'Table 3D - 29'; CL lambda target bank.", source=f"{REPORT}/fueling_control_report.md §10.7"),
    "0x69a7c": dict(name="Closed Loop Target Bank B (3D)", category="Fuel Target (Closed Loop)",
        note="upstream 'Table 3D - 30'; CL lambda target bank.", source=f"{REPORT}/fueling_control_report.md §10.7"),
    "0x6990c": dict(name="Closed Loop Warmup Time", category="Fuel Target (Closed Loop)",
        note="raw u16 x15 s; axis 0x6f7e0, data 0x6f81c; dispatch helper tbl_table_2d_304_check_datatype.",
        source=f"{REPORT}/knock_control_report.md §8.4; knock_loop_labels.json"),
    "0x6ac38": dict(name="Fuel Coolant Compensation (candidate)", category="Fuel Injection",
        note="2D lookup vs coolant used by calc_fuel_volume_request 0x306e8 (bf1c) and closed_loop_fuel_trim; descriptor unmatched in RX8Defs.",
        confidence="candidate", source=f"{REPORT}/fueling_labels.json; fueling_control_report.md §7.3"),
    "0x6ac88": dict(name="Fuel Injection - Engine Load Compensation (base fuel map)", category="Fuel Injection",
        note="THE RPM x load base fuel map (18x20 u16 scaled); bed4 in 0x306e8 fuel-volume calc.",
        source=f"{REPORT}/load_fueling_report.md §4; fueling_control_report.md §10.7"),
    "0x6a9a4": dict(name="Primary Injector Weighted Engine Temp Multiplier", category="Fuel Injection",
        note="temp x load injector multiplier.", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x6a9c0": dict(name="Secondary 1 Injector Weighted Engine Temp Multiplier", category="Fuel Injection",
        note="", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x6a9dc": dict(name="Secondary 2 Injector Weighted Engine Temp Multiplier", category="Fuel Injection",
        note="", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x6aa0c": dict(name="Injector Manifold Vacuum Multiplier A", category="Fuel Injection",
        note="vacuum (relative pressure) multiplier.", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x6aa20": dict(name="Injector Manifold Vacuum Multiplier B", category="Fuel Injection",
        note="", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x6aa34": dict(name="Injector Manifold Vacuum Multiplier C", category="Fuel Injection",
        note="", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x6aa48": dict(name="Estimated Manifold Pressure (RPM x load)", category="Engine Load",
        note="RPM x load -> estimated MAP.", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x6aa64": dict(name="Injector Latency - Secondary", category="Fuel Injection",
        note="latency vs estimated MAP x battery.", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x6aa80": dict(name="Injector Latency - Primary", category="Fuel Injection",
        note="latency vs estimated MAP x battery.", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x6aa9c": dict(name="Max Per-Channel Injection Time vs RPM (candidate)", category="Fuel Injection",
        note="read by 0x30030.", confidence="candidate", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x6ab48": dict(name="Primary Cranking Pulse Width", category="Fuel Injection",
        note="cranking pulse family with 0x6ab98/0x6abc8/0x6bab0.", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x6ab98": dict(name="Cranking Pulse Width B", category="Fuel Injection",
        note="", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x6abc8": dict(name="Cranking Pulse Width C", category="Fuel Injection",
        note="", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x6bab0": dict(name="Primary Cranking Decay Time", category="Fuel Injection",
        note="", source=f"{REPORT}/load_fueling_report.md §4"),
    "0x6ae28": dict(name="Warmup Fueling A", category="Fuel Injection",
        note="warmup family 0x6ae28/3c/58/74.", source=f"{REPORT}/fueling_control_report.md §7.3"),
    "0x6ae3c": dict(name="Warmup Fueling B", category="Fuel Injection",
        note="", source=f"{REPORT}/fueling_control_report.md §7.3"),
    "0x6ae58": dict(name="Warmup Fueling C", category="Fuel Injection",
        note="", source=f"{REPORT}/fueling_control_report.md §7.3"),
    "0x6ae74": dict(name="Warmup Fueling D", category="Fuel Injection",
        note="", source=f"{REPORT}/fueling_control_report.md §7.3"),
    "0x6b0c0": dict(name="Load Delta / Tip-In A", category="Fuel Injection",
        note="load-delta/tip-in family 0x6b0c0/0x6b124/0x6b160/0x6b17c.", source=f"{REPORT}/fueling_control_report.md §7.3"),
    "0x6b124": dict(name="Load Delta / Tip-In B", category="Fuel Injection",
        note="", source=f"{REPORT}/fueling_control_report.md §7.3"),
    "0x6b160": dict(name="Load Delta / Tip-In C", category="Fuel Injection",
        note="", source=f"{REPORT}/fueling_control_report.md §7.3"),
    "0x6b17c": dict(name="Load Delta / Tip-In D", category="Fuel Injection",
        note="", source=f"{REPORT}/fueling_control_report.md §7.3"),
    "0x6b1ec": dict(name="RPM-Based Max Engine Load", category="Engine Load",
        note="load ceiling vs RPM; x 0x6b200 (IAT) x 0x6b214 (baro) = 0.58-1.29 cell units = 0.92-2.03 g/rev (D5).",
        source=f"{REPORT}/load_fueling_report.md §4 (2026-10-31 addendum, D5 closed)"),
    "0x6b200": dict(name="Max Engine Load - IAT Correction", category="Engine Load",
        note="multiplier in the max-load clamp with 0x6b1ec/0x6b214.", source=f"{REPORT}/load_fueling_report.md (D5)"),
    "0x6b214": dict(name="Max Engine Load - Baro Correction", category="Engine Load",
        note="multiplier in the max-load clamp with 0x6b1ec/0x6b200.", source=f"{REPORT}/load_fueling_report.md (D5)"),
    "0x6ad30": dict(name="Air Flow x Battery A", category="Fuel Injection",
        note="air-flow x battery family 0x6ad30/0x6ad44.", source=f"{REPORT}/fueling_control_report.md §7.3"),
    "0x6ad44": dict(name="Air Flow x Battery B", category="Fuel Injection",
        note="", source=f"{REPORT}/fueling_control_report.md §7.3"),
    "0x6ac4c": dict(name="Per-Rotation Fuel Scale", category="Fuel Injection",
        note="per-rotation scale in the fuel-volume path.", source=f"{REPORT}/fueling_control_report.md §7.3"),
    # Closed-loop fuelling threshold range (0x1f0c4 open-loop request conditions)
    "0x69d24": dict(name="Closed Loop Fuelling Threshold A", category="Fuel Target (Closed Loop)",
        note="open-loop request conditions, read by 0x1f0c4; range 0x69d24-0x69d74.",
        source=f"{REPORT}/knock_control_report.md §8.4; fueling_control_report.md §7.3"),
    "0x69d38": dict(name="Closed Loop Fuelling Threshold B", category="Fuel Target (Closed Loop)",
        note="", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x69d4c": dict(name="Closed Loop Fuelling Threshold C", category="Fuel Target (Closed Loop)",
        note="", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x69d60": dict(name="Closed Loop Fuelling Threshold D", category="Fuel Target (Closed Loop)",
        note="", source=f"{REPORT}/knock_control_report.md §8.4"),
    "0x69d74": dict(name="Closed Loop Fuelling Threshold E", category="Fuel Target (Closed Loop)",
        note="", source=f"{REPORT}/knock_control_report.md §8.4"),
    # ---- Idle target RPM (idle_target_control_report.md §3)
    "0x69370": dict(name="Idle Target RPM - Base (Coolant)", category="Idle Control",
        note="7 u16 cells 1700->810 rpm vs coolant -40..80 C (axis 0x6dcf4, data 0x6dd10); base target selected by idle_target_rpm_calculate 0x1506c; filtered result written to idle_target_rpm 0xffffa7f4.",
        source=f"{REPORT}/idle_target_control_report.md §3"),
    "0x693d4": dict(name="Idle Target RPM - Variant F (Coolant)", category="Idle Control",
        note="7 u16 (1700->810), axis 0x6de40, data 0x6de5c; F variant of the idle target select in 0x1506c.",
        source=f"{REPORT}/idle_target_control_report.md §3"),
    "0x693e8": dict(name="Idle Target RPM - Variant G (Coolant)", category="Idle Control",
        note="7 u16 (1000..810), axis 0x6de6c, data 0x6de88; G variant of the idle target select in 0x1506c.",
        source=f"{REPORT}/idle_target_control_report.md §3"),
    "0x693fc": dict(name="Idle Target RPM - Variant H (Coolant)", category="Idle Control",
        note="7 u16 all 1900, axis 0x6de98, data 0x6deb4; H variant of the idle target select in 0x1506c.",
        source=f"{REPORT}/idle_target_control_report.md §3"),
    "0x69410": dict(name="Idle Target RPM - Vehicle Moving AT (Coolant)", category="Idle Control",
        note="7 u16 (1000->790), axis 0x6dec4, data 0x6dee0; selected for AT + vehicle moving (b534/b53c) in 0x1506c.",
        source=f"{REPORT}/idle_target_control_report.md §3"),
    "0x69384": dict(name="Idle Target RPM - Open-Loop Ramp (Coolant)", category="Idle Control",
        note="12 u16, axis 0x6dd20, data 0x6dd50; AT open-loop ramp in 0x15818, hard floor 500 rpm.",
        source=f"{REPORT}/idle_target_control_report.md §2/§3"),
    "0x693c0": dict(name="Idle Target RPM - Cranking (Coolant)", category="Idle Control",
        note="12 u16 (3500 cold cranking, 0 running), axis 0x6ddf8, data 0x6de28; cranking-vs-running select in 0x15934 (MT path).",
        source=f"{REPORT}/idle_target_control_report.md §2/§3"),
    "0x6935c": dict(name="Idle Target Filter Factor (RPM Error)", category="Idle Control",
        note="11 u16, axis 0x6dcb0, data 0x6dcdc; first-order filter factor on the idle target in 0x1506c, indexed by target-minus-current error (a7b0 - a7ac).",
        source=f"{REPORT}/idle_target_control_report.md §2/§3"),
    "0x692bc": dict(name="Idle Air Target Term (Target RPM)", category="Idle Control",
        note="16 u16, axis 0x6da0c, data 0x6da4c; target-term lookup 0x148a4 indexed by the encoded target 0xffffa7ac.",
        source=f"{REPORT}/idle_target_control_report.md §2a; idle_control_report.md §3"),
    # ---- Idle air control (idle_control_report.md §3)
    "0x6a218": dict(name="Idle Air Output Base (Air Demand)", category="Idle Control",
        note="21 u8, axis 0x732dc, data 0x73330; output base indexed by required air 0xffffa838 in idle_air_output_clamp 0x216f8.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x6a22c": dict(name="Idle Air Output Clamp Min (Coolant)", category="Idle Control",
        note="13 u8, axis 0x73348, data 0x7337c; lower output clamp in 0x216f8 (b2a4 = clamp(base, max, min)).",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x6a240": dict(name="Idle Air Output Clamp Max (Coolant)", category="Idle Control",
        note="13 u8, axis 0x7338c, data 0x733c0; upper output clamp in 0x216f8.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x6947c": dict(name="Idle Air Feedback Correction A (RPM Error)", category="Idle Control",
        note="9 u8, rpm axis 0x6dff4, data 0x6e018; feedback correction in idle_air_feedback_calc 0x15a9a.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x69490": dict(name="Idle Air Feedback Correction B (RPM Error)", category="Idle Control",
        note="5 u8, rpm axis 0x6e024, data 0x6e038; 0x15a9a.", source=f"{REPORT}/idle_control_report.md §3"),
    "0x694b8": dict(name="Idle Air Feedback Correction C (RPM Error)", category="Idle Control",
        note="14 u8, rpm axis 0x6e060, data 0x6e098; 0x15a9a.", source=f"{REPORT}/idle_control_report.md §3"),
    "0x69440": dict(name="Idle Air Feedback Clamp Min (Coolant)", category="Idle Control",
        note="9 u8, coolant axis 0x6df64, data 0x6df88; feedback clamp in 0x15a9a.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x69454": dict(name="Idle Air Feedback Clamp Max (Coolant)", category="Idle Control",
        note="9 u8, coolant axis 0x6df94, data 0x6dfb8; feedback clamp in 0x15a9a.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x694a4": dict(name="Idle Air Cranking Correction (Coolant)", category="Idle Control",
        note="6 u8, coolant axis 0x6e040, data 0x6e058; cranking correction in 0x15a9a.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x69244": dict(name="Idle Air Correction Select 1 (Coolant)", category="Idle Control",
        note="6 u16, coolant axis 0x6d934, data 0x6d94c; one of six correction tables selected by A/C/AT flags in idle_air_correction_select 0x16900.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x69258": dict(name="Idle Air Correction Select 2 (Coolant)", category="Idle Control",
        note="6 u16, coolant axis 0x6d958, data 0x6d970; select variant 2 of 6 (0x16900).",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x6926c": dict(name="Idle Air Correction Select 3 (Coolant)", category="Idle Control",
        note="6 u16, coolant axis 0x6d97c, data 0x6d994; select variant 3 of 6 (0x16900).",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x69280": dict(name="Idle Air Correction Select 4 (Coolant)", category="Idle Control",
        note="6 u16, coolant axis 0x6d9a0, data 0x6d9b8; select variant 4 of 6 (0x16900).",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x69294": dict(name="Idle Air Correction Select 5 (Coolant)", category="Idle Control",
        note="6 u16, coolant axis 0x6d9c4, data 0x6d9dc; select variant 5 of 6 (0x16900).",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x692a8": dict(name="Idle Air Correction Select 6 (Coolant)", category="Idle Control",
        note="6 u16, coolant axis 0x6d9e8, data 0x6da00; select variant 6 of 6 (0x16900).",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x6a100": dict(name="Idle Air MAF Term A", category="Idle Control",
        note="7 u16, axis 0x72680, data 0x7269c; MAF airflow term in idle_maf_airflow_term 0x148c4 (x 0.6345 x 60 / target rpm).",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x6a114": dict(name="Idle Air MAF Term B", category="Idle Control",
        note="7 u16, axis 0x726ac, data 0x726c8; MAF term variant B (0x148c4).",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x6a128": dict(name="Idle Air MAF Term C", category="Idle Control",
        note="7 u16, axis 0x726d8, data 0x726f4; MAF term variant C (0x148c4).",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x6a814": dict(name="Idle Air Baro Compensation 3D", category="Idle Control",
        note="3D 5x3 u8, axes 0x766dc/0x766f0, data 0x766fc; baro comp in idle_baro_comp 0x16358.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x6a830": dict(name="Idle Air IAT Compensation", category="Idle Control",
        note="4 u16, axis 0x7673c, data 0x7674c; IAT comp 0x16720.", source=f"{REPORT}/idle_control_report.md §3"),
    "0x6a13c": dict(name="Idle Air Aux Compensation", category="Idle Control",
        note="6 u16, axis 0x7270c (0xffffb220), data 0x72724; aux term 0x16380.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x69530": dict(name="Idle A/C Load (Coolant)", category="Idle Control",
        note="9 u8, coolant axis 0x6e1a8, data 0x6e1cc; A/C load in idle_ac_load_calc 0x16748.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x69544": dict(name="Idle A/C Load 3D (Coolant x Catalyst)", category="Idle Control",
        note="3D 9x3 u8, axes 0x6e1d8/0x6e1fc, data 0x6e208; A/C load 3D in 0x16748.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x69424": dict(name="Idle Trim Ramp Floor 3D (Coolant x Baro)", category="Idle Control",
        note="3D 7x3 u8, axes 0x6def0/0x6df0c, data 0x6df18; trim ramp floor 0x14f6c.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x694cc": dict(name="Idle A/C Request Term", category="Idle Control",
        note="4 u16 (all 0 stock), coolant axis 0x6e0c4, data 0x6e0d4; A/C request term 0x16432.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x69768": dict(name="Fuel Cut Resume Threshold (Knock)", category="Idle Control",
        note="12 u16, axis 0x6ecf8, data 0x6ed28; fuel-cut resume threshold 0x15a40 indexed by rough_knock_correction_leading 0xffffa6ac.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x6b318": dict(name="Idle Ratio Calc A (candidate)", category="Idle Control", confidence="candidate",
        note="7 u8, axis 0x7a770, data 0x7a78c; ratio calc input in idle_ratio_calcs 0x3337c; exact role not fully established.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x6b32c": dict(name="Idle Ratio Calc B (candidate)", category="Idle Control", confidence="candidate",
        note="12 u16, axis 0x7a794, data 0x7a7c4; ratio calc input in 0x3337c; exact role not fully established.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x6af18": dict(name="Idle Ratio Calc C (candidate)", category="Idle Control", confidence="candidate",
        note="8 u8, axis 0x794d4, data 0x794f4; ratio calc input in 0x3337c; exact role not fully established.",
        source=f"{REPORT}/idle_control_report.md §3"),
    "0x6af40": dict(name="Idle Ratio Calc D (candidate)", category="Idle Control", confidence="candidate",
        note="16 u16, axis 0x79538, data 0x79578; ratio calc input in 0x3337c; exact role not fully established.",
        source=f"{REPORT}/idle_control_report.md §3"),
    # ---- Alternator / charging (alternator_control_report.md §3)
    "0x6a54c": dict(name="Alternator Field Drive Target vs Alt Speed", category="Alternator Control",
        note="11 u16, alt-speed axis 0x74ae0 (0xffffb598 = engine rpm x 2.08), data 0x74b0c; field-drive target in alternator_voltage_error_calc 0x2616e; upstream name 'Alternator Duty Cycle Max' corrected.",
        source=f"{REPORT}/alternator_control_report.md §3"),
    "0x6a5c4": dict(name="Alternator Duty Base 3D (Alt Speed x Load)", category="Alternator Control",
        note="3D 11x12 u8, axes 0x74c54/0x74c80 (alt speed, filtered electrical load 0xffffb5e0), data 0x74cb0; duty base in alternator_duty_calc 0x26624.",
        source=f"{REPORT}/alternator_control_report.md §3"),
    "0x6a560": dict(name="Alternator Duty To Percent Scale", category="Alternator Control",
        note="13 u16, axis 0x74b24, data 0x74b58; duty-to-percent clamp [0,100] in 0x26624; upstream name 'Alternator Diagnostic Voltage Delta to DC' corrected.",
        source=f"{REPORT}/alternator_control_report.md §3"),
    "0x6a524": dict(name="Battery Temp Model - Speed Decay", category="Alternator Control",
        note="7 u8, vehicle-speed axis 0x74a84, data 0x74aa0; battery-temp model decay in battery_temp_model 0x25ba4.",
        source=f"{REPORT}/alternator_control_report.md §3"),
    "0x6a5b0": dict(name="Charging Voltage Target vs Battery Temp", category="Alternator Control",
        note="9 u16, battery-temp axis 0x74c1c (0xffffb5c4), data 0x74c40; voltage target in alternator_voltage_target_select 0x25c6c (14.2 V base +/- hysteresis).",
        source=f"{REPORT}/alternator_control_report.md §3"),
    "0x6a59c": dict(name="Charging Voltage Target - Alt Mode", category="Alternator Control",
        note="9 u16 (all 0 stock), axis 0x74be4, data 0x74c08; alternate-mode voltage target in 0x25c6c.",
        source=f"{REPORT}/alternator_control_report.md §3"),
    "0x6a790": dict(name="Alternator Drag Torque vs Alt Speed (candidate)", category="Alternator Control",
        confidence="candidate",
        note="5 u16, alt-speed axis 0x75cb4, data 0x75cc8; speed-indexed table x ratio stored to 0xffffbcc4 in 0x2ce18; Nm and ratio physical meanings unproven (defs-merge review).",
        source=f"{REPORT}/alternator_control_report.md §3; defs-merge/README.md (0x2ce18 candidate)"),
    # ---- CAN 0x212-derived signal consumers (dsc_can_arbitration_report.md; 0x218c4 body)
    "0x6a150": dict(name="DSC Mode C - Max Throttle Plate Opening (RPM)", category="Torque Control",
        note="19 u8, rpm axis 0x7273c, data 0x72788; read in throttle plate control 0x218c4 when DSC mode bit 0x40 (0xffffbbcc, from the CAN 0x212 mode byte) is set and 0xffffbbca clear.",
        source=f"{REPORT}/dsc_can_arbitration_report.md §2/§4; reverse-engineered/decompiled/60E15120_N3J1E/functions/000218c4_ref_throttlePlateControl_Related.c"),
}

# Short editor-facing <description> text per descriptor (AGENTS.md rule 6b):
# a simplified description of what the table does — only where accurately
# known (high confidence). No memory addresses, no structural-match or
# derivation details here; provenance stays in note/evidence/source and the
# investigation docs. Candidate labels get CANDIDATE_DESC instead.
DESC = {
    # ---- Knock control
    "0x6af54": "Lowest engine load at which knock control is enabled, vs RPM.",
    "0x6af68": "Most negative knock retard allowed (lower clamp), vs RPM.",
    "0x6af7c": "Alternate lower knock retard clamp, vs RPM.",
    "0x6af90": "Upper knock retard clamp, vs RPM.",
    "0x6afa4": "Knock retard recovery target in fail-safe, vs RPM.",
    "0x6afb8": "Scale applied to learned knock retard.",
    "0x6b250": "Scales knock sensor voltage to knock magnitude.",
    "0x6b264": "Number of cycles knock retard is held after a transient.",
    "0x6b270": "Knock level threshold that triggers ignition retard, channel A, vs RPM.",
    "0x6b27c": "Alternate knock ignition-retard threshold A, vs RPM.",
    "0x6b288": "Knock level threshold that triggers ignition retard, channel B, vs RPM.",
    "0x6b294": "Alternate knock ignition-retard threshold B, vs RPM.",
    "0x6b2a0": "Minimum knock noise threshold (clamp floor).",
    "0x6b2ac": "Knock noise floor vs RPM.",
    "0x6b2b8": "Knock level map vs load and RPM (variant A).",
    "0x6b2d4": "Knock level map vs load and RPM (variant B).",
    "0x6b2f0": "Knock level map vs load and RPM (variant C).",
    "0x6b304": "Knock level map vs load and RPM (variant D).",
    "0x6b83c": "Cold-start ignition advance reduction, vs RPM.",
    # ---- Ignition timing
    "0x69078": "Main leading (front rotor) base ignition timing vs load and RPM.",
    "0x690cc": "Maximum allowed leading ignition advance.",
    "0x69120": "Trailing (rear rotor) base ignition timing map.",
    "0x69174": "Trailing ignition advance adder.",
    "0x6a060": "Idle speed error correction to leading timing (idle control off).",
    "0x6a074": "Idle speed error correction to leading timing (idle control on).",
    "0x6a088": "Idle speed error correction to trailing timing (idle control off).",
    "0x6a09c": "Idle speed error correction to trailing timing (idle control on).",
    "0x6a0d8": "Intake-air-temperature correction to timing on throttle.",
    "0x6af2c": "Cranking ignition advance adder vs coolant temperature, leading.",
    "0x6b644": "Cranking ignition advance adder vs coolant temperature, trailing.",
    "0x6b630": "Off-throttle leading timing vs coolant temperature.",
    "0x6a7a4": "Leading base timing in DSC mode A.",
    "0x6957c": "Leading timing map 4 in DSC mode A.",
    # ---- Fuel / injection / airflow
    "0x68ef8": "Maximum injector open angle, stage 1, in degrees.",
    "0x68f0c": "Maximum injector open angle, stage 2, in degrees.",
    "0x68f20": "Maximum injector open angle, stage 3, in degrees.",
    "0x69788": "MAF sensor voltage to air mass flow (g/s).",
    "0x69cac": "Open-loop fuelling base correction vs barometric pressure.",
    "0x69cc0": "Open-loop fuelling base correction vs barometric pressure (safe mode).",
    "0x69cd4": "Open-loop target lambda correction vs coolant temperature.",
    "0x69ce8": "Rich limit for open-loop fuelling.",
    "0x69cfc": "Rich limit for open-loop fuelling (safe mode).",
    "0x69d10": "Open-loop fuelling temperature correction B.",
    "0x69e00": "Fuel enrichment during open-loop changeover.",
    "0x69e80": "Open-loop target lambda during throttle tip-in, vs RPM and throttle.",
    "0x69eb8": "Open-loop target lambda during throttle tip-in (safe mode).",
    "0x69e9c": "Main open-loop target lambda vs engine load and RPM.",
    "0x69ed4": "Main open-loop target lambda vs engine load and RPM (safe mode).",
    "0x69ef0": "Tip-in target lambda for implausible coolant reading (variant B).",
    "0x69f28": "Tip-in target lambda for implausible coolant reading (variant A).",
    "0x69f0c": "Open-loop target lambda for implausible coolant reading, gears 5-6.",
    "0x69f44": "Open-loop target lambda for implausible coolant reading, gears 1-4.",
    "0x699b8": "Closed-loop fuel enrichment at wide-open throttle.",
    "0x69a60": "Closed-loop target lambda bank A vs load and RPM.",
    "0x69a7c": "Closed-loop target lambda bank B vs load and RPM.",
    "0x6ac88": "Base fuel map vs RPM and engine load.",
    "0x6a9a4": "Engine-temperature multiplier for primary injector pulse width.",
    "0x6a9c0": "Engine-temperature multiplier for secondary injector 1 pulse width.",
    "0x6a9dc": "Engine-temperature multiplier for secondary injector 2 pulse width.",
    "0x6aa0c": "Manifold vacuum correction to injection volume (variant A).",
    "0x6aa20": "Manifold vacuum correction to injection volume (variant B).",
    "0x6aa34": "Manifold vacuum correction to injection volume (variant C).",
    "0x6aa48": "Estimated manifold pressure vs RPM and engine load.",
    "0x6aa64": "Secondary injector dead time vs estimated manifold pressure and battery voltage.",
    "0x6aa80": "Primary injector dead time vs estimated manifold pressure and battery voltage.",
    "0x6ab48": "Cranking injection pulse width (primary).",
    "0x6ab98": "Cranking injection pulse width (variant B).",
    "0x6abc8": "Cranking injection pulse width (variant C).",
    "0x6bab0": "Cranking pulse decay time.",
    "0x6ae28": "Warmup fuel enrichment (variant A).",
    "0x6ae3c": "Warmup fuel enrichment (variant B).",
    "0x6ae58": "Warmup fuel enrichment (variant C).",
    "0x6ae74": "Warmup fuel enrichment (variant D).",
    "0x6b0c0": "Load-delta / tip-in fuel correction (variant A).",
    "0x6b124": "Load-delta / tip-in fuel correction (variant B).",
    "0x6b160": "Load-delta / tip-in fuel correction (variant C).",
    "0x6b17c": "Load-delta / tip-in fuel correction (variant D).",
    "0x6b1ec": "Maximum engine load ceiling vs RPM.",
    "0x6b200": "Intake-air-temperature multiplier in the max engine load clamp.",
    "0x6b214": "Barometric-pressure multiplier in the max engine load clamp.",
    "0x6ad30": "Air-flow x battery-voltage correction (variant A).",
    "0x6ad44": "Air-flow x battery-voltage correction (variant B).",
    "0x6ac4c": "Per-rotation fuel scale in the fuel-volume calculation.",
    "0x69d24": "Closed-loop fuelling enable threshold (variant A).",
    "0x69d38": "Closed-loop fuelling enable threshold (variant B).",
    "0x69d4c": "Closed-loop fuelling enable threshold (variant C).",
    "0x69d60": "Closed-loop fuelling enable threshold (variant D).",
    "0x69d74": "Closed-loop fuelling enable threshold (variant E).",
    "0x6990c": "Time after start during which closed-loop fuelling is inhibited.",
    # ---- Idle target RPM
    "0x69370": "Base idle target speed vs coolant temperature (cold engines idle higher).",
    "0x693d4": "Alternate idle target speed vs coolant temperature (variant F).",
    "0x693e8": "Alternate idle target speed vs coolant temperature (variant G).",
    "0x693fc": "Alternate idle target speed vs coolant temperature (variant H).",
    "0x69410": "Idle target speed while the vehicle is moving (automatic transmission), vs coolant.",
    "0x69384": "Open-loop idle speed ramp vs coolant (automatic transmission); never below 500 rpm.",
    "0x693c0": "Cranking idle target vs coolant (manual transmission cranking/running select).",
    "0x6935c": "Smoothing factor applied to the idle target speed, vs target error.",
    "0x692bc": "Idle air target term vs the encoded idle target speed.",
    # ---- Idle air control
    "0x6a218": "Base idle air output vs computed required air.",
    "0x6a22c": "Minimum idle air output vs coolant temperature.",
    "0x6a240": "Maximum idle air output vs coolant temperature.",
    "0x6947c": "Idle air feedback correction vs engine speed error (variant A).",
    "0x69490": "Idle air feedback correction vs engine speed error (variant B).",
    "0x694b8": "Idle air feedback correction vs engine speed error (variant C).",
    "0x69440": "Lower clamp of the idle air feedback term vs coolant temperature.",
    "0x69454": "Upper clamp of the idle air feedback term vs coolant temperature.",
    "0x694a4": "Idle air correction while cranking vs coolant temperature.",
    "0x69244": "Idle air correction vs coolant temperature (select variant 1 of 6).",
    "0x69258": "Idle air correction vs coolant temperature (select variant 2 of 6).",
    "0x6926c": "Idle air correction vs coolant temperature (select variant 3 of 6).",
    "0x69280": "Idle air correction vs coolant temperature (select variant 4 of 6).",
    "0x69294": "Idle air correction vs coolant temperature (select variant 5 of 6).",
    "0x692a8": "Idle air correction vs coolant temperature (select variant 6 of 6).",
    "0x6a100": "Idle air MAF airflow term (variant A).",
    "0x6a114": "Idle air MAF airflow term (variant B).",
    "0x6a128": "Idle air MAF airflow term (variant C).",
    "0x6a814": "Idle air barometric-pressure compensation vs baro and load.",
    "0x6a830": "Idle air intake-air-temperature compensation.",
    "0x6a13c": "Auxiliary idle air compensation term.",
    "0x69530": "Idle air added for A/C compressor load vs coolant temperature.",
    "0x69544": "Idle air added for A/C load vs coolant temperature and catalyst state.",
    "0x69424": "Floor of the idle trim ramp vs coolant temperature and barometric pressure.",
    "0x694cc": "Idle air term for the A/C request (stock: zero).",
    "0x69768": "Engine speed threshold for resuming fuel after a fuel cut, vs knock correction.",
    # ---- Alternator / charging
    "0x6a54c": "Target alternator field drive vs alternator speed.",
    "0x6a5c4": "Base alternator field duty vs alternator speed and electrical load.",
    "0x6a560": "Scales the computed alternator duty to percent (clamped 0-100).",
    "0x6a524": "Battery temperature model decay vs vehicle speed.",
    "0x6a5b0": "Target charging voltage vs battery temperature.",
    "0x6a59c": "Alternate target charging voltage (alternate mode; stock zero).",
    # ---- CAN 0x212-derived signal consumers
    "0x6a150": "Maximum throttle plate opening while stability-control mode C is active, vs engine speed.",
}
CANDIDATE_DESC = "Purpose not fully verified (candidate label)."


def desc_for(key, name, confidence):
    """Editor-facing short description; falls back to the candidate note or a
    name-derived sentence so every entry always carries a usable desc."""
    if key in DESC:
        return DESC[key]
    if confidence == "candidate":
        return CANDIDATE_DESC
    n = re.sub(r"\s*\(candidate\)\s*$", "", name).strip()
    return n + "."


# lookup_aliases keys that are descriptor-keyed and NOT curated above; they get
# an auto-derived name (alias minus tbl_/candidate_ prefix and _XXXXXXXX
# suffix) and keep their evidence string. candidate_ aliases -> confidence
# "candidate".
ALIAS_SOURCES = ["knock_loop_labels.json", "ignition_timing_labels.json", "fueling_labels.json"]

ADDR_RE = re.compile(r"([0-9a-fA-F]{6,8})$")


def norm_key(key):
    """'PTR_DAT_0006af68' / 'DAT_0006ac38' / '00069208' -> '0x6af68'."""
    m = re.search(r"([0-9a-fA-F]{6,8})\s*$", key)
    if not m:
        return None
    return "0x%x" % int(m.group(1), 16)


def auto_name(alias):
    a = alias
    a = re.sub(r"^(candidate_)?tbl_", "", a)
    a = re.sub(r"^(candidate_)?", "", a)
    a = ADDR_RE.sub("", a).strip("_")
    a = a.replace("_", " ").strip()
    return a[:1].upper() + a[1:]


def main():
    labels = {}
    # 1. machine-readable lookup_aliases
    for fn in ALIAS_SOURCES:
        d = json.loads((LABELS / fn).read_text(encoding="utf-8"))
        for key, val in (d.get("lookup_aliases") or {}).items():
            k = norm_key(key)
            if not k:
                continue
            if isinstance(val, dict):
                alias, evidence = val.get("alias", ""), val.get("evidence", "")
            else:
                alias, evidence = val, ""
            cand = "candidate_" in alias
            name = auto_name(alias) + (" (candidate)" if cand else "")
            conf = "candidate" if cand else "high"
            labels[k] = {
                "name": name,
                "category": None,  # filled by curated entries or left to the existing def
                "note": "",
                "desc": desc_for(k, name, conf),
                "evidence": evidence,
                "source": f"data/labels/60E15120_N3J1E/{fn} lookup_aliases[{key}]",
                "confidence": conf,
                "alias": alias,
            }
    # 2. curated report entries override
    for k, e in REPORT_ENTRIES.items():
        base = labels.get(k, {})
        conf = e.get("confidence", "high")
        labels[k] = {
            "name": e["name"],
            "category": e.get("category"),
            "note": e.get("note", ""),
            "desc": desc_for(k, e["name"], conf),
            "evidence": e.get("evidence", base.get("evidence", "")),
            "source": e["source"],
            "confidence": conf,
            "alias": base.get("alias"),
        }
    # validate keys against data/maps index (every descriptor must exist in ROM extraction)
    import csv
    idx = ROOT / "data" / "maps" / "60E15120_N3J1E" / "index.tsv"
    descs = set()
    with open(idx, newline="", encoding="utf-8") as f:
        for row in csv.DictReader(f, delimiter="\t"):
            descs.add("0x%x" % int(row["descriptor"], 16))
    missing = sorted(set(labels) - descs)
    assert not missing, f"label descriptors not in maps index: {missing}"
    for k, v in labels.items():
        assert v.get("desc"), f"{k}: no editor-facing desc"
        if v["confidence"] == "high" and k not in DESC:
            print(f"warning: {k} ({v['name']!r}) has no curated DESC entry; "
                  f"falling back to name-derived desc")
    out = {
        "pass": "defs_table_labels",
        "reference_rom": "60E15120_N3J1E",
        "rom_sha256": json.loads((LABELS / "provenance_hashes.json").read_text(encoding="utf-8")).get("rom_sha256")
                        or "a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1",
        "date": "2026-11-02",
        "key": "lookup descriptor address (tbl_XXXXXXXX name in data/maps/<rom>/index.tsv)",
        "entries": labels,
        "counts": {"total": len(labels),
                   "high": sum(1 for v in labels.values() if v["confidence"] == "high"),
                   "candidate": sum(1 for v in labels.values() if v["confidence"] == "candidate"),
                   "categorized": sum(1 for v in labels.values() if v.get("category"))},
    }
    # literal-pool scalar provenance for the "Scalar - ..." 1-cell entries that
    # extend_defs_all_roms.inject_scalar_tables injects into every per-ROM def:
    # editor name/units/description come from SCALAR_ENTRIES there (rule 6b text);
    # value/bits/evidence/per-ROM addresses come from extract_scalars.py output
    import extend_defs_all_roms as _ede
    cross = json.loads((ROOT / "data" / "maps" / "cross_rom_scalars.json").read_text(encoding="utf-8"))
    out["scalar_entries"] = {
        key: {
            "name": _ede.SCALAR_ENTRIES.get(key, {}).get("name"),
            "units": _ede.SCALAR_ENTRIES.get(key, {}).get("units"),
            "description": _ede.SCALAR_ENTRIES.get(key, {}).get("description"),
            "value": sc.get("value"),
            "bits_hex": sc.get("bits_hex"),
            "subsystem": sc.get("subsystem"),
            "ram_alias": sc.get("ram_alias"),
            "evidence": sc.get("evidence"),
            "ref_addrs": sc.get("ref_addrs"),
            "source": "data/maps/cross_rom_scalars.json (extract_scalars.py --all)",
        }
        for key, sc in cross["scalars"].items()
    }
    OUT.write_text(json.dumps(out, indent=1, ensure_ascii=False) + "\n", encoding="utf-8")
    print(f"wrote {OUT.relative_to(ROOT)}: {len(labels)} entries "
          f"({out['counts']['high']} high, {out['counts']['candidate']} candidate, "
          f"{out['counts']['categorized']} categorized)")


if __name__ == "__main__":
    main()
