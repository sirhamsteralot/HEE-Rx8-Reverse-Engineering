/* ROM address: 0x00049422; body bytes: 40; decompiled */

uint FUN_00049422(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffccfd;
  if (uVar1 == 1) {
    uVar1 = FUN_00002460((int)DAT_ffffccf8,1);
    DAT_ffffccf8 = (short)uVar1;
  }
  else {
    DAT_ffffccf8 = 0;
  }
  return uVar1;
}


