/* ROM address: 0x000565fa; body bytes: 84; decompiled */

uint FUN_000565fa(char param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; ((&DAT_0005f7f9)[(uVar1 & 0xff) * 6] != param_1 && ((uVar1 & 0xff) < 3));
      uVar1 = uVar1 + 1) {
  }
  if (((uVar1 & 0xff) < 3) && ((DAT_ffffd3f0 & (&DAT_0005f7fc)[(uVar1 & 0xff) * 3]) == 0)) {
    uVar1 = 3;
  }
  return uVar1;
}


