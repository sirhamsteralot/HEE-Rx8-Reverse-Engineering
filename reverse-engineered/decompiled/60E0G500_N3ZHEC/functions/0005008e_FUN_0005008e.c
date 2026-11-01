/* ROM address: 0x0005008e; body bytes: 44; decompiled */

uint FUN_0005008e(void)

{
  uint uVar1;
  byte bVar2;
  
  bVar2 = -((((int)DAT_ffffcff1 & 0x80U) == 0) + -1);
  uVar1 = (uint)bVar2;
  if ((uVar1 == 1) && (DAT_ffffd04d == '\0')) {
    uVar1 = (uint)DAT_ffffa426;
    DAT_ffffd048 = DAT_ffffa426;
  }
  DAT_ffffd04d = bVar2;
  return uVar1;
}


