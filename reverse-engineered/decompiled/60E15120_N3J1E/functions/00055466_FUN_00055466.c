/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): DAT_ffffb0d0 * 100.0; decode = raw * 0.78125 + (-100) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00055466; body bytes: 30; decompiled */

undefined4 diag_encode_ltft(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(inferred_ltft_bank1_ffffb0d0_ffffb0d0 * 100.0,0x3f480000,0xc2c80000);
  return uVar1;
}


