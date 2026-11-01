/* ROM address: 0x00051a66; body bytes: 42; decompiled */

uint FUN_00051a66(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = (uint)DAT_ffffcff1;
  bVar2 = -(((uVar1 & 0x80) == 0) + -1);
  if ((DAT_ffffd111 == '\0') && (uVar1 = (uint)bVar2, uVar1 == 1)) {
    DAT_ffffd0e5 = 0;
    DAT_ffffd0e6 = 0;
  }
  DAT_ffffd111 = bVar2;
  return uVar1;
}


