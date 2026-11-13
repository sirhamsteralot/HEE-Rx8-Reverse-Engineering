# Signatures, locals, structures and symbolic constants

Applied directly to `decompiled/firmware_decompiled.c` and individual function files. This pass changes **267 functions**, assigns **484 scoped local/parameter names**, exposes missing lookup arguments, and replaces selected pointer arithmetic and numeric constants with documented fields and symbols. It does not claim complete type recovery for all 3,355 routines.

## 1. Function signatures

The 2D lookup now takes `(float axis_value, const Rx8Table2D *table)`; 3D takes `(float x_value, float y_value, const Rx8Table3D *table)`. Assembly at 0x2068 and 0x2658 establishes FR4 as the single/X input, FR5 as Y, R4 as descriptor and FR0 as result. The table fields are typed. Internal interpolation helpers still communicate through implicit registers; their unresolved locals remain explicitly named. Merely exposing arguments does not repair those helper bodies.

CAN transmission takes a descriptor pointer. Diagnostic append parameters now distinguish a byte value from 32-bit containers, and the SCI transmit parameter is a byte. Its signed receive return is preserved. The sorter takes a typed record pointer and a 32-bit count whose low 16 bits are used. Where return meaning is unresolved, `undefined4` remains instead of an invented status type.

[unresolved_lookup_calls.json](unresolved_lookup_calls.json) lists **23 calls with argument-count mismatches**. No guessed input values were inserted. This audit extends beyond the earlier subset of descriptor-matched calls. Other arity-correct calls can still have imperfect types or missing dataflow. These limitations mean the entire listing remains analysis C, not compilable firmware.

## 2. Local and parameter names

Math parameters now identify quantities such as signal, units-per-count, offset, coefficient and threshold. Diagnostic locals identify record index, match status and response bytes. CAN locals identify pending bits, mailbox mask and saved interrupt state.

Automatic propagation is limited to single-assignment temporaries copied directly from an already-named global. They receive `snapshot_...` names, retaining the global's address and any `inferred_` qualifier. This is a scoped identifier substitution, not an assumption about a complex expression's meaning. Other locals remain unnamed until their dataflow is established.

## 3. Structures and arrays

[rx8_analysis_types.h](../../../../../reverse-engineered/decompiled/60E15120_N3J1E/rx8_analysis_types.h) defines five checked layouts:

- 2D descriptor: counts, type, 32-bit axis/data addresses, optional scaling.
- 3D descriptor: two counts, axes/data addresses, type and optional scaling.
- Diagnostic record: identifier, response length, availability mask, handler address.
- CAN descriptor: identifier, mailbox selector, payload length/address and unknown metadata.
- Sort record: uint16 key, byte payload, untouched padding; four-byte stride.

These are target layouts. Multibyte ROM fields are big-endian; they must not be cast directly from a file on a little-endian host. Address fields use uint32_t to preserve offsets on 64-bit hosts. Short unscaled lookup records omit the trailing scale/offset fields, which must only be accessed for the appropriate type.

Diagnostic dispatch now uses `records[record_index].identifier`, `.availability_mask`, `.handler_address` and `.response_length`. CAN transmission uses descriptor fields. The sorter uses record indexing and named key/payload values, preserving padding rather than copying whole records. Its equivalence is for ordinary RAM, not volatile memory or instruction-timing behavior.

## 4. Enums and bitfields

Scoped names replace diagnostic service 0x22, positive response 0x62, identifier rejection 0x31, record count/header size, the SCI receive-data-full mask, and encoder saturation limits. Unknown state values and unnamed metadata remain numeric/unknown. Bit masks are used instead of compiler-dependent C bitfield layouts. These constants do not pretend to recover complete operating-mode enums.

## Validation and reproduction

- All five layouts pass C11 size/offset static assertions.
- The sorter matches the previous exported algorithm on 2,000 host cases, including duplicate keys and unchanged padding. The previous export is a comparison oracle, not a proof of equivalence to every target execution.
- Scoped rename targets were checked for collisions. All 3,355 individual function bodies match the canonical listing.
- Existing ROM-byte and export checks pass. The ROM and Ghidra database are unchanged.

[changes.json](changes.json) records per-function edits; [validation.json](validation.json) records counts. The pre-change export is backed up in `backups/pre_readability.zip`.

After a fresh export and previous naming passes, run `scripts/refine_readability.py`, then `scripts/refine_sort_record.py`, then `scripts/verify_readability.py`. The main pass refuses to run twice on an already-refined listing to avoid repeated structural substitutions. Run it again only after fresh regeneration. The named compatibility copy is synchronized; its include path points back to the canonical type header.
