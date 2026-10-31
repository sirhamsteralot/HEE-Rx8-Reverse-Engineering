/* ROM address: 0x00051982; body bytes: 72; decompiled */

char FUN_00051982(void)

{
  char cVar1;
  float fVar2;
  
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff8684);
  cVar1 = DAT_ffffcf86;
  if ((DAT_ffffcf86 == '\x01') && ((DAT_ffffcfe8 + fVar2) - DAT_ffffd0e0 < 0.0003)) {
    cVar1 = ref_getFaultStatus__(0x2d);
    if (cVar1 == '\0') {
      DAT_ffffd0f4 = 1;
    }
  }
  return cVar1;
}


