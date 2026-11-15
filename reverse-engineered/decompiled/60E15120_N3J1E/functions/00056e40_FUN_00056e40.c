/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid097c_ram_b59c_div2048 [high]: dispatch record 0x5f334 -> handler verified in ROM bytes + function_index; DAT_ffffb59c*0.000488281 (1/2048) | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffffb59c inferred_ram_b59c_ffffb59c (float): PID 0x097c /2048
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): inferred_ram_b59c_ffffb59c_ffffb59c; decode = raw * 0.00048828125 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056e40; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 5f33c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid097c_ram_b59c_div2048(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(inferred_ram_b59c_ffffb59c_ffffb59c,0x3a000000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


