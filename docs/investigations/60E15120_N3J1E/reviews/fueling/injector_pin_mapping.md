# Injector channel → ATU-II → pin mapping investigation

Question: which firmware injector channel index (the `param_1 & 0xff` of
`injector_pulse_set_channel` 0x8a68 / `injector_channel_disable` 0x85e4, and the
per-channel struct at `0xffffa004 + ch*0x18`) drives which physical injector
(PCM terminals 2M/2J/2G/2D/3A/3D per `hardware/pcm_connections.tsv`)?

All firmware-side links below are verified against the raw ROM
(`60E15120_N3J1E.bin`, SHA-256 a7cd953c…f264f1, untouched) and the disassembly.
The final hop — SH7055 package pin → PCM connector terminal — is board routing
and remains unresolved in this workspace (see [`hardware/README.md`](../../../../architecture/hardware/README.md)).

## 1. Firmware channel → ATU-II channel (verified from ROM)

Per-channel register table at **ROM 0xd7d4**, 3 × u32 per channel
{DCNT8x reg, GR1x reg, TIER8 mask} (register names from
`reference_project/RX8_6.rep/script_stuff/regs_7055_350.csv`):

| fw ch | DCNT (pulse width) | GR1x (start/compare) | TIER8 mask | TSR8/DSTR bit (from wrapper) |
|---|---|---|---|---|
| 0 | DCNT8A 0xfffff640 | GR1A 0xfffff444 | 0x00010000 (bit16) | bit0 (0x0001) |
| 1 | DCNT8C 0xfffff644 | GR1C 0xfffff448 | 0x00040000 (bit18) | bit2 (0x0004) |
| 2 | DCNT8E 0xfffff648 | GR1E 0xfffff44c | 0x00100000 (bit20) | bit4 (0x0010) |
| 3 | DCNT8B 0xfffff642 | GR1B 0xfffff446 | 0x00020000 (bit17) | bit1 (0x0002) |
| 4 | DCNT8D 0xfffff646 | GR1D 0xfffff44a | 0x00080000 (bit19) | bit3 (0x0008) |
| 5 | DCNT8F 0xfffff64a | GR1F 0xfffff44e | 0x00200000 (bit21) | bit5 (0x0020) |

TSR8/DSTR bits come from the six wrapper thunks **0x59a4/0x59b2/0x59c0/0x59ce/
0x59dc/0x59ea** (delay-slot `mov #imm,r4` = channel param, then `jmp 0x8340` →
0x8a68; each first writes `~bit` to **ATUII_TSR8_W 0xfffff66a** — read-then-
write-0-to-clear idiom): 0x59a4→ch0 (0xfffe), 0x59b2→ch3 (0xfffd),
0x59c0→ch1 (0xfffb), 0x59ce→ch4 (0xfff7), 0x59dc→ch2 (0xffef), 0x59ea→ch5
(0xffdf). The TSR8 bit order matches the DCNT letter order (bit0=8A … bit5=8F),
so the two sources agree. The wrappers' literal pools sit at ROM 0x2ca8+
(stride 0x18) inside the stub block 0x29f8–0x3238.

So each firmware channel is the ATU-II **8x/1x pair**: ch0→8A/1A, ch1→8C/1C,
ch2→8E/1E, ch3→8B/1B, ch4→8D/1D, ch5→8F/1F. Pulse = (latency a094[ch] +
fuel request a010[ch]) >> 4 written to DCNT8x via FUN_0000a8a4; start angle
a014[ch] to GR1x; channel armed via ATUII_DSTR_W.

## 1b. ATU-II 8x → SH7055F package pins (from the supplied `Sh7055h.pdf`, SH7055F Hardware Manual ADE 602-155B)

- Table 1.2/1.3 (Pin Functions / Pin Assignments): channel-8 down-counter
  one-shot pulse outputs are **TO8A–TO8P**. On port K (PK0–PK15) they sit on
  package pins **195, 197, 198, 199, 200, 201, 202, 204, 206–211, 213, 215**
  (PK0/TO8A=195, PK1/TO8B=197, PK2/TO8C=198, PK3/TO8D=199, PK4/TO8E=200,
  PK5/TO8F=201, …). On port B they would be pins 151–158 (PB4/TO8A=151 …
  PB11/TO8H=158), but the firmware does not select that route (below).
