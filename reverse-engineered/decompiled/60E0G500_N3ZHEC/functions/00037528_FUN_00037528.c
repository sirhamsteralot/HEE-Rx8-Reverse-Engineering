/* ROM address: 0x00037528; body bytes: 230; decompiled */

undefined2 * FUN_00037528(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(uint)DAT_ffffc242;
  if (puVar1 == (undefined2 *)&UNK_00000033) {
    if ((DAT_ffffc2cf == '\0') &&
       (puVar1 = (undefined2 *)(uint)DAT_ffffc2d0, puVar1 == (undefined2 *)&UNK_00000001)) {
      DAT_ffffc242 = 0x55;
      DAT_ffffc2e5 = DAT_ffffc2e5 | 2;
      puVar1 = (undefined2 *)&DAT_ffffc2ae;
      DAT_ffffc2d0 = 0;
      DAT_ffffc2ae = 1;
    }
  }
  else if (((puVar1 == (undefined2 *)&UNK_00000055) &&
           (puVar1 = (undefined2 *)-(((DAT_ffffc2e5 & 2) == 0) - 1),
           puVar1 == (undefined2 *)&UNK_00000001)) &&
          (puVar1 = (undefined2 *)(uint)DAT_ffffc2ad, puVar1 == (undefined2 *)&UNK_00000001)) {
    DAT_ffffc2bc = 1;
    FUN_000378d8();
    puVar1 = &DAT_ffffc2a2;
    if (DAT_ffffc2ba == DAT_ffffc2a2) {
      DAT_ffffc242 = 0xaa;
      puVar1 = (undefined2 *)((int)(char)DAT_ffffc2e5 & 0xfd);
      DAT_ffffc2e5 = (byte)puVar1;
      DAT_ffffc2ab = 0;
      DAT_ffffc2e6 = 0;
      DAT_ffffc2b2 = 1;
    }
    else {
      DAT_ffffc2ab = 1;
      if (DAT_ffffc2e8 != 0xff) {
        DAT_ffffc2e8 = DAT_ffffc2e8 + 1;
      }
      if (1 < DAT_ffffc2e8) {
        DAT_ffffc2e6 = 0;
        DAT_ffffc2b2 = 1;
        DAT_ffffc2a9 = 1;
        DAT_ffffc2e9 = 200;
        DAT_ffffc2e8 = 0;
        DAT_ffffc2b0 = 1;
        puVar1 = (undefined2 *)FUN_00037354();
      }
    }
    DAT_ffffc2ae = 1;
  }
  return puVar1;
}


