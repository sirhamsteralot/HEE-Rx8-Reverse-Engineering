/* ROM address: 0x00019ccc; body bytes: 50; decompiled */

void FUN_00019ccc(void)

{
  if (DAT_ffffc656 == '\0') {
    DAT_ffffaa14 = DAT_ffffaa0c;
    DAT_ffffaa18 = DAT_ffffaa0c;
  }
  else {
    DAT_ffffaa14 = 0x42a00000;
    DAT_ffffaa18 = 0x41f00000;
  }
  DAT_ffffaa10 = DAT_ffffaa14;
  return;
}


