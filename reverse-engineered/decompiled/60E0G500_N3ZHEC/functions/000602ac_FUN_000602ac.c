/* ROM address: 0x000602ac; body bytes: 84; decompiled */

uint FUN_000602ac(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar1 = 0;
  uVar3 = 0;
  do {
    if ((&DAT_ffffd5ac)[uVar1] == '\x01') {
      uVar2 = uVar2 + 1;
      if ((uVar1 == 0) || (uVar1 == 1)) {
        uVar3 = uVar3 + 1;
      }
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x8c);
  if ((uVar3 & 0xffff) != 0) {
    uVar2 = (uVar2 - uVar3) + 1;
  }
  if (0xff < (uVar2 & 0xffff)) {
    uVar2 = 0xff;
  }
  return uVar2;
}


