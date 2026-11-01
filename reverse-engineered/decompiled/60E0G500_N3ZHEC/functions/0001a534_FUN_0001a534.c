/* ROM address: 0x0001a534; body bytes: 40; decompiled */

uint FUN_0001a534(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffaae0;
  if (uVar1 == 1) {
    uVar1 = FUN_00002460((int)DAT_ffffaa7c,1);
    DAT_ffffaa7c = (short)uVar1;
  }
  else {
    DAT_ffffaa7c = 0;
  }
  return uVar1;
}


