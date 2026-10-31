/* ROM address: 0x000555f8; body bytes: 30; decompiled */

void FUN_000555f8(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff90f4);
  rx8_encode_u16_affine_saturate(uVar1,0x3f800000,uVar2);
  return;
}


