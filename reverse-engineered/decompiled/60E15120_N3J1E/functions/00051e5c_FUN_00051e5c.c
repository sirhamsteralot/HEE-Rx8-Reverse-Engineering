/* ROM address: 0x00051e5c; body bytes: 82; decompiled */

uint FUN_00051e5c(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 != '\x01') {
    if (DAT_ffffcfbf != 1) {
      return (uint)DAT_ffffcfbf;
    }
    if (DAT_ffffcfaa != DAT_ffffcfa8) {
      if (DAT_ffffcfaa <= DAT_ffffcfa8) {
        return 1;
      }
      uVar1 = rx8_add_u8_saturate((int)DAT_ffffd10d,1);
      DAT_ffffd10d = (char)uVar1;
      return uVar1;
    }
  }
  DAT_ffffd10d = 0;
  return 1;
}


