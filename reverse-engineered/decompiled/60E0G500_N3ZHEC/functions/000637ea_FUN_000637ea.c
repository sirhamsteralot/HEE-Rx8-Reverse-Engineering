/* ROM address: 0x000637ea; body bytes: 82; decompiled */

int FUN_000637ea(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while (((&DAT_ffff87d8)[uVar1 * 8] != param_1 || (DAT_ffff8928 == uVar1))) {
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 0;
    }
  }
  return (int)(char)(&DAT_ffff87e3)[uVar1 * 0x10];
}


