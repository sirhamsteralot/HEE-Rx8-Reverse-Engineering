/* ROM address: 0x000556b0; body bytes: 30; decompiled */

void FUN_000556b0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff90fc);
  rx8_encode_u16_affine_saturate(uVar1,0x3f800000,uVar2);
  return;
}


