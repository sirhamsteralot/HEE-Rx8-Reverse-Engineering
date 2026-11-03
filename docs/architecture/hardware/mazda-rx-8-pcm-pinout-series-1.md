# Mazda RX-8 PCM Pinout — What Each Pin Connects To

> **Source:** text-based PCM-connector pinout derived by visual reading of
> `../references/13Electrical.pdf` (**ground truth for the RX-8 electrical
> systems** — the copy-protected wiring book, 148 pages) plus the FSM terminal
> table. When this file is updated, re-diff and
> propagate changes into `pcm_connections.tsv` (`wire_colour`),
> `firmware_annotations.tsv`, and the `[WIRING REVIEW]` blocks in the
> synchronized C views. This document has **no chip-pin numbers** —
> package-pin ↔ connector-terminal is board routing, unresolved.

**Vehicle:** Mazda RX-8 (Series 1, 13B-MSP RENESIS) · **Module:** PCM (Powertrain Control Module), connector **B1-01** in the wiring book, located right-front of the engine compartment.

The PCM has **five connectors**: terminals 1A–1Z, 2A–2AD, 3A–3Z, 4A–4Z and 5A–5AF. Signal and connection data come from the official Mazda FSM PCM terminal table; every wire colour was read from the *RX-8 Electrical* wiring book's circuit diagrams and connector views, then cross-confirmed.

**Status:** wire colour is resolved for **every used terminal except 5L**. Unmarked colours are confirmed (≥2 agreeing, independent reads); **\*** = single-source (verify before use); **†** = conflicting (candidates in the notes). See *Limits* at the end for exactly how far this table can be trusted.

## How to read the tables

Mazda colour codes: **B** Black · **W** White · **R** Red · **G** Green · **L** Blue · **Y** Yellow · **LG** Light Green · **GY** Gray · **N** Natural · **V** Violet · **BR** Brown · **P** Pink. A slash is the tracer (e.g. **R/B** = black wire, red tracer).

| Marker, in the "Wire colour" column | Meaning |
| --- | --- |
| — *(Signal / Connects to)* | Terminal not used / not equipped (per FSM terminal table) |
| no marker | Colour confirmed by at least two agreeing, independent reads |
| **\*** | Colour readable in only one source — treat as provisional |
| **†** | Reads conflict; leading candidate shown, alternatives in the notes |
| – | No legible colour in any source (all such pins are listed in the notes) |

## PCM Connector 1 (terminals 1A–1Z)

| Pin | Signal / circuit | Connects to | Wire colour |
| --- | --- | --- | --- |
| 1A | — | — | – |
| 1B | Throttle control (+) | Throttle body (Throttle valve actuator) | R/B |
| 1C | Throttle control (-) | Throttle body (Throttle valve actuator) | R |
| 1D | SSV switch | SSV switch | L |
| 1E | — | — | – |
| 1F | Knock sensor (-) | Knock sensor | Y/B |
| 1G | Shield | — | B |
| 1H | — | — | – |
| 1I | — | — | – |
| 1J | Throttle valve opening angle No. 1 | Throttle body (TP sensor) | G/R |
| 1K | — | — | G * |
| 1L | SSV control | SSV solenoid valve | L/Y |
| 1M | Throttle valve opening angle No. 2 | Throttle body (TP sensor) | B/L |
| 1N | — | — | – |
| 1O | AIR control | AIR solenoid valve | R/L |
| 1P | — | — | – |
| 1Q | TP sensor power supply | Throttle body (TP sensor) | G * |
| 1R | — | — | – |
| 1S | APV position sensor Vref (constant voltage) ³ | APV motor (APV position sensor) | R/W |
| 1T | Knock sensor (+) | Knock sensor | Y/R |
| 1U | Sensor GND | ECT sensor, rear HO2S, metering oil pump switch, APV position sensor | BR |
| 1V | Front HO2S heater control | Front HO2S heater | L/O |
| 1W | VDI control | VDI solenoid valve | L/B |
| 1X | — | — | BR |
| 1Y | — | — | – |
| 1Z | — | — | – |

## PCM Connector 2 (terminals 2A–2AD)

