/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_ect_c [high]: PID 0x05: coolant_temperature_ffff9f70-40
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs diagnostic chain suggests RAM 0xffff9f70 = coolant_temperature. Direct C dataflow to handler 0x00056940; semantic candidate, not a recovered original symbol.
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): coolant_temperature_ffff9f70; decode = raw * 1 + (-40) [degC]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0005542a; body bytes: 22; decompiled */

undefined4 diag_encode_ect_c(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(coolant_temperature_ffff9f70,0x3f800000,0xc2200000);
  return uVar1;
}


