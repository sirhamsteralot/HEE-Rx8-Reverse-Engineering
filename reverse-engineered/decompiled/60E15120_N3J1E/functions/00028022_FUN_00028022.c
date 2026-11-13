/* ROM address: 0x00028022; body bytes: 54; decompiled */

uint FUN_00028022(void)

{
  uint uVar1;
  undefined1 *puVar2;
  
  uVar1 = (int)sector_parity_bank_ffffb660 & 1;
  puVar2 = &DAT_ffffba26 + uVar1;
  if ((DAT_ffffba50 <= DAT_ffffba80) || (uVar1 = (uint)DAT_ffffb69c, uVar1 != 1)) {
    *puVar2 = 0;
  }
  else {
    *puVar2 = 1;
  }
  return uVar1;
}


