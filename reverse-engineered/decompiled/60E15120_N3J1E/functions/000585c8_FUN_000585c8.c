/* ROM address: 0x000585c8; body bytes: 108; decompiled */

void FUN_000585c8(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 local_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  
  uVar4 = 0;
  uVar1 = rx8_decode_u16_affine(0x41000000,0,10);
  uVar2 = rx8_decode_u16_affine(0x42000000,uVar4,(int)DAT_ffffcd40);
  uVar3 = 0x3f800000;
  local_20 = rx8_encode_u16_affine_saturate(uVar2,0x3f800000,uVar4);
  uStack_1e = 0;
  uStack_1c = rx8_encode_u16_affine_saturate(uVar1,uVar3,uVar4);
  FUN_0005904a(&DAT_ffff9064,&local_20);
  return;
}


