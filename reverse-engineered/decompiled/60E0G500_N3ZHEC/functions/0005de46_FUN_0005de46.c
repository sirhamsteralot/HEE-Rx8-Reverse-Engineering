/* ROM address: 0x0005de46; body bytes: 54; decompiled */

uint FUN_0005de46(short param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xff;
  uVar1 = 0;
  while (((uVar1 & 0xff) < 0x1a && ((uVar2 & 0xff) == 0xff))) {
    if ((&DAT_0005fecc)[(uVar1 & 0xff) * 8] == param_1) {
      uVar2 = uVar1;
    }
    uVar1 = uVar1 + 1;
  }
  return uVar2;
}


