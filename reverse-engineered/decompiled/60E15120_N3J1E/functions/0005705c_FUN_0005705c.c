/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pida216_ram_bc30_raw [medium]: dispatch record 0x5f3dc -> handler verified in ROM bytes + function_index; DAT_ffffbc30*7.62939e-05
 * RAM 0xffffbc30 inferred_ram_bc30_ffffbc30 (float): PID 0xa216
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffbc30; decode = raw * 7.629394531e-05 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0005705c; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 5f3e4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pida216_ram_bc30_raw(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(inferred_ram_bc30_ffffbc30_ffffbc30,0x38a00000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


