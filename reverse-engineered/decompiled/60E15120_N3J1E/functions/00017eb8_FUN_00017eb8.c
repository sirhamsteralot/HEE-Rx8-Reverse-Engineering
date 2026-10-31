/* ROM address: 0x00017eb8; body bytes: 78; decompiled */

uint FUN_00017eb8(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff805a,0);
  if (cVar2 == '\x01') {
    FUN_0005fd38(0x50,1);
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff805c,0);
  if (cVar2 == '\x01') {
    FUN_0005fd38(0x51,1);
  }
  uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff805e,0);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 1) {
    uVar1 = FUN_0005fd38(0x52,1);
  }
  return uVar1;
}


