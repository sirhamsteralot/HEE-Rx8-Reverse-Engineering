/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): DAT_ffffc6f4; decode = raw * 0.003906199941 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0005831c; body bytes: 80; decompiled */

void FUN_0005831c(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined2 local_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  
  uVar2 = 0;
  uVar1 = 0x3b7fff29;
  local_1c = rx8_encode_u16_affine_saturate(DAT_ffffc6f4,0x3b7fff29,0);
  uStack_1a = rx8_encode_u16_affine_saturate(DAT_ffffc6fc,uVar1,uVar2);
  uStack_18 = 0xffff;
  FUN_0005904a(&DAT_ffff9024,&local_1c);
  return;
}


