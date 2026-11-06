/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_vss [high]: PID 0x0d: vss*1
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs diagnostic chain suggests RAM 0xffffbbb4 = vehicle_speed. Direct C dataflow to handler 0x00056998; semantic candidate, not a recovered original symbol.
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): vehicle_speed_ffffbbb4; decode = raw * 1 + (0) [km/h]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0005549a; body bytes: 20; decompiled */

undefined4 diag_encode_vss(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(vehicle_speed_ffffbbb4,0x3f800000,0);
  return uVar1;
}


