/* ROM address: 0x0002e050; body bytes: 152; decompiled */

undefined4 * FUN_0002e050(void)

{
  char cVar1;
  undefined4 *puVar2;
  float fVar3;
  
  cVar1 = DAT_ffffc022;
  fVar3 = DAT_ffffc008 - DAT_ffffc00c;
  puVar2 = (undefined4 *)(uint)DAT_ffffbd59;
  if ((puVar2 != (undefined4 *)&UNK_00000001) ||
     (((((DAT_ffffbd63 != '\0' || (DAT_ffffc022 != '\0')) || (DAT_ffffc01d != 0)) ||
       (puVar2 = &DAT_00076b5c, fVar3 < 10.0)) &&
      (((puVar2 = (undefined4 *)(uint)DAT_ffffc01d, puVar2 != (undefined4 *)&UNK_00000001 ||
        (fVar3 < 10.0)) || (puVar2 = (undefined4 *)&LAB_00001d4c, DAT_ffffbd60 < 0x1d4c)))))) {
    DAT_ffffbd57 = 0;
  }
  else {
    DAT_ffffbd57 = 1;
  }
  if (fVar3 < 10.0) {
    DAT_ffffbd60 = 0;
  }
  else {
    puVar2 = (undefined4 *)FUN_00002460((int)(short)DAT_ffffbd60,1);
    DAT_ffffbd60 = (ushort)puVar2;
  }
  DAT_ffffbd63 = cVar1;
  return puVar2;
}


