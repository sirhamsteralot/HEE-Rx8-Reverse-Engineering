/* ROM address: 0x00046392; body bytes: 84; decompiled */

undefined4 FUN_00046392(void)

{
  char cVar1;
  
  cVar1 = ref_getFaultStatus__(0x46);
  if ((((cVar1 == '\0') && (DAT_ffffccc3 == '\x01')) &&
      (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8740,0), cVar1 == '\0')) &&
     ((DAT_ffffccbc == '\0' && (DAT_ffffccbd == '\0')))) {
    DAT_ffffcc28 = 1;
  }
  else {
    DAT_ffffcc28 = 0;
  }
  return 0;
}


