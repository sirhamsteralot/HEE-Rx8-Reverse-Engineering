/* ROM address: 0x000640c4; body bytes: 82; decompiled */

int FUN_000640c4(char param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8936)[uVar1 * 0x34] != param_1 || (DAT_ffff8d74 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff8937)[uVar1 * 0x34];
}


