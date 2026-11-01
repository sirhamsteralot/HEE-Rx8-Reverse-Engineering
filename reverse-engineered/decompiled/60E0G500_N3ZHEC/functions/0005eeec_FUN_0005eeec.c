/* ROM address: 0x0005eeec; body bytes: 74; decompiled */

uint FUN_0005eeec(void)

{
  uint uVar1;
  char local_8 [8];
  
  uVar1 = FUN_00038ed8(0x9f,local_8,1);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 0) {
    uVar1 = (int)local_8[0] & 1;
    if (((uVar1 == 0) && (DAT_ffffd1f1 == '\0')) && (uVar1 = (uint)DAT_ffffd1f4, uVar1 == 0)) {
      DAT_ffffd3d8 = 1;
    }
    else {
      DAT_ffffd3d8 = 0;
    }
  }
  return uVar1;
}


