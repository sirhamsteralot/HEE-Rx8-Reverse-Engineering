/* [CROSS-ECU / RX8DEFS REVIEW]
 * RX8Defs diagnostic chain suggests RAM 0xffffc0b4 = engine_load. Direct C dataflow to handler 0x00056b8a; semantic candidate, not a recovered original symbol.
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): engine_load_ffffc0b4; decode = raw * 0.003921568394 + (0) [logger-defined load units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00055748; body bytes: 22; decompiled */

undefined4 FUN_00055748(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u16_affine_saturate(engine_load_ffffc0b4,0x3b808080,0);
  return uVar1;
}


