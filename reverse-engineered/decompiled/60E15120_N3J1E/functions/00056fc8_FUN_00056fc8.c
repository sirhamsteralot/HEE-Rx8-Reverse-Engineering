/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffb5ac; decode = raw * 0.003051757812 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056fc8; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 5f3c0 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid16e8_ram_b5ac_raw(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(inferred_ram_b5ac_ffffb5ac_ffffb5ac,0x3b480000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


