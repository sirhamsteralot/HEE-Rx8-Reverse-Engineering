# Named lookup analysis view

**Integration update:** These names and review comments are now included in
`decompiled/firmware_decompiled.c` and individual function files. Earlier statements
below about a separate named view or unchanged raw C describe the pre-integration
state. The saved Ghidra database remains unchanged. See `metadata/integrated_names.json`.

[firmware_named.c](firmware_named.c) replaces opaque descriptor and selected RAM tokens with descriptive names. This is an additional readable view of the complete C export; the original export and saved Ghidra database are unchanged.

- **452 descriptor addresses** receive names from the matched RX8Defs tables. `tbl_` identifies the descriptor passed to a lookup, rather than the table's raw cell storage. Definitions with generic or questionable names retain that uncertainty in their names.
- **18 RAM addresses** receive descriptive names. Four are backed by the earlier diagnostic dataflow review; **14 use `inferred_`** because their meaning comes from the named axis of an explicit lookup argument.
- **350 lookup calls** are catalogued. Seven have missing or extra decompiled arguments and are excluded from axis inference. No conflicting names were found among the eligible direct RAM arguments; that does not prove every definition is correct.

Examples:

| Original | Readable name | Basis |
|---|---|---|
| DAT_0006aa64 | tbl_injector_latency_secondary_0006aa64 | Descriptor matched to XML data, axes and dimensions |
| DAT_ffffb590 | inferred_battery_voltage_ffffb590 | Battery-voltage axis of injector latency tables |
| DAT_ffffad14 | inferred_barometric_pressure_ffffad14 | Barometric-pressure correction axes |
| DAT_ffffb5c4 | inferred_estimated_battery_temperature_ffffb5c4 | Desired-charge-voltage table axis |
| DAT_ffffb548 | engine_speed_rpm_ffffb548 | Diagnostic reader plus engine-speed axes |

The address suffix matters. For example, both 0xffffb2d4 and 0xffffad44 index throttle-position axes. This identifies a quantity but does not distinguish requested, measured, filtered or fallback throttle position. Likewise, 0xffffa98c and 0xffffa990 are distinct coolant-temperature values. Those distinctions require producer/caller analysis.

For two-dimensional tables, the single explicit numeric argument is associated with the sole axis. For three-dimensional tables, explicit arguments are associated with X and Y in the order supported by the G-ROM declaration and observed calls. This is a candidate-level assumption where the raw ABI has not been fully recovered. Calls with omitted floating-point arguments, expression arguments and locally held temporaries are not used to assign new global RAM names. A generic `Unknown` or `Value` axis provides no meaning.

Table results are recorded in [lookup_result_candidates.json](lookup_result_candidates.json) but not automatically renamed: a mutable global can receive several calculations, and a single table name need not describe its final role. The lookup function signatures remain the original imperfect decompiler signatures; renaming does not repair their ABI.

[lookup_aliases.tsv](lookup_aliases.tsv) gives original tokens, aliases and supporting calls. [lookup_calls.json](lookup_calls.json) includes argument lists. [axis_conflicts.json](axis_conflicts.json) records conflicting candidates if present. [validation.json](validation.json) records coverage and checks.

Rebuild with `python3 scripts/name_lookup_variables.py`. It reads the current raw C, produces this named view, preserves provenance comments verbatim, and checks that only the selected identifier tokens change. This remains analysis C, not buildable firmware.
