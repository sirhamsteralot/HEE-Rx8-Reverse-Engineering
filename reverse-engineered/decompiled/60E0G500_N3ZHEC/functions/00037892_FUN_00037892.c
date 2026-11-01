/* ROM address: 0x00037892; body bytes: 70; decompiled */

void FUN_00037892(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_fffff430;
  DAT_ffffc2e7 = (undefined1)((uVar1 & (uint)&PTR_FUN_0000ff00) >> 8);
  if ((uVar1 & (uint)&PTR_FUN_0000ff00) == 0) {
    DAT_ffffc2e7 = 0x5a;
  }
  DAT_ffffc2b4 = 1;
  uVar2 = FUN_00036420((int)DAT_ffffc2ea);
  DAT_ffffc2ef = (char)((uint)uVar2 >> 0x10);
  DAT_ffffc2f0 = (char)((uint)uVar2 >> 8);
  DAT_ffffc2f1 = (char)uVar2;
  return;
}


