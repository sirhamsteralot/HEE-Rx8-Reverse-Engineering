/* ROM address: 0x0000031c; body bytes: 28; decompiled */

byte FUN_0000031c(void)

{
  byte bVar1;
  ushort uVar2;
  
  bVar1 = DAT_ffffec10;
  if ((bVar1 & 0x80) != 0) {
    Ramffffec10 = 0xa53c;
    uVar2 = DAT_fffff738;
    DAT_fffff738 = uVar2 ^ 0x8000;
  }
  return bVar1;
}


