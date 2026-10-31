# Denso comparison and RX8Defs correlations

**Integration update:** These names and review comments are now included in
`decompiled/firmware_decompiled.c` and individual function files. Earlier statements
below about a separate named view or unchanged raw C describe the pre-integration
state. The saved Ghidra database remains unchanged. See `metadata/integrated_names.json`.

Reviewed 2026-09-09 against the stock 60E15120 ROM. This extension adds evidence-backed comments and proposed aliases to the exported analysis C. It does not modify the ROM or rename symbols in the saved Ghidra database. Definitions are community interpretations, not recovered Mazda source names.

## Results from local RomRaider definitions

`correlate_rx8defs.py` resolves target 60E15120 and its base definition (case-insensitive `Rx8Base` → `RX8Base`). It matches ROM descriptors using the defined data address, axis addresses and element counts, rather than relying on a nearby label.

- **478 descriptor matches**, including **128 with descriptive names**. The remaining entries retain generic `Table ...` names. See [full descriptor matches](romraider_descriptor_matches.json).
- **15 of 22 logger entries match 14 distinct handlers** in the recovered diagnostic dispatch table. Two entries conflict over identifier `0x1410`: Injector Pulse Time and Throttle Pedal Position. Neither meaning is adopted. Seven entries are absent from this recovered table; absence does not prove no implementation elsewhere. See [all logger results](romraider_logger_matches.json).
- **13 diagnostic alias candidates** and **11 RAM meaning candidates**, supported by handler-to-reader dataflow in the C export. See [function aliases](romraider_function_aliases.tsv) and [RAM candidates](romraider_ram_candidates.tsv). The XML addresses such as `0x22000C` encode a diagnostic request, not a RAM address.

A concrete table example is descriptor **0x68fa8**, whose data at **0x6c4ac** is named **Off Throttle Fuel Cut - Fuel Resume - In Gear Threshold**. Its 16 coolant-temperature entries and six gear entries match the descriptor's axes and counts. The ROM multiplier is 25 RPM per stored byte, agreeing with the base definition. This lets us identify references to the descriptor as well as references directly to calibration storage. The two other layout examples at 0x69dd8 and 0x69dec match generic Tables 2D 101 and 102, so their purpose remains unknown.

The engine-speed request identifier **0x000c** selects handler **0x56982**, which calls **0x55484**, reading **0xffffb548**. The conversion scalar is 0.25, matching the logger's RPM decoding. This independently supports the RPM interpretation already used in the 10,000 RPM review. Other candidates include coolant temperature at 0xffff9f70, knock retard at 0xffffa734 and leading/trailing timing at 0xffffa630/0xffffa638. These remain interpretation labels; units and behavior across every producer have not all been independently verified.

The logger file also contains duplicate parameter IDs, a conflicting 0x1410 definition, and flex-fuel entries absent from the recovered table. Its gauge maximum of 10,000 RPM is a display setting, not evidence of an ECU limit or reset trigger. The ROM's secondary ID N3ZHE still differs from the N3J1E filename/definition identification; variant-dependent interpretations remain provisional.

## What other Denso efforts contribute

**Descriptor structure:** ScoobyRom's Denso parsers document 12/20-byte 2D and 20/28-byte 3D records, with counts, axis/data pointers and optional scaling. Their offsets match our lookup routines at 0x2068 and 0x20dc and the three inspected ROM examples. This provides a structural basis for the larger RX8Defs correlation, without importing Subaru calibration meanings. Sources: [Table2D.cs](https://github.com/aalesv/ScoobyRom/blob/main/LibScoobyRom/Tables/Table2D.cs), [Table3D.cs](https://github.com/aalesv/ScoobyRom/blob/main/LibScoobyRom/Tables/Table3D.cs). An original C schema is in [denso_table_layout.h](denso_table_layout.h); it describes file offsets, not a host-endian memory cast.

**External watchdog pattern:** npkern explicitly services an external watchdog by toggling a configurable GPIO. Our 0x31c and 0x11cc toggle PBDR bit 15 after handling a WDT status event. That is a plausible watchdog heartbeat pattern, but does not prove the external chip, connector route, or running-engine service schedule. Source: [npkern watchdog implementation](https://github.com/fenugrec/npkern/blob/master/wdt.c). The [RX-8 author's recovery guide](https://www.rx8club.com/series-i-engine-tuning-forum-63/open-source-s1-rx-8-ecu-reverse-engineering-data-logging-tuning-users-guide-276137/) also describes an externally supplied watchdog signal during recovery. Recovery timing must not be assumed to be normal firmware timing.

**Automated symbol suggestions:** [ScoobyTables](https://github.com/aalesv/ScoobyTables) uses table features for predicted annotations. A similar approach could rank unknown RX-8 tables, preferably using close RX-8 ROMs as references. Predictions are candidates; shared shapes alone cannot establish ignition, fuel or load semantics.

**Architecture references:** [FastECU](https://github.com/miikasyvanen/FastECU) and [npkern](https://github.com/fenugrec/npkern) provide useful SH705x flashing/peripheral examples. Their transport kernels are not the production RX-8 control application. Addresses, pin assignments and application symbols must not be copied across ECU families. The existing [RX-8 reverse-engineering repository](https://github.com/equinox311/Mazda_RX8_PCM_ReverseEngineering) already supplies our reference ROM labels; those labels are not an independent second confirmation.

## Corrections and reset investigation

The [nine cross-project/assembly alias proposals](symbol_aliases.tsv) include two important corrections to the C interpretation:

- **0x3920 changes the SH status register's interrupt mask.** The raw decompiler omits the `ldc` side effect in a return delay slot. At 0x7188 the requested mask is level 11.
- **0xca7e modifies command bits 3–5 and sends a synchronous SCI0 transaction.** The inherited `ignitionCoilPulse` name is misleading for its visible behavior. A knock-interface role remains a hypothesis.
- **0x71ea waits for SCI0 status bit 0x40 without a software timeout in that loop.** Combined with the interrupt-mask behavior and possible external watchdog, this is a concrete path to investigate for loss of progress. No evidence yet connects entry into a stuck state to 10,000 RPM. An absent external response alone does not necessarily stop an internally clocked SCI transfer.
- **0x4c14 contains 20 NOPs before the return**, despite appearing empty in C. Its timing purpose must not be erased in reconstruction.

No reset-causing bug has been proven. The new evidence improves where to inspect and which misleading decompiler assumptions to avoid. See the [reset review](../reviews/reset_at_10000_rpm.md).

## Reproducing and reviewing

Run `python3 scripts/correlate_rx8defs.py` and then `python3 scripts/annotate_cross_ecu.py` from the artifact directory (the original workspace sources must remain available). The latter inserts idempotent review comments into individual and combined C listings, retaining original function identities. Reapply it after a Ghidra export. The saved Ghidra project predates this extension; these comments and alias files have not been imported into it.

[Validation](validation.json) records counts and definition hashes; [annotation validation](annotation_validation.json) records coverage. Descriptor matches validate pointers/counts, not all calibration semantics or every table's scaling. The C schema passes C11 size/offset assertions. The existing export validator checks ROM hash, instruction bytes and file consistency; it does not prove semantic equivalence.
