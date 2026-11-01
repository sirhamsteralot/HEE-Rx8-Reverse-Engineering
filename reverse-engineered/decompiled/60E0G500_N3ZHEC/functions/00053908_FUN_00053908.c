/* ROM address: 0x00053908; body bytes: 74; decompiled */

undefined1 * FUN_00053908(void)

{
  ushort uVar1;
  
  uVar1 = FUN_00002460(0x4e,0x10);
  if (DAT_ffffd180 == '\x02') {
    if (uVar1 <= DAT_ffffcfe6) {
      DAT_ffffd184 = 0;
      DAT_ffffd185 = 1;
      return &DAT_0007d7f3;
    }
    DAT_ffffd184 = 1;
  }
  else {
    DAT_ffffd184 = 0;
  }
  DAT_ffffd185 = 0;
  return &DAT_0007d7f3;
}


