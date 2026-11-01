/* ROM address: 0x00029742; body bytes: 42; decompiled */

void FUN_00029742(void)

{
  DAT_ffffbb1c = DAT_ffffbb1c + 1;
  if (0x18 < DAT_ffffbb1c) {
    FUN_000297ac();
    FUN_00029774();
    DAT_ffffbb1c = 0;
  }
  return;
}


