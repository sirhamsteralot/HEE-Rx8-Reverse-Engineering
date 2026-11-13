/* ROM address: 0x0000df6a; body bytes: 72; decompiled */

char FUN_0000df6a(void)

{
  char cVar1;
  
  cVar1 = engine_running_flag_ffffaa68;
  if ((engine_running_flag_ffffaa68 == '\x01') && (cVar1 = '\x01', DAT_ffffb578 != '\x01')) {
    if ((DAT_ffffbfff == '\0') && (cVar1 = ref_getFaultStatus__(0x81), cVar1 == '\0')) {
      DAT_ffffa403 = 1;
      return '\0';
    }
    cVar1 = '\0';
    DAT_ffffa403 = 0;
  }
  return cVar1;
}


