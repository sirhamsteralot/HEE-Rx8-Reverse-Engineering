/* ROM address: 0x00037406; body bytes: 70; decompiled */

undefined * FUN_00037406(void)

{
  undefined *puVar1;
  undefined *in_r0;
  
  if ((DAT_ffffc2b6 == '\0') && (in_r0 = (undefined *)(uint)DAT_ffffb5e8, in_r0 != &UNK_00000001)) {
    if (DAT_ffffc2e6 != '\0') {
      DAT_ffffc2e6 = DAT_ffffc2e6 + -1;
      DAT_ffffc2b2 = 1;
      in_r0 = (undefined *)(int)DAT_ffffc2e6;
      if ((in_r0 == (undefined *)0x0) &&
         (in_r0 = (undefined *)(uint)DAT_ffffc242, in_r0 == &UNK_00000055)) {
        puVar1 = (undefined *)(uint)DAT_ffffc242;
        if (puVar1 != &UNK_00000033) {
          DAT_ffffc242 = 0x33;
          DAT_ffffc2e5 = DAT_ffffc2e5 & 0xfd;
          DAT_ffffc2b7 = 0;
          DAT_ffffc2a4 = 0;
          puVar1 = &DAT_ffffc2ac;
          DAT_ffffc2ac = 0;
          DAT_ffffc2ae = 1;
          DAT_ffffc2a8 = 0;
        }
        return puVar1;
      }
    }
  }
  return in_r0;
}


