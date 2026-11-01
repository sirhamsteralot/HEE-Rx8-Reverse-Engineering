/* ROM address: 0x0003f706; body bytes: 108; decompiled */

void FUN_0003f706(void)

{
  DAT_ffffc700 = FUN_00002068(DAT_ffffaa88,&DAT_0006bb5c);
  if (DAT_ffffc6bf == '\0') {
    DAT_ffffc704 = 0x3f800000;
  }
  else {
    DAT_ffffc704 = FUN_00002068(DAT_ffffaa10,&DAT_0006bb70);
  }
  if (DAT_ffffb13a == '\x01') {
    DAT_ffffc708 = 100.0;
  }
  else {
    DAT_ffffc714 = (float)FUN_000020dc(DAT_ffffb5b8,DAT_ffffc12c,&DAT_0006bb84);
    DAT_ffffc708 = DAT_ffffc6d4 + DAT_ffffc6d8 + DAT_ffffc714;
  }
  FUN_0003f966();
  return;
}


