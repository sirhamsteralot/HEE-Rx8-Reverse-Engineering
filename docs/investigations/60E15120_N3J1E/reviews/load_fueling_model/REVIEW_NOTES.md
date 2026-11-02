# Load/fuelling model review — per-function evidence notes

Date: 2026-10-29. Ground truth: untouched ROM
(`Mazda_RX8_PCM_ReverseEngineering/Stock_ROMs/60E15120_N3J1E.bin`, 512 KiB,
SHA-256 `a7cd953c2a87af12ee2814a95c958dc23959d352ef9c5e7f82b8ab8952f264f1`),
`decompiled/firmware_disassembly.asm`, `decompiled/`, `decompiled/callgraph.tsv`,
`cross_ecu/romraider_descriptor_matches.json`. Per AGENTS.md, `ref_`/`CAL_`/
`inferred_`/candidate labels are hypotheses; nothing here was executed.

## A. MAF acquisition and validation

### 0x7438 ref_getMAFSensorValue (inherited name)
- Reads `DAT_ffff9eea` = ADC channel 3 result (ADDR3H, written in the
  0x6884 sweep; channel order verified against the ADDRx→RAM stride in the
  decompiled sweep and its validated instruction bytes).
- volts = raw x 7.6293945e-05 (=5/65536); scaled by tbl 0x69788 ("MAF
  Scaling", RX8Defs match) -> 0xffff9f78.
- Side flags at 0xffff9f7c: 0 normal (0xac0 <= raw < 0xfae2), 1 (>= 0xfae2),
  2 (< 0xac0). Volts equivalents: 0xac0 -> 0.084 V, 0xfae2 -> 4.839 V.

### 0x19f4e ref_MAFRelated (inherited name; ISR 0x63f0 -> 0x114b0 -> 0x19806)
- a9e4 (0xffffa9e4) = raw x 5/65536 via `rx8_decode_u16_affine(0x38a00000,0)`
  = **MAF in volts**.
- Excursion counters aa35 (raw >= 0xf852), aa36 (raw < 0x7ae), u8-saturating,
  reset when back in range.
- Copy gate (disassembly 0x19fa8–0x19fe8): a9e4 = aa2c and a9e8 = 0xffff9f78
  are refreshed when (aa35 >= 3) OR (aa36 >= 3) OR raw in [0x7ae, 0xf852).
  1–2 sample excursions hold the previous values (debounce); sustained
  excursions propagate (so the fault manager can detect them).
- In-range volts: 0x7ae -> 0.0595 V, 0xf852 -> 4.768 V.

### 0x3b214 FUN_0003b214 (fault manager)
- c593 = (a9e4 < 0.64), c594 = (a9e4 > 4.9); battery >= 8 V gate;
  RPM windows: low-fault checked >= 500 RPM, high-fault checked <= 6500 RPM;
  4-count debounces c58c/c58d; fault slots 10/0xb via `ref_getFaultStatus__`.
- c590 = 1 selects the throttle fallback model (consumed by 0x1a086);
  c595 = 1 = healthy.

### 0x1a13c FUN_0001a13c (fallback model)
- `DAT_ffffaa28 = ((DAT_ffffad48 x 0.04 - -0.26) x RPM) / 60.0` i.e.
  ((x*0.04)+0.26)*RPM/60. Candidate: alpha-N-style airflow estimate used when
  MAF is faulted. `DAT_ffffad48` writer not traced (candidate raw throttle).

## B. MAF conditioning (task[5] chain 0x65f6 -> 0x11b7e -> 0x19794)

### 0x1a086 FUN_0001a086
- Six-slot circular buffer (aa34 = 0..5) of previous/current MAF per slot;
  used value = (prev + new)/2.
- Density cap: `a9f0 = f(RPM; tbl 0x69794) x 293.0/(IAT+273) x baro/101.33299`;
  literals verified from ROM: 273.0 @0x1a194, 293.0 @0x1a198 (0x43928000),
  101.33299 @0x1a1a0. **293.0, not 295** (correction applied to the
  synchronized views and `source_review/accepted_ram_aliases.tsv`).
- If c590 (MAF fault) set: mass_air_flow (0xffffa9ec) = aa28 (fallback).
- 0x19f40 is the direct pass-through (init/reset path): a9ec = a9e8.

## C. Load calculation (task[6] chain 0x661e -> 0x11ba4 -> 0x197be)

### 0x1a1dc FUN_0001a1dc (transient detection)
- Track aa44 = filter(RPM, coeff 0.5); compares throttle/RPM deltas against
  `f(throttle; tbl 0x697a0)`; sets aa4d/aa4e event flags, noise-reset
  markers aa5c/aa5d, and **aa4c = 1 to use raw (unfiltered) MAF** during
  transients/startup, else 0.

### 0x1a418 FUN_0001a418 (airflow index) — ROM-verified
- aa54 = lookup2d(RPM; tbl 0x697b4) — filter coefficient (verified: first
  jsr @0x2068 takes fr4 = @0xffffb548 via fr15, table pointer 0x697b4 from
  pool @0x1a4d0).
- aa48 = first-order filter of mass_air_flow with coeff aa54.
- Selected MAF: raw (a9ec) if aa4c==1 else filtered (aa48).
- **aa3c = min(selected x 60.0/RPM, 5.0)** — literals 60.0 @0x1a4e8,
  5.0 @0x1a4f4; divide helper @0x3db24; select flag @0xffffaa4c.
- aa38 = snap-filtered variant of the same product (coeff 1.0), used
  elsewhere (candidate: unfiltered load for other consumers).

### 0x33a6c ref_airPerStroke — ROM-verified
- `DAT_ffffc0b0 = DAT_ffffaa3c x 0.6345`; literal pointer @0x33b70 ->
  0x7a088 = 0.6345 (float32 big-endian). Physical meaning unresolved.

### 0x33ad2 ref_calculateEngineLoad
- If cranking/injectors-off (a41c==1, or c0c5==0 & injectors off): load :=
  0.525.
- Else load = min(filter(c0b0; coeff 0.2, snap 1.0 while c0c4 != 0), c0b8).

### 0x33a58 FUN_00033a58 / 0x19640
- Sets c0c4 = 25 (snap countdown for the load filter). Caller 0x19640 not
  traced in this pass.

### 0x33ab0 ref_getMaxLoadCompensations + 0x33a7c ref_calculateEngineLoadMax
- c0bc = f(IAT; 0x6b200), c0c0 = f(baro; 0x6b214);
  c0b8 = c0bc x c0c0 x f(RPM; tbl_rpm_based_max_engine_load 0x6b1ec).
  Countdown of c0c4 also lives here.

## D. Pressure model

### 0xd144 ref_getBaroSensorVal / 0xd13c / 0x1ad54
- `DAT_ffffa3dc = raw x 25.325 + 0.0182` (kPa candidate);
  0x1ad54 selects it into 0xffffad14, forced to 101.3 (0x42ca999a) when
  flag c5d7 set. Sensor channel not traced.

### 0x2fdb0 FUN_0002fdb0 (MAP estimate)
- `be18 = lookup3d(RPM, load; tbl_estimated_manifold_pressure 0x6aa48)`;
  `be00 = (IAT+273) x be18 x DAT_ffffbe1c / 300.0` (0x43960000 = 300.0).
  be1c writer not traced (candidate VE-type factor).
- 0x2fe00: relative = baro − be00 (two copies be04/be08).

## E. Fuel volume request and injector path (task 0x20e40)

### 0x306e8 ref_calcFuelVolumeRequest — ROM/disasm-verified
- bed0 = load x 0.07196 (literal pointer @0x30830 -> 0x78170).
  2026-11-02: this and the other verified literals are machine-extracted per ROM
  into `data/maps/<rom-id>/scalars.{json,tsv}` + `cross_rom_scalars.json`
  (`utilities/scripts/extract_scalars.py`, tests/test_extract_scalars.py).
- bed4 = lookup3d(RPM, load; 0x6ac88): RPM argument via fr4 delay slot at
  0x3070c (@0x30800 -> 0xb548); load already in fr5 from the bed0 multiply
  (0x306fe `fmul fr5,fr3` used 0xffffc0b4 via @0x307fe). The decompiler's
  one-arg print is an ABI artifact.
- Enrichment sum assembled from c104/cde0 (max), coolant-table 0x6ac38 (min
  with c00c + open_loop_fuel_target b120), b0c4, bc74, cdf4, a5dc, bf40;
  subtractors c0c8, ae08, b21c, b0d0 addend; all multiplied by
  `DAT_ffffadec` (fuel-target multiplier: 1.0 default; closed-loop value
  clamped [b048, b044] in 0x1c880) and bed4.
- `beac = FUN_0005c024(bf14)`: diagnostic trim adder — active only when a
  diagnostic request id 0x17e0 (RAM 0xffffd314) with command 7 is present;
  adds u8 affine (scale 0x3b800000 = 1/256, offset 0xbf000000 = −0.5).
  Candidate: service-tool proportional fuel trim.
- `beb0 = beac x bed0` — fuel volume request.

### 0x30948 ref_calculateFuelAmountPerRotationMinMax
- bf18 = f(RPM; tbl_table_2d_182 0x6ac4c); builds per-channel window bounds
  with constants 6e7 (60,000,000 = us/min), 369.472 (0x43b8bc6a) and
  475.93 (0x43edf70a) for the primary/secondary channel families; also
  60000000.0 (0x4c64e1c0), 780525.19 (0x493e8ed3), 514004.41 (0x48fafa8d).
  Timer-unit interpretation of the 369.472/475.93 pair is a candidate.

### 0x2fd3e ref_getInjectorTempBasedMultiplierLookups
- bde4/bde8/bdec = lookup3d(weighted engine temp, load; 0x6a9a4/0x6a9c0/
  0x6a9dc) — primary / secondary-1 / secondary-2 multiplier groupings.

### 0x30030 FUN_00030030
- be4c = clamp(bde4 x be0c x bebc, 1024, f(RPM; tbl 0x6aa9c));
  be50 = clamp(bde8 x be10 x bec0, 0, same max); be54 likewise for bdec.
- 0x30228: cranking pulse products (be58/be5c) when not yet running or in
  crank-decay window (be3c).

### 0x2fea8 ref_injectorPulseTimeArbitrate_crankAddTimer
- Adds be44 (latency) to the per-channel times; crank-decay table 0x6bab0.

### 0x2ff78 ref_getFuelInectorLatencyCals -> 0x86f8 ref_setFuelInjectorLatency
- be44 = lookup3d(MAP-est, battery; tbl_injector_latency_primary 0x6aa80);
  per-channel latency stored at a094[].

### Output timer layer (not re-verified in detail this pass; export-validated)
- 0x8344/0x8814/0x84c6/0x8a68: 6 output records (0x18 stride) at 0xffffa004;
  ATU compare registers; per-injector ISRs 0x59a4–0x59ea set flags and call
  the pulse setter.

## F. Closed/open-loop interaction (existing annotations, re-read)

- `closed_loop_enable_condition` (0x1c13c) and `open_loop_request_condition`
  (0x1f0c4) annotations were re-read and are consistent with this chain: the
  "Closed Loop Fuelling Threshold" tables 0x69d24–0x69d74 compare against
  `engine_load_ffffc0b4` as documented; `DAT_ffffadec` (this review:
  candidate `fuel_target_multiplier_lambda_command`) is where closed-loop
  trim enters the fuel volume request; (adec − 1) x 100 is exported to
  diagnostic RAM 0xffffd0d8 (percent trim candidate).
- `ref_filterFuelVolumeRequest` (0x2f9d0): decel-cut comparison base
  bdc0 = filter(RPM x beb0 x 0.12, coeff 0.75).

## G. Corrections applied in this pass (documentation only)

1. "Kelvin conversion 295/(x+273)" -> "293.0/(x+273)" in
   `decompiled/functions/0001a086_FUN_0001a086.c`,
   `decompiled/firmware_decompiled.c` (line 27952),
   `named/firmware_named.c` (line 27952),
   `source_review/accepted_ram_aliases.tsv` (row ffffaddc).
   Evidence: ROM literal 0x43928000 at 0x1a198 = 293.0 (295.0 would be
   0x43938000; that encoding does not occur in this function).
   No function bodies, names, addresses or ROM bytes changed.
