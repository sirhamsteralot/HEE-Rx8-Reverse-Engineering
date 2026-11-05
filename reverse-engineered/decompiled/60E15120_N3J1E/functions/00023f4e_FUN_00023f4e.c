/* ROM address: 0x00023f4e; body bytes: 772; decompiled */

uint e2ram_stored_dtc_replay(void)

{
  uint uVar1;
  
  if (DAT_ffffb500 == '\x01') {
    FUN_0005fd38(0x14,1);
  }
  else if (DAT_ffffb501 == '\x01') {
    FUN_0005fd38(0x14,2);
  }
  if (DAT_ffffb503 == '\x01') {
    FUN_0005fd38(0x13,1);
  }
  else if (DAT_ffffb504 == '\x01') {
    FUN_0005fd38(0x13,2);
  }
  if (DAT_ffffb50a == '\x01') {
    FUN_0005fd38(0x6a,1);
  }
  else if (DAT_ffffb50b == '\x01') {
    FUN_0005fd38(0x6a,2);
  }
  if (DAT_ffffb505 == '\x01') {
    FUN_0005fd38(0x22,1);
  }
  else if (DAT_ffffb506 == '\x01') {
    FUN_0005fd38(0x22,2);
  }
  if (DAT_ffffb507 == '\x01') {
    FUN_0005fd38(0x21,1);
  }
  else if (DAT_ffffb508 == '\x01') {
    FUN_0005fd38(0x21,2);
  }
  if (DAT_ffffb4f0 == '\x01') {
    FUN_0005fd38(0x47,1);
  }
  else if (DAT_ffffb4f1 == '\x01') {
    FUN_0005fd38(0x47,2);
  }
  if (DAT_ffffb4f3 == '\x01') {
    FUN_0005fd38(100,1);
  }
  else if (DAT_ffffb4f4 == '\x01') {
    FUN_0005fd38(100,2);
  }
  if (DAT_ffffb4f5 == '\x01') {
    FUN_0005fd38(0x5d,1);
  }
  else if (DAT_ffffb4f6 == '\x01') {
    FUN_0005fd38(0x5d,2);
  }
  if (DAT_ffffb4f7 == '\x01') {
    FUN_0005fd38(0x5b,1);
  }
  else if (DAT_ffffb4f8 == '\x01') {
    FUN_0005fd38(0x5b,2);
  }
  if (DAT_ffffb4f9 == '\x01') {
    FUN_0005fd38(0x5c,1);
  }
  else if (DAT_ffffb4fa == '\x01') {
    FUN_0005fd38(0x5c,2);
  }
  if (DAT_ffffb4fb == '\x01') {
    FUN_0005fd38(0x83,1);
  }
  else if (DAT_ffffb4fc == '\x01') {
    FUN_0005fd38(0x83,2);
  }
  if (DAT_ffffb4fd == '\x01') {
    FUN_0005fd38(0x65,1);
  }
  else if (DAT_ffffb4fe == '\x01') {
    FUN_0005fd38(0x65,2);
  }
  if (DAT_ffffb50c == '\x01') {
    FUN_0005fd38(0x4f,1);
  }
  else if (DAT_ffffb50d == '\x01') {
    FUN_0005fd38(0x4f,2);
  }
  if (DAT_ffffb50e == '\x01') {
    FUN_0005fd38(0x61,1);
  }
  else if (DAT_ffffb50f == '\x01') {
    FUN_0005fd38(0x61,2);
  }
  if (DAT_ffffb510 == '\x01') {
    FUN_0005fd38(0x5f,1);
  }
  else if (DAT_ffffb511 == '\x01') {
    FUN_0005fd38(0x5f,2);
  }
  if (DAT_ffffb512 == '\x01') {
    FUN_0005fd38(0x60,1);
  }
  else if (DAT_ffffb513 == '\x01') {
    FUN_0005fd38(0x60,2);
  }
  if (DAT_ffffb514 == '\x01') {
    FUN_0005fd38(0x6b,1);
  }
  else if (DAT_ffffb515 == '\x01') {
    FUN_0005fd38(0x6b,2);
  }
  if (DAT_ffffb518 == '\x01') {
    FUN_0005fd38(0x42,1);
  }
  else if (DAT_ffffb519 == '\x01') {
    FUN_0005fd38(0x42,2);
  }
  if (DAT_ffffb516 == '\x01') {
    uVar1 = FUN_0005fd38(0x84,1);
  }
  else {
    uVar1 = (uint)DAT_ffffb517;
    if (uVar1 == 1) {
      uVar1 = FUN_0005fd38(0x84,2);
    }
  }
  return uVar1;
}


