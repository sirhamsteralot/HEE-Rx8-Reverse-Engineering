/* ROM address: 0x0004a10c; body bytes: 336; decompiled */

undefined2 * FUN_0004a10c(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  float fVar3;
  float extraout_fr0;
  undefined4 uVar4;
  float fVar5;
  
  uVar4 = 0;
  puVar1 = (undefined2 *)(uint)DAT_ffffd201;
  if (puVar1 == (undefined2 *)&UNK_00000001) {
    DAT_ffffcd5e = 0;
    DAT_ffffcd64 = 0.0;
    DAT_ffffcd68 = 0.0;
  }
  else {
    puVar2 = (undefined2 *)(uint)DAT_ffffcd74;
    if ((((puVar2 != (undefined2 *)0x0) &&
         (puVar1 = (undefined2 *)(int)DAT_ffffcd5e, puVar1 != (undefined2 *)&UNK_ffffffff)) &&
        ((DAT_ffffad98 < 0.3 || ((5.0 <= DAT_ffffcd6c && (DAT_ffffcd6c < 150.0)))))) &&
       ((DAT_ffffad98 < 0.3 || ((0.6 <= DAT_ffffad98 || (0.05 <= DAT_ffffad98 - DAT_ffffcd78)))))) {
      if (puVar2 != (undefined2 *)&UNK_00000001) {
        DAT_ffffcd78 = DAT_ffffad98;
        return puVar2;
      }
      if (0.6 <= DAT_ffffad98) {
        if (DAT_ffffcd5e == -1) {
          DAT_ffffcd78 = DAT_ffffad98;
          return &DAT_0007c5c8;
        }
        DAT_ffffcd74 = 0;
        DAT_ffffcd60 = 0;
        fVar3 = DAT_ffffcd6c;
        fVar5 = DAT_ffffad98;
        DAT_ffffcd70 = FUN_00002460((int)DAT_ffffcd70,1);
        DAT_ffffcd5e = FUN_00002460((int)DAT_ffffcd5e,1);
        puVar1 = (undefined2 *)FUN_000020c4(fVar3,&DAT_0006be2c);
        DAT_ffffcd7c = (short)puVar1;
        if (DAT_ffffcd7c != 0) {
          fVar3 = (float)FUN_000024c0(0x42000000,uVar4,(int)DAT_ffffcd70);
          puVar1 = (undefined2 *)FUN_000024c0(0x41000000,uVar4,(int)DAT_ffffcd7c);
          DAT_ffffcd64 = fVar3 / extraout_fr0;
        }
        DAT_ffffcd68 = DAT_ffffcd64 + DAT_ffffcd68;
        DAT_ffffcd70 = 0;
        DAT_ffffcd78 = fVar5;
        return puVar1;
      }
      if (DAT_ffffad98 < 0.3) {
        DAT_ffffcd78 = DAT_ffffad98;
        return puVar2;
      }
      if (DAT_ffffad98 - DAT_ffffcd78 < 0.05) {
        DAT_ffffcd78 = DAT_ffffad98;
        return puVar2;
      }
      fVar3 = DAT_ffffad98;
      puVar1 = (undefined2 *)FUN_00002460((int)DAT_ffffcd70,1);
      DAT_ffffcd70 = (short)puVar1;
      DAT_ffffcd78 = fVar3;
      return puVar1;
    }
    DAT_ffffcd74 = 0;
  }
  DAT_ffffcd70 = 0;
  DAT_ffffcd60 = 0;
  DAT_ffffcd78 = DAT_ffffad98;
  return puVar1;
}


