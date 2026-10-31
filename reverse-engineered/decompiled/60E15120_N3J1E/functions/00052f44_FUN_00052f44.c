/* ROM address: 0x00052f44; body bytes: 472; decompiled */

char FUN_00052f44(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  char cVar5;
  float fVar6;
  float fVar7;
  
  fVar7 = DAT_ffffcf90;
  fVar6 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff867c);
  fVar7 = fVar7 - fVar6;
  cVar5 = ref_getKnownBooleanValue__();
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffd146 = '\0';
  }
  else if ((((float)0x41366666 < fVar7) && (DAT_ffffd158 == '\0')) && (cVar5 == '\x01')) {
    DAT_ffffd146 = '\x01';
  }
  if (((DAT_ffffd0ac == '\x01') || (DAT_ffffd0ad == '\x01')) || (DAT_ffffd1c5 == '\x01')) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86e4,0);
  }
  else if ((((float)0x41366666 < fVar7) && (DAT_ffffd158 == '\0')) && (cVar5 == '\x01')) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86e4,1);
  }
  cVar4 = DAT_ffffd1c5;
  DAT_ffffd158 = cVar5;
  cVar5 = ref_getKnownBooleanValue__();
  if (cVar4 == '\x01') {
    DAT_ffffd03a = 0;
    DAT_ffffd038 = 0;
    bVar1 = false;
    DAT_ffffd039 = 0;
  }
  else {
    if ((DAT_ffffd080 == '\0') && (cVar5 == '\x01')) {
      DAT_ffffd03a = 1;
      bVar1 = true;
    }
    else {
      DAT_ffffd03a = 0;
      bVar1 = false;
    }
    if (bVar1) {
      if (DAT_ffffd146 != '\x01') {
        DAT_ffffd039 = 1;
        DAT_ffffd038 = 0;
        bVar1 = false;
        goto LAB_0004fdd4;
      }
      DAT_ffffd038 = 1;
      bVar1 = true;
    }
    else {
      DAT_ffffd038 = 0;
      bVar1 = false;
    }
    DAT_ffffd039 = 0;
  }
LAB_0004fdd4:
  if ((DAT_ffffd08a == '\x01') && (DAT_ffffd266 == '\0')) {
    DAT_ffffd03b = 1;
    bVar3 = true;
  }
  else {
    DAT_ffffd03b = 0;
    bVar3 = false;
  }
  if ((DAT_ffffd08b == '\x01') && (DAT_ffffd26f == '\0')) {
    DAT_ffffd03c = '\x01';
  }
  else {
    DAT_ffffd03c = '\0';
  }
  if ((cVar4 == '\x01') || (DAT_ffffd03c == '\x01')) {
    DAT_ffffd03d = 1;
    bVar2 = true;
  }
  else {
    DAT_ffffd03d = 0;
    bVar2 = false;
  }
  if ((bVar2) || (bVar3)) {
    DAT_ffffd03e = 1;
  }
  else {
    DAT_ffffd03e = 0;
  }
  cVar4 = '\x01';
  if ((bVar1) || (cVar4 = DAT_ffffd03c, DAT_ffffd03c == '\x01')) {
    DAT_ffffd03f = 1;
  }
  else {
    DAT_ffffd03f = 0;
  }
  DAT_ffffd080 = cVar5;
  DAT_ffffd08a = DAT_ffffd266;
  DAT_ffffd08b = DAT_ffffd26f;
  return cVar4;
}


