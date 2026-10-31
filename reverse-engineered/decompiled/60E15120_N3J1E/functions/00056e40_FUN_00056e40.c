/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffb59c; decode = raw * 0.00048828125 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056e40; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 5f33c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00056e40(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(DAT_ffffb59c,0x3a000000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


