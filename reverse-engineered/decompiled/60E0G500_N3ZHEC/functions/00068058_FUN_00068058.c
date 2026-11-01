/* ROM address: 0x00068058; body bytes: 84; decompiled */

int FUN_00068058(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff8ec8)[uVar1 * 0x14] != param_1 || (DAT_ffff8fc0 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (6 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff8ece)[uVar1 * 0x28];
}


