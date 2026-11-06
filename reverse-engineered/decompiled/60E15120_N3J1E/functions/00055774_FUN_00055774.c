/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_ad48 [medium]: PID 0x45: ffffad48*0.392157
 * RAM 0xffffad48 inferred_ram_ad48_ffffad48 (float): PID 0x45: *0.392157
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (8-bit): DAT_ffffad48; decode = raw * 0.3921568394 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x00055774; body bytes: 22; decompiled */

undefined4 candidate_diag_encode_ad48(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate(inferred_ram_ad48_ffffad48_ffffad48,0x3ec8c8c8,0);
  return uVar1;
}