| Pin | Signal / circuit | Connects to | Wire colour |
| --- | --- | --- | --- |
| 2A | Rear HO2S heater control | Rear HO2S heater | R |
| 2B | Front HO2S | Front HO2S | V |
| 2C | Front HO2S | Front HO2S | P |
| 2D | Fuel injector **(Rear Secondary)** control | Fuel injector (Rear Secondary) | L/B |
| 2E | Oil pressure switch | Oil pressure switch | LG |
| 2F | TP sensor GND | Throttle body (TP sensor) | G/Y |
| 2G | Fuel injector **(Front Secondary)** control | Fuel injector (Front Secondary) | G/R |
| 2H | Shield | — | B |
| 2I | Field coil control | Generator (D terminal) | BR/R * |
| 2J | Fuel injector **(Rear Primary 1)** control | Fuel injector (Rear Primary 1) | LG/B |
| 2K | ECT sensor | ECT sensor | G/W |
| 2L | — | — | – |
| 2M | Fuel injector **(Front Primary 1)** control | Fuel injector (Front Primary 1) | LG/R |
| 2N | Metering oil pump switch | Metering oil pump (Metering oil pump switch) | B/Y |
| 2O | Neutral switch ¹ | Neutral switch | L/R |
| 2P | Purge solenoid valve control | Purge solenoid valve | R/Y * |
| 2Q | Rear HO2S | Rear HO2S | Y |
| 2R | Oil-level switch | Oil-level switch | R/W |
| 2S | — | — | – |
| 2T | Generator output voltage | Generator (Terminal P) | W/G |
| 2U | Eccentric shaft position sensor (+) | Eccentric shaft position sensor | Y/B * |
| 2V | Metering oil pump control 3 | Metering oil pump | L/Y |
| 2W | Metering oil pump control 1 | Metering oil pump | B/O |
| 2X | Eccentric shaft position sensor (-) | Eccentric shaft position sensor | Y/R |
| 2Y | Metering oil pump control 4 | Metering oil pump | R/G |
| 2Z | Ignition coil (L/R) control | Ignition coil | Y/G |
| 2AA | Ignition coil (L/F) control | Ignition coil | G |
| 2AB | Metering oil pump control 2 | Metering oil pump | B/L |
| 2AC | Ignition coil (T/R) control | Ignition coil | L/O |
| 2AD | Ignition coil (T/F) control | Ignition coil | W |

## PCM Connector 3 (terminals 3A–3Z)

| Pin | Signal / circuit | Connects to | Wire colour |
| --- | --- | --- | --- |
| 3A | Fuel injector **(Front Primary 2)** control ³ | Fuel injector (Front Primary 2) ³ | L/B |
| 3B | APV opening angle ³ | APV motor (APV position sensor) | R/G |
| 3C | — | — | – |
| 3D | Fuel injector **(Rear Primary 2)** control ³ | Fuel injector (Rear Primary 2) ³ | W/G |
| 3E | — | — | – |
| 3F | — | — | – |
| 3G | APV motor control (+) ³ | APV motor | G/B |
| 3H | — | — | – |
| 3I | — | — | – |
| 3J | APV motor control (-) ³ | APV motor | L/R |
| 3K | — | — | – |
| 3L | — | — | – |
| 3M | — | — | – |
| 3N | — | — | – |
| 3O | — | — | – |
| 3P | — | — | – |
| 3Q | — | — | – |
| 3R | — | — | – |
| 3S | — | — | – |
| 3T | — | — | – |
| 3U | — | — | – |
| 3W | — | — | – |
| 3X | — | — | – |
| 3Y | — | — | – |
| 3Z | — | — | – |

## PCM Connector 4 (terminals 4A–4Z)

| Pin | Signal / circuit | Connects to | Wire colour |
| --- | --- | --- | --- |
| 4A | GND | GND | B |
| 4B | — | — | – |
| 4C | Drive-by-wire relay control | Drive-by-wire relay | W/B |
| 4D | — | — | – |
| 4E | Main relay control | Main relay | G/Y |
| 4F | Clutch switch ¹ | Clutch switch | V |
| 4G | — | — | – |
| 4H | — | — | R/L * |
| 4I | — | — | – |
| 4J | GND | GND | B |
| 4K | BARO sensor Vref (constant voltage) | BARO sensor | B/L |
| 4L | — | — | – |
| 4M | Fuel pump speed control | Fuel pump speed control relay | LG |
| 4N | — | — | – |
| 4O | AIR pump control | AIR pump relay | L/R * |
| 4P | Brake switch ⁷ | Brake switch | R/G |
| 4Q | IG1 | Ignition relay | B/W |
| 4R | — | — | – |
| 4S | CAN_L | — | G/B |
| 4T | Coolant level switch | Coolant level switch | V/W |
| 4U | Sensor GND | MAF sensor, BARO sensor, IAT sensor | B/G |
| 4V | CAN_H | — | L/W |
| 4W | A/C control | Refrigerant pressure switch (high pressure and low pressure) | LG/B |
| 4X | APP sensor 2 power supply | APP sensor | R/Y |
| 4Y | APP sensor 1 power supply | APP sensor | G/R |
| 4Z | A/C load | Refrigerant pressure switch (medium pressure) | R/B |

## PCM Connector 5 (terminals 5A–5AF)

