/* ROM address: 0x00025e86; body bytes: 178; decompiled */

undefined * FUN_00025e86(void)

{
  undefined *puVar1;
  
  if (DAT_ffffaae0 == '\x01') {
    if (DAT_ffffb5ea != '\0') {
      FUN_0003ebc0(&DAT_ffff812c,0);
      puVar1 = (undefined *)FUN_00009efe();
      return puVar1;
    }
    puVar1 = &UNK_0000005a;
    DAT_ffffdf99 = 0x5a;
    DAT_ffffb5f0 = 0;
    DAT_ffffb5e9 = 1;
  }
  else if (DAT_ffffb5ea == '\0') {
    DAT_ffffb5ec = 0;
    DAT_ffffb5ea = '\x01';
    DAT_ffffb5e8 = 1;
    puVar1 = &DAT_ffffb5e8;
    DAT_ffffb5f0 = DAT_ffffb5f0 + 1;
  }
  else {
    if (DAT_ffffb5ec != 0xffffffff) {
      DAT_ffffb5ec = DAT_ffffb5ec + 1;
    }
    if ((0x36ee7 < DAT_ffffb5ec) ||
       ((puVar1 = &UNK_00000019, 0x18 < DAT_ffffb5ec &&
        (puVar1 = &DAT_ffffb5f3, DAT_ffffb5f2 <= DAT_ffffb5f3)))) {
      DAT_ffffb5ea = 2;
      FUN_0003ebc0(&DAT_ffff812c,1);
      DAT_ffffb5e9 = 0;
      DAT_ffffdf99 = 0;
      puVar1 = (undefined *)FUN_00009ea2();
      return puVar1;
    }
  }
  return puVar1;
}


