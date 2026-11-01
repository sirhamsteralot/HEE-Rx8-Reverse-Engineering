/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs diagnostic chain suggests RAM 0xffffa9ec = mass_air_flow. Direct C dataflow to handler 0x000569da; semantic candidate, not a recovered original symbol.
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): mass_air_flow_ffffa9ec; decode = raw * 0.009999999776 + (0) [g/s]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00055528; body bytes: 22; decompiled */

undefined4 diag_encode_maf(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(mass_air_flow_ffffa9ec,0x3c23d70a,0);
  return uVar1;
}