- The manual also confirms the firmware pattern: channel 1's output compare
  register "can be selected for one-shot pulse offset in combination with the
  channel 8 down-counter" — exactly GR1x (offset/start) + DCNT8x (width) →
  pulse on TO8x.
- **Running pin-function config (firmware fact):** `ref_setRegisters`
  (0x4d2e, from mainInit 0x61a8) → FUN_000051c8 sets `PKCRL_W = 0x5555`, i.e.
  PK0–PK7 mode = 1 = **TO8A–TO8H** (PKCR bit table §20.3.21: PK0MD=1 →
  "ATU-II one-shot pulse output TO8A"). PBCRL=0x4000 sets only PB7=TO7D (PWM),
  so the PB route (pins 151–156) is not used for channel 8 in the running
  configuration. (A second init path, 0x50aa via 0x4c80←0x9e68, clears the PK
  control registers — different mode; the main-init path wins.)

Combined chain (firmware ch → ATU-II 8x/1x → TO8x → package pin):

| fw ch | ATU-II | TO8 pin | SH7055F pkg pin | rotor block |
|---|---|---|---|---|
| 0 | 8A/1A | TO8A | **195** | 0 (channels 0-2) |
| 1 | 8C/1C | TO8C | **198** | 0 |
| 2 | 8E/1E | TO8E | **200** | 0 |
| 3 | 8B/1B | TO8B | **197** | 1 (channels 3-5) |
| 4 | 8D/1D | TO8D | **199** | 1 |
| 5 | 8F/1F | TO8F | **201** | 1 |

## 2. Rotor (front/rear) assignment (verified from ROM)

`ref_fuelingArrayInit_` (0xf37c) builds two 0x58-byte queue blocks at RAM
0xffffa4b4 and fills the three queue entries of each block with channel ids
from **ROM 0x4e2c8**: block 0 → channels **[0, 1, 2]**, block 1 → channels
**[3, 4, 5]**. The block index (0/1) is stored at queue+0xc0 (0xffffa4c0) and
rotates with the 12-phase ATU window counter in `FUN_0000f4d8` (param_1 0..0xb).
So **channels 0-2 fire for one rotor, channels 3-5 for the other** (each rotor
has primary-1, primary-2, secondary = 3 injectors, matching the 6 harness
circuits). Which block is front vs rear is a physical convention not
decidable from firmware alone — candidate: block 0 = the rotor reported as
rotor 0 by `ref_getRotorNumberForControl_`.

## 3. Primary vs secondary within a block (partially traced)

Per-injector-type pulse requests are computed in 0x30030 from the three
injector temp multipliers: `be4c` = primary (bde4), `be50` = secondary-1
(bde8), `be54` = secondary-2 (bdec), each clamped to tbl 0x6aa9c(rpm). They
are distributed into the queue entries (entry +0xc fuel request, consumed by
0xf0dc/0xfcfe → 0x84c6 → a010[ch]); cranking (0xffd6) fires all three entries
of the active block. The exact entry-order → injector-type assignment within a
block is not fully traced; the fuel-cut flag table ROM 0x4e2ce marks entry 0 of
each block (channels 0 and 3) with flag 1 — candidate "primary-1" markers.

## 4. Harness side (from `hardware/pcm_connections.tsv`, documented wiring)

| Component | PCM terminal | Connector |
|---|---|---|
| Front primary injector 1 | 2M | B1-29 |
| Rear primary injector 1 | 2J | B1-30 |
| Front secondary injector | 2G | B1-31 |
| Rear secondary injector | 2D | B1-32 |
| Front primary injector 2 | 3A | B1-33 (high power) |
| Rear primary injector 2 | 3D | B1-34 (high power) |

## 5. Result and limits

