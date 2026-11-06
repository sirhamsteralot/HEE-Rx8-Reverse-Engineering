/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid093c_throttle_position_raw [high]: dispatch record 0x5f31c -> handler verified in ROM bytes + function_index; inferred_throttle_position_ffffad44*0.00195312 (1/512)
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): inferred_throttle_position_ffffad44; decode = raw * 0.001953125 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056e04; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 5f324 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid093c_throttle_position_raw(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(inferred_throttle_position_ffffad44,0x3b000000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


