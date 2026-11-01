/* ROM address: 0x00032506; body bytes: 40; decompiled */

uint FUN_00032506(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffa41c;
  if (uVar1 == 1) {
    uVar1 = FUN_00002460((int)DAT_ffffbfd6,1);
    DAT_ffffbfd6 = (short)uVar1;
  }
  else {
    DAT_ffffbfd6 = 0;
  }
  return uVar1;
}


