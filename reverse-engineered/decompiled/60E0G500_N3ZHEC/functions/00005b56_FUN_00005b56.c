/* ROM address: 0x00005b56; body bytes: 98; decompiled */

uint FUN_00005b56(void)

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = DAT_fffff6ea;
  if (((uVar1 & 2) == 2) && (uVar1 = DAT_fffff6e8, (uVar1 & 2) == 2)) {
    DAT_fffff6e8 = 0xd;
    FUN_00005348(0xb4);
  }
  uVar1 = DAT_fffff6ea;
  uVar2 = uVar1 & 8;
  if ((uVar2 == 8) && (uVar1 = DAT_fffff6e8, uVar2 = uVar1 & 8, uVar2 == 8)) {
    DAT_fffff6e8 = 7;
    uVar2 = FUN_00005348(0xb4);
    return uVar2;
  }
  return uVar2;
}


