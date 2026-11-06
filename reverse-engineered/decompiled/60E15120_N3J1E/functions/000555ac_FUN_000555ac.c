/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_trim_b074 [medium]: PID 0x15: ffffb074*100*0.7813-100
 * RAM 0xffffb074 inferred_trim_b074_ffffb074 (float): PID 0x15/0x163e: x*100*0.7813-100
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): DAT_ffffb074 * 100.0; decode = raw * 0.7812999487 + (-100) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x000555ac; body bytes: 30; decompiled */

undefined4 candidate_diag_encode_trim_b074(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(inferred_trim_b074_ffffb074_ffffb074 * 100.0,0x3f480346,0xc2c80000);
  return uVar1;
}


