/* ROM address: 0x00056586; body bytes: 72; decompiled */

uint FUN_00056586(char param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; ((&DAT_0005f7e4)[(uVar1 & 0xff) * 4] != param_1 && ((uVar1 & 0xff) < 5));
      uVar1 = uVar1 + 1) {
  }
  if (((uVar1 & 0xff) < 5) && ((DAT_ffffd3f0 & (&DAT_0005f7e6)[(uVar1 & 0xff) * 2]) == 0)) {
    uVar1 = 5;
  }
  return uVar1;
}


