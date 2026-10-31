/* ROM address: 0x00036540; body bytes: 230; decompiled */

undefined2 * FUN_00036540(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(uint)DAT_ffffc1d2;
  if (puVar1 == (undefined2 *)((int)&vector_usr_break + 3)) {
    if ((DAT_ffffc25f == '\0') &&
       (puVar1 = (undefined2 *)(uint)DAT_ffffc260,
       puVar1 == (undefined2 *)((int)&vector_Poweron_Reset + 1))) {
      DAT_ffffc1d2 = 0x55;
      DAT_ffffc275 = DAT_ffffc275 | 2;
      puVar1 = (undefined2 *)&DAT_ffffc23e;
      DAT_ffffc260 = 0;
      DAT_ffffc23e = 1;
    }
  }
  else if (((puVar1 == (undefined2 *)0x55) &&
           (puVar1 = (undefined2 *)-(((DAT_ffffc275 & 2) == 0) - 1),
           puVar1 == (undefined2 *)((int)&vector_Poweron_Reset + 1))) &&
          (puVar1 = (undefined2 *)(uint)DAT_ffffc23d,
          puVar1 == (undefined2 *)((int)&vector_Poweron_Reset + 1))) {
    DAT_ffffc24c = 1;
    FUN_000368f0();
    puVar1 = &DAT_ffffc232;
    if (DAT_ffffc24a == DAT_ffffc232) {
      DAT_ffffc1d2 = 0xaa;
      puVar1 = (undefined2 *)((int)(char)DAT_ffffc275 & 0xfd);
      DAT_ffffc275 = (byte)puVar1;
      DAT_ffffc23b = 0;
      DAT_ffffc276 = 0;
      DAT_ffffc242 = 1;
    }
    else {
      DAT_ffffc23b = 1;
      if (DAT_ffffc278 != 0xff) {
        DAT_ffffc278 = DAT_ffffc278 + 1;
      }
      if (1 < DAT_ffffc278) {
        DAT_ffffc276 = 0;
        DAT_ffffc242 = 1;
        DAT_ffffc239 = 1;
        DAT_ffffc279 = 200;
        DAT_ffffc278 = 0;
        DAT_ffffc240 = 1;
        puVar1 = (undefined2 *)FUN_0003636c();
      }
    }
    DAT_ffffc23e = 1;
  }
  return puVar1;
}


