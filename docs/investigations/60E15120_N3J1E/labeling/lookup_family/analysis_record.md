# Function analysis record

## 0x00002068

**Old name:** lookup_2d_descriptor_scaled

**New name:** lookup_2d_descriptor_scaled

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** Dispatch pointers verified directly at 0x2098/0x210c. Type values are byte offsets 0,4,8,12,16. Unknown dispatch values remain an unresolved operation, not an invented error/default value.

**Evidence:** firmware_disassembly.asm at 00002068; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x000020ac

**Old name:** ref_2DLookup_FP_8bit

**New name:** rx8_lookup_2d_raw_u8

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** Wrapper uses FTRC then EXTU.B/W. Exceptional conversion left to explicitly unresolved SH operation; no C undefined float-to-int replacement.

**Evidence:** firmware_disassembly.asm at 000020ac; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x000020c4

**Old name:** ref_2DLookup_FP_16bit

**New name:** rx8_lookup_2d_raw_u16

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** Wrapper uses FTRC then EXTU.B/W. Exceptional conversion left to explicitly unresolved SH operation; no C undefined float-to-int replacement.

**Evidence:** firmware_disassembly.asm at 000020c4; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x000020dc

**Old name:** lookup_3d_descriptor_scaled

**New name:** lookup_3d_descriptor_scaled

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** Dispatch pointers verified directly at 0x2098/0x210c. Type values are byte offsets 0,4,8,12,16. Unknown dispatch values remain an unresolved operation, not an invented error/default value.

**Evidence:** firmware_disassembly.asm at 000020dc; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x00002120

**Old name:** ref_3DLookup_FP_8bit

**New name:** rx8_lookup_3d_raw_u8

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** Wrapper uses FTRC then EXTU.B/W. Exceptional conversion left to explicitly unresolved SH operation; no C undefined float-to-int replacement.

**Evidence:** firmware_disassembly.asm at 00002120; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x0000213c

**Old name:** ref_3DLookup_FP_16bit

**New name:** rx8_lookup_3d_raw_u16

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** Wrapper uses FTRC then EXTU.B/W. Exceptional conversion left to explicitly unresolved SH operation; no C undefined float-to-int replacement.

**Evidence:** firmware_disassembly.asm at 0000213c; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x0000253c

**Old name:** ref_interpolate_floatTable

**New name:** rx8_interpolate_2axis_f32

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** 0000253c: signed low-word row offset, two calls to 00002678, second only if Y fraction nonzero; final FR2. No row-bound checks added.

**Evidence:** firmware_disassembly.asm at 0000253c; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x0000256c

**Old name:** ref_lookup_char

**New name:** rx8_interpolate_2axis_s8

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** 0000256c: signed low-word row offset, two calls to 000026f4, second only if Y fraction nonzero; final FR2. No row-bound checks added.

**Evidence:** firmware_disassembly.asm at 0000256c; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x00002598

**Old name:** ref_lookup_short

**New name:** rx8_interpolate_2axis_s16

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** 00002598: signed low-word row offset, two calls to 00002690, second only if Y fraction nonzero; final FR2. No row-bound checks added.

**Evidence:** firmware_disassembly.asm at 00002598; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x000025c8

**Old name:** ref_interpolate_8bitTable

**New name:** rx8_interpolate_2axis_u8

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** 000025c8: signed low-word row offset, two calls to 000026b0, second only if Y fraction nonzero; final FR2. No row-bound checks added.

**Evidence:** firmware_disassembly.asm at 000025c8; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x000025f4

**Old name:** ref_interpolate_3d_uint16

**New name:** rx8_interpolate_2axis_u16

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** 000025f4: signed low-word row offset, two calls to 000026d0, second only if Y fraction nonzero; final FR2. No row-bound checks added.

**Evidence:** firmware_disassembly.asm at 000025f4; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x00002624

**Old name:** ref_dataLookup

**New name:** rx8_find_axis_index_fraction

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** 0x2624-2656: R0 count/index, R1 axis, FR0 value/fraction. Endpoint paths set FR0=0; interior path divides breakpoint differences. No empty-axis guard is present. Struct return models two hardware outputs, not a native C ABI claim.

**Evidence:** firmware_disassembly.asm at 00002624; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x00002658

**Old name:** ref_indexLookupSomething

**New name:** rx8_find_xy_axis_positions

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** 0x2658-2676: first search FR4/X/count+0/axis+4, second FR5/Y/count+2/axis+8; results R2/R3 and FR0/FR1. Both calls required.

**Evidence:** firmware_disassembly.asm at 00002658; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x00002678

**Old name:** ref_interpolate_floatTable

**New name:** rx8_interpolate_1d_f32

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** 00002678: integer extension distinguishes float; R0 index, R1 data, FR0 fraction, FR2 result. FMAC retained as explicit model operation.

**Evidence:** firmware_disassembly.asm at 00002678; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x00002690

**Old name:** ref_interpolate_shortTable

**New name:** rx8_interpolate_1d_s16

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** 00002690: integer extension distinguishes int16_t; R0 index, R1 data, FR0 fraction, FR2 result. FMAC retained as explicit model operation.

**Evidence:** firmware_disassembly.asm at 00002690; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x000026b0

**Old name:** ref_interpolate_uint8Table

**New name:** rx8_interpolate_1d_u8

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** 000026b0: integer extension distinguishes uint8_t; R0 index, R1 data, FR0 fraction, FR2 result. FMAC retained as explicit model operation.

**Evidence:** firmware_disassembly.asm at 000026b0; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x000026d0

**Old name:** ref_interpolate_uint16Table

**New name:** rx8_interpolate_1d_u16

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** 000026d0: integer extension distinguishes uint16_t; R0 index, R1 data, FR0 fraction, FR2 result. FMAC retained as explicit model operation.

**Evidence:** firmware_disassembly.asm at 000026d0; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.


## 0x000026f4

**Old name:** ref_interpolate_charTable

**New name:** rx8_interpolate_1d_s8

**Confidence:** High: ordinary valid table behavior and register roles

**Reason:** 000026f4: integer extension distinguishes int8_t; R0 index, R1 data, FR0 fraction, FR2 result. FMAC retained as explicit model operation.

**Evidence:** firmware_disassembly.asm at 000026f4; callgraph.tsv; ROM dispatch pointers

**Remaining uncertainty:** Invalid addresses/counts, target pointer wrap on non-32-bit hosts, signaling NaN/FPU exception details and unknown type dispatch are not executable host models.

