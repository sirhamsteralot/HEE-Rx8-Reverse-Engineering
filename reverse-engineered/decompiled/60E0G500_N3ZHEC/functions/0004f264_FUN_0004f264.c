/* ROM address: 0x0004f264; body bytes: 80; decompiled */

uint FUN_0004f264(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffd002;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffcfe4, uVar1 < (uint)(int)DAT_ffffcfe6)) {
    if (DAT_ffffd020 < DAT_ffffd01c) {
      if ((DAT_ffffd034 == '\0') && (DAT_ffffcfed != '\0')) {
        DAT_ffffcfed = DAT_ffffcfed + -1;
      }
    }
    else {
      uVar1 = 8;
      DAT_ffffcfed = '\b';
    }
  }
  return uVar1;
}


