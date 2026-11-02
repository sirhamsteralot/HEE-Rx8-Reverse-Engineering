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

Each entry: {name, category, note, evidence, source, confidence}.
  name       RomRaider table name to use (" (candidate)" suffix marks unproven)
  category   RomRaider category = the grouping (existing RX8Defs category names)
  note       short semantics/units note appended to the def <description>
  confidence "high" = binary-verified role; "candidate" = hypothesis (label ladder)

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
}

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
            labels[k] = {
                "name": auto_name(alias) + (" (candidate)" if cand else ""),
                "category": None,  # filled by curated entries or left to the existing def
                "note": "",
                "evidence": evidence,
                "source": f"data/labels/60E15120_N3J1E/{fn} lookup_aliases[{key}]",
                "confidence": "candidate" if cand else "high",
                "alias": alias,
            }
    # 2. curated report entries override
    for k, e in REPORT_ENTRIES.items():
        base = labels.get(k, {})
        labels[k] = {
            "name": e["name"],
            "category": e.get("category"),
            "note": e.get("note", ""),
            "evidence": e.get("evidence", base.get("evidence", "")),
            "source": e["source"],
            "confidence": e.get("confidence", "high"),
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
    OUT.write_text(json.dumps(out, indent=1, ensure_ascii=False) + "\n", encoding="utf-8")
    print(f"wrote {OUT.relative_to(ROOT)}: {len(labels)} entries "
          f"({out['counts']['high']} high, {out['counts']['candidate']} candidate, "
          f"{out['counts']['categorized']} categorized)")


if __name__ == "__main__":
    main()
