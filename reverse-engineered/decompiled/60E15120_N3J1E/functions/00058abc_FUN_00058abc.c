/* ROM address: 0x00058abc; body bytes: 92; decompiled */

void FUN_00058abc(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined2 local_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  
  uVar3 = 0;
  uVar2 = 0x37ffda40;
  uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff86a8);
  local_1c = rx8_encode_u16_affine_saturate(uVar1,uVar2,uVar3);
  uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(uVar3,&DAT_ffff86b8);
  uStack_1a = rx8_encode_u16_affine_saturate(uVar1,uVar2,uVar3);
  uStack_18 = 0xffff;
  FUN_0005904a(&DAT_ffff90a4,&local_1c);
  return;
}


