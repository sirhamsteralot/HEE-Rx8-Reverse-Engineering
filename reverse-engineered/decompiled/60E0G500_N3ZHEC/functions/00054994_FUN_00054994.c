/* ROM address: 0x00054994; body bytes: 452; decompiled */

uint FUN_00054994(void)

{
  uint uVar1;
  
  if (DAT_ffffd130 == '\x01') {
    FUN_000604dc(0x2d,1);
  }
  else if (DAT_ffffd131 == '\x01') {
    FUN_000604dc(0x2d,2);
  }
  if (DAT_ffffd081 == '\x01') {
    FUN_000604dc(0x2e,1);
  }
  else if (DAT_ffffd082 == '\x01') {
    FUN_000604dc(0x2e,2);
  }
  if (DAT_ffffd151 == '\x01') {
    FUN_000604dc(0x30,1);
  }
  else if (DAT_ffffd152 == '\x01') {
    FUN_000604dc(0x30,2);
  }
  if (DAT_ffffd07e == '\x01') {
    FUN_000604dc(0x31,1);
  }
  else if (DAT_ffffd07f == '\x01') {
    FUN_000604dc(0x31,2);
  }
  if (DAT_ffffd0e5 == '\x01') {
    FUN_000604dc(0x32,1);
  }
  else if (DAT_ffffd0e6 == '\x01') {
    FUN_000604dc(0x32,2);
  }
  if (DAT_ffffd153 == '\x01') {
    FUN_000604dc(0x77,1);
  }
  else if (DAT_ffffd154 == '\x01') {
    FUN_000604dc(0x77,2);
  }
  if (DAT_ffffd155 == '\x01') {
    FUN_000604dc(0x7a,1);
  }
  else if (DAT_ffffd156 == '\x01') {
    FUN_000604dc(0x7a,2);
  }
  if (DAT_ffffd14e == '\x01') {
    FUN_000604dc(0x78,1);
  }
  else if (DAT_ffffd150 == '\x01') {
    FUN_000604dc(0x78,2);
  }
  if (DAT_ffffd14f == '\x01') {
    FUN_000604dc(0x79,1);
  }
  else if (DAT_ffffd150 == '\x01') {
    FUN_000604dc(0x79,2);
  }
  if (DAT_ffffd14b == '\x01') {
    FUN_000604dc(0x75,1);
  }
  else if (DAT_ffffd14d == 1) {
    FUN_000604dc(0x75,2);
  }
  if (DAT_ffffd14c == '\x01') {
    uVar1 = FUN_000604dc(0x76,1);
  }
  else {
    uVar1 = (uint)DAT_ffffd14d;
    if (uVar1 == 1) {
      uVar1 = FUN_000604dc(0x76,2);
    }
  }
  return uVar1;
}


