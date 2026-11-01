/* ROM address: 0x00052600; body bytes: 82; decompiled */

uint FUN_00052600(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 != '\x01') {
    if (DAT_ffffcffb != 1) {
      return (uint)DAT_ffffcffb;
    }
    if (DAT_ffffcfe6 != DAT_ffffcfe4) {
      if (DAT_ffffcfe6 <= DAT_ffffcfe4) {
        return 1;
      }
      uVar1 = FUN_00002478((int)DAT_ffffd149,1);
      DAT_ffffd149 = (char)uVar1;
      return uVar1;
    }
  }
  DAT_ffffd149 = 0;
  return 1;
}


