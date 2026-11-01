/* ROM address: 0x0004376c; body bytes: 278; decompiled */

undefined1 * FUN_0004376c(void)

{
  undefined1 *puVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  
  puVar1 = (undefined1 *)(uint)DAT_ffffd201;
  if (puVar1 == (undefined1 *)0x1) {
    DAT_ffffca08 = 0;
    DAT_ffffca0a = 0;
    puVar1 = &DAT_ffffca05;
    DAT_ffffca05 = 0;
    DAT_ffffca04 = 0;
    DAT_ffffca07 = 0;
    DAT_ffffca06 = 0;
  }
  else {
    fVar3 = DAT_ffffb600;
    fVar4 = DAT_ffffb3a0;
    if (DAT_ffffb3a0 < 90.0) {
      uVar2 = FUN_000671a4(5);
      puVar1 = (undefined1 *)(uVar2 & 0xff);
      if (puVar1 == (undefined1 *)0x1) {
        DAT_ffffca08 = 0;
      }
      else {
        if ((fVar3 <= 10.0) || (puVar1 = (undefined1 *)0x1, DAT_ffffc721 == '\x01')) {
          DAT_ffffca08 = 0;
        }
        else {
          puVar1 = (undefined1 *)FUN_00002460((int)(short)DAT_ffffca08,1);
          DAT_ffffca08 = (ushort)puVar1;
        }
        if (DAT_ffffca08 < 0x40) {
          puVar1 = (undefined1 *)0x40;
          if (DAT_ffffca08 < 0x40) {
            puVar1 = &DAT_ffffca04;
            DAT_ffffca04 = 1;
          }
        }
        else {
          DAT_ffffca05 = 1;
        }
      }
    }
    if (10.0 <= fVar4) {
      uVar2 = FUN_000671a4(6);
      puVar1 = (undefined1 *)(uVar2 & 0xff);
      if (puVar1 == (undefined1 *)0x1) {
        DAT_ffffca0a = 0;
      }
      else {
        if ((fVar3 <= 10.0) || (DAT_ffffc720 == '\0')) {
          DAT_ffffca0a = 0;
        }
        else {
          puVar1 = (undefined1 *)FUN_00002460((int)(short)DAT_ffffca0a,1);
          DAT_ffffca0a = (ushort)puVar1;
        }
        if (DAT_ffffca0a < 0x40) {
          puVar1 = (undefined1 *)0x40;
          if (DAT_ffffca0a < 0x40) {
            puVar1 = &DAT_ffffca06;
            DAT_ffffca06 = 1;
          }
        }
        else {
          DAT_ffffca07 = 1;
        }
      }
    }
  }
  return puVar1;
}


