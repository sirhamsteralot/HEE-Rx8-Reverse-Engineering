/* ROM address: 0x0004c1ee; body bytes: 212; decompiled */

uint FUN_0004c1ee(void)

{
  uint uVar1;
  
  if (DAT_ffffce9c == '\x01') {
    FUN_0005fd38(0x54,1);
  }
  else if (DAT_ffffce9d == '\x01') {
    FUN_0005fd38(0x54,2);
  }
  if (DAT_ffffce9a == '\x01') {
    FUN_0005fd38(0x55,1);
  }
  else if (DAT_ffffce9d == '\x01') {
    FUN_0005fd38(0x55,2);
  }
  if (DAT_ffffce9b == '\x01') {
    FUN_0005fd38(0x56,1);
  }
  else if (DAT_ffffce9d == '\x01') {
    FUN_0005fd38(0x56,2);
  }
  if (DAT_ffffceaa == '\x01') {
    FUN_0005fd38(0x53,1);
  }
  else if (DAT_ffffceab == '\x01') {
    FUN_0005fd38(0x53,2);
  }
  if (DAT_ffffcea9 == '\x01') {
    uVar1 = FUN_0005fd38(0x57,1);
  }
  else {
    uVar1 = (uint)DAT_ffffcea8;
    if (uVar1 == 1) {
      uVar1 = FUN_0005fd38(0x57,2);
    }
  }
  return uVar1;
}