| Pin | Signal / circuit | Connects to | Wire colour |
| --- | --- | --- | --- |
| 5A | Starter relay ¹⁰ | Starter relay | W/G |
| 5B | — | — | – |
| 5C | APP sensor 2 | APP sensor | R/W |
| 5D | GND | GND | B |
| 5E | — | — | – |
| 5F | APP sensor 1 | APP sensor | W/R |
| 5G | — | — | – |
| 5H | Drive-by-wire relay control | Drive-by-wire relay | L |
| 5I | — | — | L * |
| 5J | Backup power supply (KAM) | Battery | L/R |
| 5K | IAT sensor | MAF/IAT sensor | R/B |
| 5L | Fuel pump relay control ¹¹ | Fuel pump relay | – |
| 5M | — | — | – |
| 5N | MAF sensor | MAF sensor | Y/R |
| 5O | GND | GND | B |
| 5P | Fuel pump relay control ¹⁰ | Fuel pump relay | L/B |
| 5Q | — | — | – |
| 5R | GND | GND | B |
| 5S | BARO sensor | BARO sensor | B/R |
| 5T | GND | GND | B/O & B/R |
| 5U | MAF sensor GND | MAF sensor | B/W |
| 5V | Cruise control switch ⁵ | Cruise control switch | G/Y |
| 5W | ECT (A/C unit) | A/C unit | R/L |
| 5X | Electrical fan control | Cooling fan relay | R/G |
| 5Y | — | — | – |
| 5Z | VFAD control ³ | VFAD solenoid valve | O |
| 5AA | A/C relay | A/C relay | G/B |
| 5AB | APP sensor GND 2 | APP sensor | LG/B |
| 5AC | Power supply | Main relay | B/L |
| 5AD | Electrical fan control | Cooling fan relay | L/W |
| 5AE | APP sensor GND 1 | APP sensor | GY |
| 5AF | Power supply | Main relay | B/L |

## Footnotes (option / transmission dependent)

| Marker | Applies to |
| --- | --- |
| ¹ | MT (manual transmission) |
| ² | AT (automatic transmission) |
| ³ | 13B-MSP (High Power) engine |
| ⁴ | 13B-MSP (Standard Power) engine |
| ⁵ | With cruise control system |
| ⁶ | Without cruise control system |
| ⁷ | With cruise control system and DSC |
| ⁸ | Without cruise control system and DSC |
| ¹⁰ | With immobilizer system |
| ¹¹ | Without immobilizer system |

## Wire colour notes

**Shared feeds and grounds** (confirmed on the component connectors):
- All six fuel injectors share a **W/L** power feed; the PCM pins are the ground-side controls.
- All four ignition coils share a **B/W** power feed (pin C) and a **B** ground (pin B); pin A is the PCM control. Coils: Leading Front B1-07, Trailing Front B1-08, Leading Rear B1-09, Trailing Rear B1-10.
- **W/R** is the switched feed common to the HO2S heaters, the SSV solenoid, the AIR solenoid and the metering oil pump motor.
- **BR** is the shared sensor ground (**1U**) at the ECT sensor, metering oil pump switch, rear HO2S and APV position sensor.
- Throttle body (B1-19, six wires): actuator **1B R/B / 1C R**, TP signals **1J G/R / 1M B/L**, TP ground **2F G/Y**, TP power **1Q G**.
- APV assembly (B1-37, five wires): motor **3G G/B** (+) / **3J L/R** (−), position sensor **3B R/G** (signal), **1S R/W** (Vref), **1U BR** (ground).
- CAN bus: **4S = G/B** (CAN_L) / **4V = L/W** (CAN_H), the same twisted pair that runs to the instrument cluster, ABS/DSC HU/CM, EPS control module, keyless control module, TPMS module and the data link connector.

**† Conflict resolutions:**
- **5T** — **B/O & B/R** (two wires). The circuit diagram prints *B/O & B/R (F)* on terminal 5T: two separate ground wires spliced together before entering the single PCM terminal. (A plain-B read is spillover from adjacent GND terminals 5O/5R, both plain B, confirmed by the same diagram.)
- **4C** — **W/B**. The drive-by-wire (ETV) relay circuit diagram (B1-02) shows W/B (F) on the relay-coil wire ending at PCM 4C, confirmed on two independent reads.
- **4K** — function **Vref (constant voltage)**: the BARO sensor circuit diagram labels the B/L wire to 4K as *CONSTANT VOLTAGE (Vref)*. The same diagram confirms 5S = B/R (signal) and 4U = B/G (ground).
- **5Z** — colour **O**. The VFAD solenoid circuit diagram (B1-15) shows the O (F) wire terminating at PCM 5Z on two agreeing reads; the companion B/L (F) wire is the feed side.
- **1O** — **R/L**. The AIR solenoid circuit diagram (connector B1-23: control wire R/L, feed W/R) traces the R/L wire unambiguously to PCM 1O.
- **1S** — function **Vref (constant voltage)**: the APV circuit diagram (B1-37) labels the R/W wire to 1S as *CONSTANT VOLTAGE (Vref)*.
- **2A** — **R**. The rear HO2S circuit diagram (B1-28) shows solid R on the heater-control terminal 2A, with W/R as the switched feed to the heater element on the other side (never reaching the PCM). Signal Y → 2Q and ground BR → 1U match the table.

