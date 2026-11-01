/* ROM address: 0x00051c6c; body bytes: 332; decompiled */

undefined4 * FUN_00051c6c(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  char cVar5;
  
  DAT_ffffd138 = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006b8d8);
  uVar2 = FUN_0003eaa4(&DAT_ffff86c4,0);
  cVar5 = -((((int)(char)DAT_ffffcff1 & 0x80U) == 0) + -1);
  if (((DAT_ffffd145 == '\0') && (cVar5 == '\x01')) || (DAT_ffffd12f == '\x01')) {
    puVar4 = (undefined4 *)0x1;
    DAT_ffffd12e = 0;
    bVar1 = false;
  }
  else {
    puVar4 = (undefined4 *)(uint)DAT_ffffd04a;
    if (((((puVar4 == (undefined4 *)0x1) &&
          (puVar4 = (undefined4 *)(uint)DAT_ffffd12d, puVar4 == (undefined4 *)0x1)) &&
         ((puVar4 = (undefined4 *)(int)DAT_ffffd12c, puVar4 == (undefined4 *)0x0 &&
          ((DAT_ffffaa40 < DAT_ffffd138 &&
           (puVar4 = (undefined4 *)&DAT_ffffaada, DAT_ffffaada == '\0')))))) &&
        ((puVar4 = (undefined4 *)-(((DAT_ffffcff1 & 0x20) == 0) - 1), puVar4 == (undefined4 *)0x1 &&
         ((puVar4 = (undefined4 *)(uint)DAT_ffffb366, puVar4 == (undefined4 *)0x1 &&
          (puVar4 = (undefined4 *)(int)DAT_ffffcfff, puVar4 == (undefined4 *)0x0)))))) &&
       (((uVar2 & 0xff) == 1 || (puVar4 = (undefined4 *)(uVar2 & 0xff), puVar4 == (undefined4 *)0x3)
        ))) {
      uVar3 = FUN_0003eaa4(&DAT_ffff86ee,0);
      puVar4 = (undefined4 *)(uVar3 & 0xff);
      if ((((((puVar4 != (undefined4 *)(uVar2 & 0xff)) &&
             (puVar4 = (undefined4 *)(int)DAT_ffffd14a, puVar4 == (undefined4 *)0x0)) &&
            (DAT_ffffcb39 == '\0')) &&
           ((puVar4 = (undefined4 *)&DAT_ffffcfb4, DAT_ffffcfb4 == '\0' && (DAT_ffffcfc1 == '\0'))))
          && (DAT_ffffd27c == 0)) && (DAT_ffffcdb4 == '\0')) {
        puVar4 = (undefined4 *)0x1;
        DAT_ffffd12e = 1;
        bVar1 = true;
        goto LAB_00051dd6;
      }
    }
    DAT_ffffd12e = 0;
    bVar1 = false;
  }
LAB_00051dd6:
  if (!bVar1) {
    puVar4 = &DAT_00051e24;
    DAT_ffffd118 = 0x3d1ba5e3;
  }
  DAT_ffffd145 = cVar5;
  return puVar4;
}


