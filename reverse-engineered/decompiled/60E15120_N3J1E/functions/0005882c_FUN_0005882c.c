/* ROM address: 0x0005882c; body bytes: 104; decompiled */

void FUN_0005882c(void)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 local_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  
  uVar4 = 0;
  fVar2 = 1000.0;
  uVar3 = 0x3b800000;
  fVar1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff8684);
  local_20 = rx8_encode_u16_affine_saturate(fVar1 * fVar2,uVar3,uVar4);
  fVar1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(uVar4,&DAT_ffff8694);
  uStack_1e = rx8_encode_u16_affine_saturate(fVar1 * fVar2,uVar3,uVar4);
  uStack_1c = 0xffff;
  FUN_0005904a(&DAT_ffff9084,&local_20);
  return;
}


