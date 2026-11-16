# <Subsystem> — subsystem report

Template guidance: the report is organized top-down from human to machine —
parts 1–2 are for anyone, part 3 for engineers, part 4 is the proof. Write the
final report in a purely factual tone: state what the subsystem is and does,
never "findings", never Q&A-style phrasing ("already", "you see"), and do not
carry this template's explanatory scaffolding lines (including this paragraph)
into the final report. Cross-links to related reports go in the proof section
(§4.7), not in the header.

| Date | What changed | Version |
|------|--------------|---------|
| YYYY-MM-DD | Initial report | 1 |

**Applicable ROMs** — the behavior described here is **assumed identical across
all ROM bins until proven otherwise**; a row documents any per-ROM difference
(also detailed in [`docs/investigations/<rom-id>/`](../investigations/README.md),
never re-derived here). List only ROMs actually investigated for this subsystem
(the reference ROM always present) — never add a row asserting shared logic for
a ROM that has not been investigated; the assumption above covers it until
then:

| ROM | ROM specifics | Short one-line description |
|-----|---------------|----------------------------|
| [`60E15120_N3J1E`](../investigations/60E15120_N3J1E/README.md) | reference ROM — all `0x` addresses in this report are from this bin unless a row says otherwise; SHA-256 `<hash from binaries/manifest.csv>`, untouched | <what this subsystem does on this ROM, one line> |

All content in the report is from static analysis of the canonical export
(`reverse-engineered/decompiled/`), the disassembly and the ROM bytes, except
where a section explicitly states otherwise.

## 1. Introduction — what this subsystem is and does

Plain language, no addresses yet: what the subsystem is, what it does for the
car, and what the key numbers mean.

## 2. How it works, step by step

The basic operation in the order it happens, one short paragraph per step.
Use sub-chapters (`## 2.1`, `## 2.2`, …) to explain the relevant subsystems and
logic where required. When the subsystem touches hardware, start with a hardware
setup diagram (ASCII or mermaid) showing the relevant peripherals, terminals and
signals — distinguishing traced pin routing from firmware-level paths. Near the
start of the body, include a structured overview diagram (ASCII or mermaid) of
the subsystem's components and execution order — which tasks/batches run what,
and in what order — so the whole is visible at a glance before the step-by-step
detail. Add further flow charts or breakdown diagrams where they help, and the
calibrated tables when they explain the operation:

## 2.1 <subsystem / logic stage>

```mermaid
flowchart LR
    A[sensor input] --> B[decision] --> C[actuator output]
```

## 2.2 <next subsystem / logic stage>

...

## 3. Technical pseudocode

Only now the machine-level detail: the firmware chain as condensed pseudocode,
each step anchored to its `0x` ROM address.

## 4. Proof — evidence and validation

Everything that backs parts 1–3 lives in this section.

### 4.1 Memory map (mandatory)

Function (ROM address), RAM (`0xffff…`) and ROM table / literal-pool tables.

### 4.2 Labeling applied

Which labels/aliases this report relies on, and where their evidence lives.

### 4.3 Corrections

Corrections to earlier claims, with the evidence that corrected them.

### 4.4 Files

Artifacts this report produced or depends on (label JSONs/TSVs, review
folders, validation records).

### 4.5 Validation

ROM SHA-256, `validation.json` records, dynamic/emulator checks. Validation
proves what it lists — never write "verified working" beyond what a validation
artifact covers.

### 4.6 Limits

What this report does not cover, and what would disprove the shared-logic
assumption for a given ROM.

### 4.7 Related reports

Links to upstream/downstream subsystem reports and per-ROM difference
documents — cross-link here instead of re-deriving their content.