**\* Single-source entries (the complete list):** 1K = G · 1Q = G · 2I = BR/R · 2P = R/Y · 2U = Y/B · 4H = R/L · 4O = L/R · 5I = L. Of these, 1Q, 2P, 2U and 4F/4T-style entries were cross-checked against component connectors; 1K, 5I sit on pins the FSM lists as unused.

**Used pins with no colour found:** **5L** (fuel pump relay, without-immobilizer variant) — not legible in any available source. The wiring book marks 5L with an asterisk (option/variant marker) and shows the line ending unlabelled, consistent with it being populated only on non-immobilizer cars.

**Pins listed as unused (—):** the FSM PCM terminal table may not document every populated terminal. Wires were intermittently glimpsed near several unused pins — 1A (B or L/B), 1N (B/L or Y/R), 2L (V or G/W), 3E/3M/3R (R/G, L/R — offset reads of neighbours 3B/3J), 4D (Y/B, read twice), 4G (R/L or L/G), 4B, 4I, 4L, 4N, 4R — but those label attributions proved unstable, so no colour is recorded for them. Only 1K, 1X and 5I gave consistent reads on unused pins and are shown (1X = BR across four agreeing passes).

## Limits — how far this table can be trusted

1. **Extraction method.** The wiring-book PDF is copy-protected against text/vector extraction, so every colour code was read visually from rendered page images and user-supplied screenshots — not copied from digital text. Typos in the codes are therefore possible in principle.
2. **Confirmation rule.** *Unmarked* = at least two agreeing, independent reads (e.g. circuit diagram + component connector, or view + close-up), or a single unambiguous read on a zoomed, named connector that also passes a logic check (GND = plain B, sensor pairs sharing a base colour). *** = one readable source only. *†* = sources disagree. No colour was left unmarked on the strength of a single connector-view pass alone.
3. **Known weak spots.** The B1-01 connector-view drawing has tiny pin labels that occasionally shift by one position between reads — all colour assignments that relied on it were cross-checked against a circuit diagram or a component close-up. Mirrored code pairs such as **5C = R/W vs 5F = W/R** were recorded exactly as printed but could not be independently re-verified: double-check mirrored pairs on the harness.
4. **Unresolved items.** The eight single-source (\*) entries and 5L (no colour found), plus the unused-pin attributions listed above. 4C (W/B), 5T (B/O & B/R) and 5Z (O) were †/gap entries until resolved by circuit diagrams during review.
5. **Applicability.** Series 1 RX-8 (13B-MSP RENESIS). Option- and transmission-dependent circuits are marked with the footnotes above; wire colours can vary with market, build date and harness revision. **Confirm against the actual car's harness before cutting, splicing, or wiring an aftermarket/standalone ECU.**
6. **Scope.** Pin functions and connections are from the FSM terminal table; colours are from the *RX-8 Electrical* wiring book. This document contains no electrical values — reference voltages and waveforms are in the FSM *PCM INSPECTION* terminal voltage table.

## Reference

- **Harness symbols** in the wiring book: **(F)** = Front harness, **(E)** = Engine harness, **(R)** = Rear harness.
- **Fuel injector naming:** the RX-8 has two rotors (front and rear), each fed by one **Primary** and one **Secondary** injector; High-Power (6MT) cars add a second primary per rotor. Pin assignment: **2J = Rear Primary 1, 2M = Front Primary 1, 2D = Rear Secondary, 2G = Front Secondary**; second primary pair (High Power only): **3A = Front Primary 2, 3D = Rear Primary 2**. Control-wire colours: **2M LG/R, 2J LG/B, 2G G/R, 2D L/B, 3A L/B, 3D W/G**.
- Injector connectors: B1-29 Front Primary 1, B1-30 Rear Primary 1, B1-31 Front Secondary, B1-32 Rear Secondary, B1-33 Front Primary 2, B1-34 Rear Primary 2.

**Source:** Official Mazda RX-8 FSM, *PCM INSPECTION* terminal voltage table (Series 1), as hosted on the Foxed.ca RX-8 FSM archive; wire colours from the *RX-8 Electrical* wiring book, cross-checked against the *Engine Diagnostics & Control* FSM PDF.