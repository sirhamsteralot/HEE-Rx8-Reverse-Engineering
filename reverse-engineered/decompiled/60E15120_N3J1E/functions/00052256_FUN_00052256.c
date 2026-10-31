/* ROM address: 0x00052256; body bytes: 64; decompiled */

char FUN_00052256(void)

{
  char cVar1;
  float fVar2;
  
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff8684);
  cVar1 = DAT_ffffcf86;
  if ((DAT_ffffcf86 == '\x01') && (DAT_ffffcfe4 < DAT_ffffcfe8 + fVar2)) {
    cVar1 = ref_getFaultStatus__(0x77);
    if (cVar1 == '\0') {
      DAT_ffffd117 = 1;
    }
  }
  return cVar1;
}


