/* ROM address: 0x0003633e; body bytes: 120; decompiled */

void FUN_0003633e(void)

{
  DAT_ffffc24c = FUN_00036420(DAT_ffffc2e0,DAT_ffffc278);
  DAT_ffffc250 = FUN_00036420(DAT_ffffc2e0 >> 0x10,DAT_ffffc278 >> 8);
  DAT_ffffc254 = FUN_00036420(DAT_ffffc2dc,DAT_ffffc278 >> 0x10);
  DAT_ffffc258 = FUN_00036420(DAT_ffffc2dc >> 0x10,DAT_ffffc278 >> 0x18);
  DAT_ffffc260 = DAT_ffffc24c | 0x1000000;
  DAT_ffffc264 = DAT_ffffc250 | 0x2000000;
  DAT_ffffc268 = DAT_ffffc254 | 0x3000000;
  DAT_ffffc26c = DAT_ffffc258 | 0x4000000;
  return;
}


