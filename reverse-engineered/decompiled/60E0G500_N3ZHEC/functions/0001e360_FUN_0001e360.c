/* ROM address: 0x0001e360; body bytes: 190; decompiled */

undefined4 * FUN_0001e360(void)

{
  short sVar2;
  undefined4 *puVar1;
  float fVar3;
  
  fVar3 = DAT_ffffae84 - DAT_ffffae78;
  sVar2 = FUN_000020c4(DAT_ffffaa1c,&DAT_0006a1fc);
  puVar1 = (undefined4 *)(uint)DAT_ffffae97;
  if (puVar1 == (undefined4 *)&UNK_00000001) {
    puVar1 = (undefined4 *)FUN_00002460((int)(short)DAT_ffffb130,1);
    DAT_ffffb130 = (ushort)puVar1;
  }
  else {
    DAT_ffffb130 = 0;
  }
  if ((((((DAT_ffffb130 < 0x4e) || (5000.0 <= DAT_ffffb5b8)) ||
        (puVar1 = &DAT_00071528, fVar3 < -0.015)) || ((0.015 <= fVar3 || (1.0 < DAT_ffffc12c)))) ||
      ((DAT_ffffaa10 < 70.0 ||
       ((puVar1 = (undefined4 *)(uint)DAT_ffffad9c, puVar1 != (undefined4 *)&UNK_00000001 ||
        (puVar1 = (undefined4 *)(int)sVar2, (undefined4 *)(int)DAT_ffffa424 < puVar1)))))) ||
     (puVar1 = (undefined4 *)(int)DAT_ffffcd9d, puVar1 != (undefined4 *)0x0)) {
    DAT_ffffb0ed = 0;
  }
  else {
    DAT_ffffb0ed = 1;
  }
  return puVar1;
}


