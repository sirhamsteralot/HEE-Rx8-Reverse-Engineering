/* ROM address: 0x00049fde; body bytes: 66; decompiled */

void FUN_00049fde(void)

{
  if (DAT_ffffcd60 == '\0') {
    DAT_ffffcd72 = 0;
  }
  else if (DAT_ffffae98 == '\x01') {
    DAT_ffffcd72 = FUN_00002460((int)DAT_ffffcd72,1);
  }
  else if (DAT_ffffad98 < 0.5) {
    DAT_ffffcd72 = 0;
  }
  return;
}