- **Established (firmware + supplied manual):** fw ch → ATU-II 8x/1x pair →
  TO8x → **SH7055F package pin** (195/197/198/199/200/201 for ch0/3/1/4/2/5),
  plus TSR8/DSTR/TIER8 bits, wrapper thunks, per-channel RAM struct, rotor
  block split ({0,1,2}/{3,4,5}), and the running PFC config (port K, not
  port B). Sources: ROM tables 0xd7d4 / 0x4e2c8 / 0x5a70-0x5aa4, wrappers
  0x59a4-0x59ea, `ref_setRegisters`→0x51c8 (PKCRL=0x5555), and
  `Sh7055h.pdf` Tables 1.2/1.3 + §20.3.21 (PKCR) + ATU-II chapter (channel 8
  one-shot pulse output, GR1x as one-shot offset with DCNT8x).
- **Not established:** package pin → PCM connector terminal (2M/2J/2G/2D/3A/
  3D) — that is board routing ([`hardware/README.md`](../../../../architecture/hardware/README.md) lists it as unresolved;
  external ECU pinout pages are 403-blocked). So the fw-channel → terminal table is **candidate-only**
  until a board trace or an accessible Denso RX-8 PCM pinout confirms which
  of pins 195/197-201 land on which terminal.
- No ROM, def or wiring data was modified; this file is analysis output only.

## 6. What this resolves in the fueling control

- **Per-rotor fueling:** the injection schedule is two rotor blocks
  (queue at 0xffffa4b4, 0x58-byte blocks); block 0 fires fw channels {0,1,2}
  (pins 195/198/200), block 1 fires {3,4,5} (pins 197/199/201). This matches
  the per-rotor knock sensing (knock_rotor_index alternates 0/1 per ATU
  window in 0xc8dc) — fuel and knock are both rotor-indexed.
- **Staging slots:** 0x30030 computes per-type pulse requests from the three
  injector temp multipliers: be4c = primary (tbl 0x6a9a4), be50 = secondary-1
  (0x6a9c0), be54 = secondary-2 (0x6a9dc). 0x2fea8 then forms
  be24 = be28 = be4c + latency be40 — and be24 is exactly what PID 0x1410
  "Injector Pulse Time" reports — so **the logged pulse time is the primary
  injector's**. be30/be38 = be50/be54 + latency be44 (secondary-1/2 slots);
  be2c/be34 mirror them. (Readers of be2c/be30/be34/be38 are not visible in
  the export — open.)
- **Primary-1 marker:** the fuel-cut flag table ROM 0x4e2ce = [1,0,0] per
  block, so queue entry 0 — fw channels **0 and 3** — is the flagged channel
  of each rotor (candidate: always-on primary-1; consistent with the
  cranking path 0xffd6 firing all three entries of the active block).
- **Secondary-enable gates:** 0x30b08 computes bf36/bf37 against
  tbl 0x6ac74 / 0x6ac60 "Secondary Injectors Allowed Threshold - Coolant
  Temperature Based"(coolant) — consumers of bf36/bf37 are not identified in
  this export (open).

## 7. FSM pinout cross-check

The supplied pinout PDF (generated from the 13B electrical book / official FSM
PCM terminal table) gives **terminal → function** with FSM names. It contains
**no chip-pin numbers**, so it does not close the package-pin → terminal hop
by itself; it confirms the harness side and adds the FSM injector naming:

| Terminal | FSM function (pinout PDF) | Markers |
|---|---|---|
| 2M | Fuel injector (Front Primary 1) control | — |
| 2J | Fuel injector (Rear Primary 1) control | — |
| 2G | Fuel injector (Front Secondary) control | color * provisional |
| 2D | Fuel injector (Rear Secondary) control | color conflict † |
| 3A / 3D | Fuel injector (Front/Rear Primary 2) control | ³ high-power only; connector-3 illegible at render resolution |
| 1L / 1D | SSV control / SSV switch | — / color * |
| 1O | AIR control (AIR solenoid valve) | color * |
| 1W | VDI control | — |
| 5Z | VFAD control | ³ high-power only |
| 2P | Purge solenoid valve control | — |
| 3B / 3G / 3J / 1S | APV opening angle / motor (+)/(−) / position sensor power | ³ high-power only |

