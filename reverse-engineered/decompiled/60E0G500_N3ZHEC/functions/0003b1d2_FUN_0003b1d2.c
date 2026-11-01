/* ROM address: 0x0003b1d2; body bytes: 90; decompiled */

undefined * FUN_0003b1d2(void)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(uint)DAT_ffffd201;
  if ((puVar1 == &UNK_00000001) || (DAT_ffffbfd4 == '\0')) {
    DAT_ffffc5b1 = 0;
    DAT_ffffc5ae = 0;
  }
  else {
    puVar1 = (undefined *)FUN_00002478((int)(char)DAT_ffffc5ae,1);
    DAT_ffffc5ae = (byte)puVar1;
    if (DAT_ffffc5b8 == '\0') {
      DAT_ffffc5b1 = 0;
    }
    else {
      puVar1 = &DAT_0007a7ba;
      if (0x1f < DAT_ffffc5ae) {
        DAT_ffffc5b1 = 1;
      }
    }
  }
  return puVar1;
}


