/* ROM address: 0x0003d328; body bytes: 44; decompiled */

uint FUN_0003d328(void)

{
  uint uVar1;
  
  if (DAT_ffffc616 == '\x01') {
    uVar1 = FUN_0005fd38(0x4a,1);
    return uVar1;
  }
  if (DAT_ffffc617 == 1) {
    uVar1 = FUN_0005fd38(0x4a,2);
    return uVar1;
  }
  return (uint)DAT_ffffc617;
}


