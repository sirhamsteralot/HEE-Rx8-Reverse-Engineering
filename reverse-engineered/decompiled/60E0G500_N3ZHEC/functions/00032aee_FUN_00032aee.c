/* ROM address: 0x00032aee; body bytes: 40; decompiled */

undefined4 FUN_00032aee(void)

{
  undefined4 uVar1;
  
  if (DAT_ffffbff3 == '\x01') {
    DAT_ffffbff2 = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_00002478((int)DAT_ffffbff2,1);
    DAT_ffffbff2 = (char)uVar1;
  }
  return uVar1;
}


