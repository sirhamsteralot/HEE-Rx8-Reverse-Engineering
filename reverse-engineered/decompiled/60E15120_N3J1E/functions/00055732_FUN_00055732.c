/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): inferred_battery_voltage_ffffb590; decode = raw * 0.0009999999311 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00055732; body bytes: 22; decompiled */

undefined4 diag_encode_battery_v(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(inferred_battery_voltage_ffffb590,0x3a83126e,0);
  return uVar1;
}


