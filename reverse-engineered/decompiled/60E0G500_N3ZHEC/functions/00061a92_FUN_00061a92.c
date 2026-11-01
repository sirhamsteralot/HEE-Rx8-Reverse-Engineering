/* ROM address: 0x00061a92; body bytes: 266; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00061a92(void)

{
  char cVar1;
  
  FUN_00064cd4();
  if ((DAT_ffff8ea4 == '\x01') && (DAT_ffff87b4._0_1_ == '\0')) {
    DAT_ffff87b4 = FUN_00002420(1);
    cVar1 = FUN_00063a2e(0);
    while (cVar1 == '\x01') {
      FUN_00062b44((int)(short)DAT_ffffd7cc);
      cVar1 = (&DAT_0007ded2)[DAT_ffffd7cc];
      if (cVar1 == '\0') {
        FUN_0006144a(&DAT_ffffd7cc);
      }
      else if (cVar1 == '\x01') {
        FUN_000650bc(&DAT_ffffd7cc);
      }
      else if (cVar1 == '\x02') {
        FUN_00065116(&DAT_ffffd7cc);
      }
      else if (cVar1 == '\x03') {
        FUN_000647ae(&DAT_ffffd7cc);
      }
      FUN_00060e62();
      FUN_00062f44();
      cVar1 = FUN_00063a2e(1);
    }
    FUN_0006123a();
  }
  FUN_00064d00();
  _DAT_ffff8ea4 = FUN_00002420(0);
  FUN_000646a0();
  cVar1 = DAT_ffff8ea6;
  _DAT_ffff8ea6 = FUN_00002420(0);
  FUN_000627e4((int)cVar1);
  FUN_00060d36();
  DAT_ffff87b4 = FUN_00002420(0);
  return;
}


