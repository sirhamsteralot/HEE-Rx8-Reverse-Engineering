# Targeted static review: possible reset at 10,000 RPM

User observation: power cuts, CAN resets, and operation resumes; the user reports
that an ECU reset has been confirmed. The exact running tune is still unknown.

Result: no confirmed reset-causing bug found in this targeted pass. This is not
an exhaustive review or a demonstration that the firmware is safe at that speed.
The original 60E15120_N3J1E ROM was inspected; applicability to a modified tune
is not established. No firmware changes were made.

Findings:

- 0xc3ce sets byte 0xffffa386 when raw RPM 0xffff9f80 reaches 10,000.
  The comparison was checked against SH disassembly and its ROM float literal.
  The identified consumer 0xc8dc selects per-channel bytes from 0x7a750 below
  threshold and 0x7a752 above. Both two-byte tables contain 01 01 in this ROM.
  Thus this selected value does not change at the threshold in the supplied
  image. A modified calibration could differ. The surrounding peripheral
  routine's inherited ignition/knock names are not definitive identification.
- 0x1f6ae uses RPM 0xffffb548 with 10,000/9,800 hysteresis. Bytes 0xffffb1c3
  and 0xffffb1c4 set above 10,000 and clear at/below 9,800; 0xffffb1ce sets
  at/above 10,000 and clears below 9,800. They affect flags 0xffffb152/153/155.
  This is a control-mode transition candidate, not a traced reset request.
- 0x49c5a clears an enable flag at/above 10,000. No direct reset operation
  appears in that routine.
- 0x123da and 0x124d6 compare RPM against 10,000 plus RAM float 0xffffa7ac,
  with 100-unit hysteresis, then change a blending factor. These are not
  necessarily thresholds at exactly 10,000 RPM and are not direct reset calls.
- 0x7fcc calculates speed as 120,000,000 / accumulated period. At 10,000 RPM
  this corresponds to 12,000 period counts, not a zero denominator or obvious
  integer overflow. A zero/corrupt period remains a separate possible failure;
  no path producing it specifically at 10,000 was demonstrated.
- Reset/startup and shutdown-like paths were inspected (0x4e0, 0xd20c,
  0x9e68, 0x4c80). Several contain decompiler warnings and intentional-looking
  terminal loops. They are not evidence of an RPM-triggered hang by themselves.
  Exported calls do not cover every indirect dispatch or asynchronous reset.

Unresolved mechanisms worth distinguishing with measurements:

1. A real reboot caused by watchdog starvation, an exception or supply/reset-pin
   disturbance. High-RPM scheduling pressure is plausible but unmeasured; no
   worst-case execution-time, interrupt-load or stack proof was performed.
2. The user has confirmed a reset, so an ordinary control-mode cut alone is
   insufficient. A control transition or crank-signal fault could still be an
   upstream trigger, but no such causal chain has been demonstrated.
3. A difference between this stock-image calibration and the actual running ROM.

Useful next evidence: exact flashed ROM; whether CAN communications disappear
and a repeatable startup sequence follows; reset-cause state captured before
startup clears it; simultaneous ECU supply/reset-line and crank-signal capture.
Logging loss alone is insufficient to establish a processor reset. Do not
change watchdog servicing or these thresholds merely to conceal the symptom.

Sources: local address-indexed C, SH disassembly and original ROM bytes.
The function names are inherited hypotheses; no hardware execution was performed.


## 2026-09-09: Denso comparison and logger evidence

RX8Defs identifier 0x000c maps through 0x56982 and 0x55484 to RAM 0xffffb548, independently supporting its RPM role. The logger gauge maximum of 10,000 is a UI setting, not an ECU reset threshold.

Assembly at 0x392c writes SR in a return delay slot, a side effect missing from raw C. Caller 0x7188 requests interrupt mask level 11 before a synchronous SCI0 exchange at 0x71ea. The receive-status loop at 0x721e–0x7226 has no software timeout or watchdog service inside it. This is a potential loss-of-progress path, not a demonstrated fault: SCI completion may depend on internal clocking, and a missing external response alone need not hang it. No 10,000 RPM trigger or active-engine watchdog starvation chain has been established. PB15 toggles in 0x31c/0x11cc resemble the external-watchdog idiom in other SH705x projects, but board routing and normal-runtime scheduling still need verification.

See [sources, alias corrections and full evidence](../cross_ecu/README.md).


### Additional source review

Renesas SH7055 application-note section 2.20 corroborates RDRF mask 0x40 and itself uses a blocking wait. The pattern alone is therefore not evidence of a firmware defect. CAN 0x201 RPM encoding at 0x29236 uses 0.25 RPM/count with a normal ceiling of 0xfffe; 10,000 RPM encodes as 40000, within range. This excludes overflow of this particular encoded field at that RPM, not other reset mechanisms. See [source review](../source_review/README.md).
