/* ROM address: 0x000461dc; body bytes: 64; decompiled */

undefined4 FUN_000461dc(void)

{
  char cVar1;
  
  cVar1 = ref_getFaultStatus__(0x62);
  if (((cVar1 == '\0') && (DAT_ffffccc4 == '\x01')) &&
     (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873c,0), cVar1 == '\0')) {
    DAT_ffffcc15 = 1;
    return 0;
  }
  DAT_ffffcc15 = 0;
  return 0;
}


