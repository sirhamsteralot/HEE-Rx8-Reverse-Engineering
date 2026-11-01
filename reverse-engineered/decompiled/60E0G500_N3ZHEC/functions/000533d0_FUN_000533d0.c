/* ROM address: 0x000533d0; body bytes: 94; decompiled */

uint FUN_000533d0(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if (DAT_ffffd201 != '\x01') {
    if (DAT_ffffcffb != 1) {
      return (uint)DAT_ffffcffb;
    }
    if ((uint)(int)DAT_ffffcfe6 <= (uint)(int)DAT_ffffcfe4) {
      return (int)DAT_ffffcfe6;
    }
    if ((int)DAT_ffffd034 != 0) {
      return (int)DAT_ffffd034;
    }
    uVar1 = 0;
    if (DAT_ffffd01c < DAT_ffffd028 - DAT_ffffd168) {
      uVar1 = FUN_00002478((int)DAT_ffffd16c,1);
      DAT_ffffd16c = (char)uVar1;
      return uVar1;
    }
  }
  DAT_ffffd16c = 0;
  return uVar1;
}


