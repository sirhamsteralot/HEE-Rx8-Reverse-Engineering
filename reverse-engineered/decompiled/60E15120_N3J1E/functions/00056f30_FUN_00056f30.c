/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): maf_voltage_latched_ffffa9e4; decode = raw * 0.000244140625 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00056f30; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 5f384 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1177_maf_voltage_latched_v(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(maf_voltage_latched_ffffa9e4,0x39800000,0);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


