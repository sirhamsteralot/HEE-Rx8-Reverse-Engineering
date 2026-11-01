/* ROM address: 0x00029950; body bytes: 42; decompiled */

uint FUN_00029950(void)

{
  uint uVar1;
  
  uVar1 = FUN_00009890(&DAT_0004e9d8);
  if ((uVar1 & 0xff) == 0) {
    FUN_0000e040();
    FUN_00029a48();
    FUN_00029a8c();
    uVar1 = FUN_00029bb8();
    return uVar1;
  }
  return uVar1 & 0xff;
}


