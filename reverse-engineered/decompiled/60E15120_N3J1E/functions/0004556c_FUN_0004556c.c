/* ROM address: 0x0004556c; body bytes: 80; decompiled */

undefined4 FUN_0004556c(void)

{
  char cVar1;
  
  cVar1 = ref_getFaultStatus__(0x4e);
  if ((((cVar1 == '\0') && (DAT_ffffccc4 == '\x01')) &&
      (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8728,0), cVar1 == '\0')) &&
     (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873e,0), cVar1 == '\0')) {
    DAT_ffffcbe2 = 1;
    return 0;
  }
  DAT_ffffcbe2 = 0;
  return 0;
}


