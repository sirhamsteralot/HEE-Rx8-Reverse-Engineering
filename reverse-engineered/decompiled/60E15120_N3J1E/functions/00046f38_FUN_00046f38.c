/* ROM address: 0x00046f38; body bytes: 56; decompiled */

uint FUN_00046f38(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8750,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_0005fd38(0x41,1);
    return uVar1;
  }
  if (DAT_ffffcc68 == 1) {
    uVar1 = FUN_0005fd38(0x41,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc68;
}


