/* ROM address: 0x0004b10c; body bytes: 92; decompiled */

uint FUN_0004b10c(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  bVar1 = DAT_ffffa415;
  DAT_ffffce11 = 0;
  if (DAT_ffffce12 == '\x01') {
    DAT_ffffce11 = 1;
    DAT_ffffce12 = '\0';
    uVar2 = 1;
  }
  else {
    uVar3 = (uint)DAT_ffffa415;
    if (uVar3 == 0) {
      uVar2 = (uint)DAT_ffffce10;
      if (uVar2 == 0x17) {
        DAT_ffffce11 = 1;
      }
    }
    else {
      uVar2 = FUN_00002478((int)(char)DAT_ffffce10,1);
      if ((uVar2 & 0xff) == uVar3) {
        DAT_ffffce11 = 1;
      }
    }
  }
  DAT_ffffce10 = bVar1;
  return uVar2;
}


