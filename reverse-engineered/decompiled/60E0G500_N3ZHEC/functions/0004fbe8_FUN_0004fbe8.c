/* ROM address: 0x0004fbe8; body bytes: 204; decompiled */

undefined * FUN_0004fbe8(void)

{
  undefined *puVar1;
  float extraout_fr0;
  float fVar2;
  
  DAT_ffffd038 = (float)FUN_00002068(DAT_ffffb600,&DAT_0006b790);
  fVar2 = ((DAT_ffffcfdc * DAT_ffffd038) / 33.0) / 4.0;
  puVar1 = (undefined *)(uint)DAT_ffffcffa;
  if ((((puVar1 == &UNK_00000001) && (DAT_ffffd036 == '\0')) && (DAT_ffffcfe2 <= DAT_ffffcfe6)) ||
     (DAT_ffffd035 == '\n')) {
    DAT_ffffd035 = '\x01';
    DAT_ffffd014 = fVar2;
  }
  else {
    if (puVar1 != &UNK_00000001) {
      return puVar1;
    }
    if (DAT_ffffcfe2 <= DAT_ffffcfe6) {
      DAT_ffffd035 = FUN_00002478((int)DAT_ffffd035,1);
      DAT_ffffd014 = DAT_ffffd014 + fVar2;
    }
  }
  if ((puVar1 == &UNK_00000001) && (puVar1 = &DAT_0007d239, DAT_ffffd035 == '\n')) {
    puVar1 = (undefined *)FUN_00002500(0x3f800000,0,10);
    DAT_ffffd018 = DAT_ffffd014 / extraout_fr0;
  }
  return puVar1;
}


