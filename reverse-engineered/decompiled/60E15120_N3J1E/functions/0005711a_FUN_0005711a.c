/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1634_apv_position_voltage [high]: dispatch record 0x5f424 -> handler verified in ROM bytes + function_index; apv_position_voltage_ffffcab0*0.0195312
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): apv_position_voltage_ffffcab0; decode = raw * 0.01953125 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0005711a; body bytes: 30; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f424. Table purpose inferred from
   neighboring code. */

void diag22_pid1634_apv_position_voltage(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(apv_position_voltage_ffffcab0,0x3ca00000,0);
  diag_append_u8((int)param_1,uVar1);
  return;
}


