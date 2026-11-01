/* ROM address: 0x00037354; body bytes: 58; decompiled */

undefined * FUN_00037354(void)

{
  undefined *puVar1;
  
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


