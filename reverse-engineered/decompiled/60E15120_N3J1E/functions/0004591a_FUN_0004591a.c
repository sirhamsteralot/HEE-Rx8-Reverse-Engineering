/* ROM address: 0x0004591a; body bytes: 64; decompiled */

undefined4 FUN_0004591a(void)

{
  char cVar1;
  
  cVar1 = ref_getFaultStatus__(0x6c);
  if (((cVar1 == '\0') && (DAT_ffffccc2 == '\x01')) &&
     (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff872c,0), cVar1 == '\0')) {
    DAT_ffffcbf0 = 1;
    return 0;
  }
  DAT_ffffcbf0 = 0;
  return 0;
}


