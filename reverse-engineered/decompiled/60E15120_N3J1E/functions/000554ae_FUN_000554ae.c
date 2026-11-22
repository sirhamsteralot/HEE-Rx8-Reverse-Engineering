/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs diagnostic chain suggests RAM 0xffffa630 = leading_ignition_timing. Direct C dataflow to handler 0x000569ae; semantic candidate, not a recovered original symbol.
 */
/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_leading_timing [high]: PID 0x0e: lead*0.5-64
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): leading_ignition_timing_ffffa630; decode = raw * 0.5 + (-64) [degrees]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x000554ae; body bytes: 24; decompiled */

undefined4 diag_encode_leading_timing(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(leading_ignition_timing_ffffa630,0x3f000000,0xc2800000);
  return uVar1;
}


