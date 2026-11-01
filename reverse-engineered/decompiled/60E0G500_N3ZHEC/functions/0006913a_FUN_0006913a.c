/* ROM address: 0x0006913a; body bytes: 120; decompiled */

void FUN_0006913a(void)

{
  FUN_000693fc(4);
  DAT_ffffde20 = FUN_00002478((int)(char)DAT_ffffde20,1);
  DAT_ffffde1a = DAT_ffffde1a + 7;
  if (DAT_ffffde18 <= DAT_ffffde1a) {
    FUN_000690b4();
    thunk_FUN_000551da((int)DAT_ffffde1c);
    return;
  }
  if ((DAT_ffffde2d != 0) && (DAT_ffffde2d <= DAT_ffffde20)) {
    DAT_ffffde20 = 0;
    DAT_ffffde1d = 7;
    FUN_0006936a(4,0x4b);
    return;
  }
  DAT_ffffde1d = 9;
  FUN_0006936a(2,DAT_ffffde2e);
  return;
}


