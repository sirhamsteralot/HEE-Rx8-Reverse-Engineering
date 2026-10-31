/* ROM address: 0x00012e60; body bytes: 58; decompiled */

void FUN_00012e60(void)

{
  undefined4 uVar1;
  
  uVar1 = rx8_decode_u8_affine(0x3f800000,0,(int)DAT_ffffa688);
  DAT_ffffa698 = (float)lookup_2d_descriptor_scaled(uVar1,&DAT_0006a04c);
  DAT_ffffa66c = DAT_ffffa67c * DAT_ffffa698;
  DAT_ffffa670 = DAT_ffffa680 * DAT_ffffa698;
  return;
}


