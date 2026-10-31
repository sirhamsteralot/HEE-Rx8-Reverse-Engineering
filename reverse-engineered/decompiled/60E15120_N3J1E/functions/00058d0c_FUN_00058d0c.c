/* ROM address: 0x00058d0c; body bytes: 106; decompiled */

void FUN_00058d0c(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 local_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  
  uVar4 = 0;
  uVar3 = 0x3f800000;
  uVar2 = 0x43000000;
  uVar1 = rx8_decode_u8_affine(0x43000000,0,(int)DAT_ffffc53f);
  local_20 = rx8_encode_u16_affine_saturate(uVar1,uVar3,uVar4);
  uStack_1e = 0;
  uVar1 = rx8_decode_u8_affine(uVar2,uVar4,0x27);
  uStack_1c = rx8_encode_u16_affine_saturate(uVar1,uVar3,uVar4);
  FUN_0005904a(&DAT_ffff90c4,&local_20);
  return;
}


