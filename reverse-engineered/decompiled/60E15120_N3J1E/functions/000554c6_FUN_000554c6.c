/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs diagnostic chain suggests RAM 0xffff9f60 = intake_air_temperature. Direct C dataflow to handler 0x000569c4; semantic candidate, not a recovered original symbol.
 */
/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_iat [high]: PID 0x0f: iat-40
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): intake_air_temperature_ffff9f60; decode = raw * 1 + (-40) [degC]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x000554c6; body bytes: 22; decompiled */

undefined4 diag_encode_iat(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(intake_air_temperature_ffff9f60,0x3f800000,0xc2200000);
  return uVar1;
}


