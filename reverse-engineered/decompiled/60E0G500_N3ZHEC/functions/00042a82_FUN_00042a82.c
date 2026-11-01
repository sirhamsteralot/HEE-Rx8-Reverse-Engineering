/* ROM address: 0x00042a82; body bytes: 116; decompiled */

undefined * FUN_00042a82(void)

{
  undefined *puVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc9ba = 0;
    DAT_ffffc9bd = 0;
    puVar1 = &DAT_ffffc9da;
    DAT_ffffc9da = 0;
  }
  else {
    if ((DAT_ffffc9d8 == '\x01') && (DAT_ffffc9bf == '\0')) {
      DAT_ffffc9ba = 0x494;
    }
    else if (DAT_ffffc9ba != 0) {
      DAT_ffffc9ba = DAT_ffffc9ba + -1;
    }
    puVar1 = (undefined *)(uint)DAT_ffffc9bc;
    if ((puVar1 == &UNK_00000001) && (DAT_ffffc9ba == 0)) {
      DAT_ffffc9bd = 1;
      DAT_ffffc9da = 1;
    }
    else {
      DAT_ffffc9bd = 0;
    }
  }
  DAT_ffffc9d8 = DAT_ffffc9bf;
  return puVar1;
}


