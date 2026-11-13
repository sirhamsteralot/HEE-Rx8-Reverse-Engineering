/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_rpm [high]: PID 0x0c: rpm*0.25
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs diagnostic chain suggests RAM 0xffffb548 = engine_speed_rpm. Direct C dataflow to handler 0x00056982; semantic candidate, not a recovered original symbol.
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): engine_speed_rpm_ffffb548; decode = raw * 0.25 + (0) [RPM]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00055484; body bytes: 22; decompiled */

undefined4 diag_encode_rpm(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(engine_speed_rpm_ffffb548,0x3e800000,0);
  return uVar1;
}


