/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): DAT_ffffad48; decode = raw * 0.3921568394 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00055774; body bytes: 22; decompiled */

undefined4 FUN_00055774(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(DAT_ffffad48,0x3ec8c8c8,0);
  return uVar1;
}


