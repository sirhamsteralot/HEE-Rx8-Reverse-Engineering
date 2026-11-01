/* ROM address: 0x00007724; body bytes: 84; decompiled */

uint FUN_00007724(void)

{
  uint uVar1;
  
  DAT_ffff9f95 = 0x24;
  DAT_ffff9fc1 = 0;
  DAT_ffff9fb0 = 0xffffffff;
  DAT_ffff9fc2 = 0;
  DAT_ffff9fbc = 0;
  DAT_ffff9fc5 = 0;
  DAT_ffff9fa1 = 0;
  FUN_00007b58();
  if (DAT_ffff9fc0 == 1) {
    DAT_ffff9fc0 = 0;
    if (DAT_ffff9fa3 != '\x02') {
      FUN_00007c0c();
    }
    uVar1 = FUN_00007b84();
    return uVar1;
  }
  return (uint)DAT_ffff9fc0;
}


