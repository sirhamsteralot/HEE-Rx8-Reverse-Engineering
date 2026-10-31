/* ROM address: 0x00042766; body bytes: 132; decompiled */

uint FUN_00042766(void)

{
  uint uVar1;
  
  if (DAT_ffffc96d == '\x01') {
    FUN_0005fd38(0x1b,1);
  }
  else if (DAT_ffffc96c == '\x01') {
    FUN_0005fd38(0x1b,2);
  }
  if (DAT_ffffc96f == '\x01') {
    FUN_0005fd38(0x1a,1);
  }
  else if (DAT_ffffc96e == '\x01') {
    FUN_0005fd38(0x1a,2);
  }
  if (DAT_ffffc971 == '\x01') {
    uVar1 = FUN_0005fd38(0x19,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc970;
    if (uVar1 == 1) {
      uVar1 = FUN_0005fd38(0x19,2);
    }
  }
  return uVar1;
}


