/* ROM address: 0x00046aca; body bytes: 64; decompiled */

undefined4 FUN_00046aca(void)

{
  char cVar1;
  
  cVar1 = ref_getFaultStatus__(99);
  if (((cVar1 == '\0') && (DAT_ffffccc5 == '\x01')) &&
     (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8744,0), cVar1 == '\0')) {
    DAT_ffffcc5c = 1;
    return 0;
  }
  DAT_ffffcc5c = 0;
  return 0;
}


