/* ROM address: 0x00035312; body bytes: 58; decompiled */

uint FUN_00035312(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_ffffb13a;
  uVar2 = (uint)DAT_ffffb13a;
  if (uVar2 == 1) {
    if (DAT_ffffc208 == '\0') {
      DAT_ffffc1d8 = 0;
    }
    else {
      uVar2 = FUN_00002460((int)DAT_ffffc1d8,1);
      DAT_ffffc1d8 = (short)uVar2;
    }
  }
  DAT_ffffc208 = bVar1;
  return uVar2;
}


