/* ROM address: 0x0003e40c; body bytes: 44; decompiled */

uint FUN_0003e40c(void)

{
  uint uVar1;
  
  if (DAT_ffffc68e == '\x01') {
    uVar1 = FUN_000604dc(0x3a,1);
    return uVar1;
  }
  if (DAT_ffffc68f == 1) {
    uVar1 = FUN_000604dc(0x3a,2);
    return uVar1;
  }
  return (uint)DAT_ffffc68f;
}


