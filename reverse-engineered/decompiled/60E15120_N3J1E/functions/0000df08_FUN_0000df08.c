/* ROM address: 0x0000df08; body bytes: 98; decompiled */

char FUN_0000df08(void)

{
  char cVar1;
  
  cVar1 = engine_running_flag_ffffaa68;
  if ((engine_running_flag_ffffaa68 == '\x01') && (cVar1 = '\x01', DAT_ffffb578 != '\x01')) {
    if (((DAT_ffffbac0 == '\0') || (DAT_ffffbaf0 == '\0')) &&
       ((((int)DAT_ffffcd0e & 0x80U) != 0 && (cVar1 = ref_getFaultStatus__(0x7f), cVar1 == '\0'))))
    {
      DAT_ffffa402 = 1;
      return '\0';
    }
    cVar1 = '\0';
    DAT_ffffa402 = 0;
  }
  return cVar1;
}


