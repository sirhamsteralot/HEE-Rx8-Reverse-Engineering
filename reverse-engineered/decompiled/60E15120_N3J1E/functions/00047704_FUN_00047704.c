/* ROM address: 0x00047704; body bytes: 236; decompiled */

char FUN_00047704(void)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  
  cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff872c,0);
  cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8730,0);
  if ((cVar4 == '\x01') ||
     (cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8732,0), cVar4 == '\x01')) {
    DAT_ffffcc96 = '\x01';
  }
  else {
    DAT_ffffcc96 = '\0';
  }
  cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8734,0);
  if ((cVar4 == '\x01') ||
     (cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8736,0), cVar4 == '\x01')) {
    DAT_ffffcc97 = 1;
    bVar1 = true;
  }
  else {
    DAT_ffffcc97 = 0;
    bVar1 = false;
  }
  if (((DAT_ffffcc96 == '\x01') && (bVar1)) || (cVar3 == '\x01')) {
    DAT_ffffcc9e = 1;
  }
  else {
    DAT_ffffcc9e = 0;
  }
  if ((DAT_ffffcc96 == '\x01') || (cVar3 == '\x01')) {
    DAT_ffffcc9b = 1;
    bVar2 = true;
  }
  else {
    DAT_ffffcc9b = 0;
    bVar2 = false;
  }
  if ((bVar1) || (cVar3 == '\x01')) {
    DAT_ffffcc9c = '\x01';
  }
  else {
    DAT_ffffcc9c = '\0';
  }
  cVar3 = '\x01';
  if ((bVar2) || (cVar3 = DAT_ffffcc9c, DAT_ffffcc9c == '\x01')) {
    DAT_ffffcc9d = 1;
  }
  else {
    DAT_ffffcc9d = 0;
  }
  return cVar3;
}


