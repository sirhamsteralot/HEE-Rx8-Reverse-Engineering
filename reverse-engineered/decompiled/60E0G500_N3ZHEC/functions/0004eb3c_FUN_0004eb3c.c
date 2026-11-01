/* ROM address: 0x0004eb3c; body bytes: 272; decompiled */

undefined4 * FUN_0004eb3c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = FUN_0003eb72(0,&DAT_ffff86a4);
  puVar1 = (undefined4 *)FUN_000020c4(uVar3,&DAT_0006b75c);
  DAT_ffffcfb4 = DAT_ffffd2ab;
  if (DAT_ffffd2ab == 0) {
    DAT_ffffcfb6 = '\0';
    puVar2 = puVar1;
  }
  else {
    puVar2 = &DAT_ffffd020;
    if (((((DAT_ffffd020 < DAT_ffffd01c) && (DAT_ffffd034 == '\0')) &&
         (puVar2 = (undefined4 *)(uint)DAT_ffffd2ab, puVar2 == (undefined4 *)0x1)) &&
        (puVar2 = (undefined4 *)(uint)DAT_ffffcfe6, (undefined4 *)0x4e < puVar2)) ||
       ((uint)DAT_ffffcfb8 == ((uint)puVar1 & 0xffff))) {
      DAT_ffffcfb6 = '\x01';
    }
  }
  if (DAT_ffffd2ab == 0) {
    DAT_ffffcfb5 = 0;
  }
  else {
    puVar2 = (undefined4 *)0x1;
    if ((DAT_ffffcfb6 == '\x01') ||
       ((puVar2 = (undefined4 *)(uint)DAT_ffffd2ab, puVar2 == (undefined4 *)0x1 &&
        (((((puVar2 = (undefined4 *)0x1, DAT_ffffd081 == '\x01' ||
            (puVar2 = (undefined4 *)0x1, DAT_ffffd07e == '\x01')) ||
           ((puVar2 = (undefined4 *)0x1, DAT_ffffd14b == '\x01' ||
            ((puVar2 = (undefined4 *)0x1, DAT_ffffd14c == '\x01' ||
             (puVar2 = (undefined4 *)0x1, DAT_ffffd14e == '\x01')))))) ||
          (puVar2 = (undefined4 *)0x1, DAT_ffffd14f == '\x01')) ||
         (((puVar2 = (undefined4 *)0x1, DAT_ffffd151 == '\x01' ||
           (puVar2 = (undefined4 *)0x1, DAT_ffffd153 == '\x01')) ||
          (puVar2 = (undefined4 *)(uint)DAT_ffffd155, puVar2 == (undefined4 *)0x1)))))))) {
      DAT_ffffcfb5 = 1;
    }
  }
  DAT_ffffcfb8 = DAT_ffffcfe6;
  return puVar2;
}


