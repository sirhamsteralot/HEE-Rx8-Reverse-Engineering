/* ROM address: 0x0005549c; body bytes: 44; decompiled */

uint FUN_0005549c(void)

{
  uint uVar1;
  
  if (DAT_ffff9038 == -0x5b) {
    uVar1 = FUN_0005544a();
    if ((uVar1 & 0xffff) == (uint)DAT_ffff903a) {
      return uVar1 & 0xffff;
    }
  }
  uVar1 = FUN_00055410();
  return uVar1;
}


