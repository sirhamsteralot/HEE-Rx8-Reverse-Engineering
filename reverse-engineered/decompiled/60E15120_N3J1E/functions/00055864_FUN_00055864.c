/* [ADDITIONAL SOURCE REVIEW]
 * diag_encode_b410 [medium]: PID 0x4c: ffffb410*100/84*0.392157
 * RAM 0xffffb410 inferred_ram_b410_ffffb410 (float): PID 0x4c/0x091a
 */
/* ROM address: 0x00055864; body bytes: 38; decompiled */

undefined4 candidate_diag_encode_b410(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_encode_u8_affine_saturate((inferred_ram_b410_ffffb410_ffffb410 * 100.0) / 84.0,0x3ec8c8c8,0);
  return uVar1;
}


