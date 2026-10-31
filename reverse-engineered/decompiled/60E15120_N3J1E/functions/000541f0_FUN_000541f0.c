/* ROM address: 0x000541f0; body bytes: 452; decompiled */

uint FUN_000541f0(void)

{
  uint uVar1;
  
  if (DAT_ffffd0f4 == '\x01') {
    FUN_0005fd38(0x2d,1);
  }
  else if (DAT_ffffd0f5 == '\x01') {
    FUN_0005fd38(0x2d,2);
  }
  if (DAT_ffffd045 == '\x01') {
    FUN_0005fd38(0x2e,1);
  }
  else if (DAT_ffffd046 == '\x01') {
    FUN_0005fd38(0x2e,2);
  }
  if (DAT_ffffd115 == '\x01') {
    FUN_0005fd38(0x30,1);
  }
  else if (DAT_ffffd116 == '\x01') {
    FUN_0005fd38(0x30,2);
  }
  if (DAT_ffffd042 == '\x01') {
    FUN_0005fd38(0x31,1);
  }
  else if (DAT_ffffd043 == '\x01') {
    FUN_0005fd38(0x31,2);
  }
  if (DAT_ffffd0a9 == '\x01') {
    FUN_0005fd38(0x32,1);
  }
  else if (DAT_ffffd0aa == '\x01') {
    FUN_0005fd38(0x32,2);
  }
  if (DAT_ffffd117 == '\x01') {
    FUN_0005fd38(0x77,1);
  }
  else if (DAT_ffffd118 == '\x01') {
    FUN_0005fd38(0x77,2);
  }
  if (DAT_ffffd119 == '\x01') {
    FUN_0005fd38(0x7a,1);
  }
  else if (DAT_ffffd11a == '\x01') {
    FUN_0005fd38(0x7a,2);
  }
  if (DAT_ffffd112 == '\x01') {
    FUN_0005fd38(0x78,1);
  }
  else if (DAT_ffffd114 == '\x01') {
    FUN_0005fd38(0x78,2);
  }
  if (DAT_ffffd113 == '\x01') {
    FUN_0005fd38(0x79,1);
  }
  else if (DAT_ffffd114 == '\x01') {
    FUN_0005fd38(0x79,2);
  }
  if (DAT_ffffd10f == '\x01') {
    FUN_0005fd38(0x75,1);
  }
  else if (DAT_ffffd111 == 1) {
    FUN_0005fd38(0x75,2);
  }
  if (DAT_ffffd110 == '\x01') {
    uVar1 = FUN_0005fd38(0x76,1);
  }
  else {
    uVar1 = (uint)DAT_ffffd111;
    if (uVar1 == 1) {
      uVar1 = FUN_0005fd38(0x76,2);
    }
  }
  return uVar1;
}