Combined chain (firmware → chip → harness), with the board hop marked:

```
fw ch → ATU-II 8x/1x → TO8x → SH7055F pkg pin (Sh7055h.pdf) ‖ terminal → FSM component (pinout PDF)
ch0 → 8A/1A → TO8A → pin 195 ‖ 2M=Front Primary 1, 2J=Rear Primary 1, 2G=Front Secondary,
ch1 → 8C/1C → TO8C → pin 198    2D=Rear Secondary, 3A/3D=Primary 2 (HP)
ch2 → 8E/1E → TO8E → pin 200 ‖  (rotor block 0 = ch{0,1,2}, block 1 = ch{3,4,5}, ROM 0x4e2c8)
ch3 → 8B/1B → TO8B → pin 197 ‖  ch0/ch3 = queue entry 0 per block (fuel-cut flag ROM 0x4e2ce,
ch4 → 8D/1D → TO8D → pin 199    candidate primary-1)
ch5 → 8F/1F → TO8F → pin 201 ‖  [pkg pin ↔ terminal] = BOARD ROUTING — unresolved
```

Scepticism notes (per the PDF's own caveats): it is generated from 13B
electrical renders; connector 3 (3A/3B/3D/3G/3J) was not legible; colors marked
*/† are single-source or conflicting; ³ pins are high-power-only. Terminal→
function comes from the FSM terminal table (strong), but no source available
here maps SH7055 package pins to connector terminals — that hop needs a board
trace or an ECU pinout database (ecu.design page for the Denso SH7055 RX-8
was 403-blocked from this environment).

Cross-check discrepancy noted: the reference project's `vars.h`
(equinox311/RX8_FlexFuel) names 0xffffbea8/0xffffbeac "primary/secondary
fuel injector pulse cranking"; in this ROM's disassembly 0x306e8 writes
beac = FUN_0005c024(bf14) and beb0 = beac*bed0 (fuel volume scaled/final), and
the cranking pulses live at be58/be5c (0x2fea8). Our disasm-derived labels
stand; the reference names appear misassigned.

## 8. Wire colours (FSM pinout cross-check)

The FSM pinout ([`mazda-rx-8-pcm-pinout-series-1.md`](../../../../architecture/hardware/mazda-rx-8-pcm-pinout-series-1.md))
resolves wire colours for every used terminal except 5L/5Z (FSM terminal table +
wiring-book reads; unmarked = confirmed, * = single-source, † = conflict, ³ = high-power
only) and one topology fact: **each injector also has a shared W/L +12 V power
feed** — the PCM switches the low side (TO8A–F, pkg pins 195/197–201), which
matches the firmware driving one side per channel. Terminal→function matches §7.
Control-wire colours:

| Terminal | FSM function | Wire colour | Marker |
|---|---|---|---|
| 2M | Front Primary 1 | LG/R | confirmed |
| 2J | Rear Primary 1 | LG/B | confirmed |
| 2G | Front Secondary | G/R | confirmed |
| 2D | Rear Secondary | L/B | confirmed |
| 3A | Front Primary 2 | L/B | ³ HP-only |
| 3D | Rear Primary 2 | W/G | ³ HP-only |
| 1L | SSV | L/Y | confirmed |
| 1W | VDI | L/B | confirmed |
| 3J | APV (motor −) | L/R | confirmed |
| 1S | APV position sensor Vref | R/W | |
| 3B | APV position sensor signal | R/G | ³ |
| 3G | APV (motor +) | G/B | ³ |
| 2P | purge | R/Y | * |
| 5Z | VFAD | unread | — |

Applied to the decompiled sources: `hardware/pcm_connections.tsv` carries the
`wire_colour` column, `hardware/firmware_annotations.tsv` holds the actuator rows,
and the `[WIRING REVIEW …]` blocks in all synchronized views
(per-function files, `firmware_decompiled.c`, `firmware_named.c`) match (marker
kept so a Ghidra rebuild reproduces them). Still unresolved: the package-pin ↔
terminal hop (board routing — the pinout has no chip-pin data), and the VFAD
(5Z) wire colour remains unread (the purge 2P is R/Y *).
