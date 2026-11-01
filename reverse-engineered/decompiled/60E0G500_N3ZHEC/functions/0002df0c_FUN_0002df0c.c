/* ROM address: 0x0002df0c; body bytes: 262; decompiled */

undefined1 * FUN_0002df0c(void)

{
  char cVar1;
  undefined1 *puVar2;
  float fVar3;
  
  cVar1 = DAT_ffffc021;
  fVar3 = DAT_ffffc008 - DAT_ffffc00c;
  puVar2 = (undefined1 *)0x1;
  if (((((DAT_ffffad90 == '\x01') || (puVar2 = (undefined1 *)0x1, DAT_ffffbc37 == '\x01')) ||
       (puVar2 = (undefined1 *)0x1, DAT_ffffb5aa == '\x01')) ||
      ((puVar2 = (undefined1 *)(uint)DAT_ffffbd59, puVar2 == (undefined1 *)0x1 &&
       ((((DAT_ffffbd62 == '\0' && (DAT_ffffc021 == '\0')) &&
         ((DAT_ffffc01d == 0 && ((puVar2 = &DAT_ffffc022, DAT_ffffc022 == '\0' && (fVar3 < -15.0))))
         )) || ((puVar2 = (undefined1 *)(uint)DAT_ffffc01d, puVar2 == (undefined1 *)0x1 &&
                ((fVar3 < -15.0 && (puVar2 = &LAB_00001d4c, 0x1d4b < DAT_ffffbd5e)))))))))) ||
     (((DAT_ffffbdb5 == '\0' && (DAT_ffffc008 < 22.5)) ||
      (((9.799999 < DAT_ffffbd38 * 0.27777776 || (DAT_ffffbd38 * 0.27777776 < -9.799999)) ||
       (puVar2 = (undefined1 *)(uint)DAT_ffffbca0, puVar2 == (undefined1 *)0x1)))))) {
    DAT_ffffbd56 = 1;
  }
  else {
    DAT_ffffbd56 = 0;
  }
  if (-15.0 <= fVar3) {
    DAT_ffffbd5e = 0;
  }
  else {
    puVar2 = (undefined1 *)FUN_00002460((int)(short)DAT_ffffbd5e,1);
    DAT_ffffbd5e = (ushort)puVar2;
  }
  DAT_ffffbd62 = cVar1;
  return puVar2;
}


