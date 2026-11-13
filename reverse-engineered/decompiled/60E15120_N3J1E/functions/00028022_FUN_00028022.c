/* ROM address: 0x00028022; body bytes: 54; decompiled */

uint misfire_event_arm_secondary(void)

{
  uint uVar1;
  undefined1 *puVar2;
  
  uVar1 = (int)sector_parity_bank_ffffb660 & 1;
  puVar2 = &misfire_event_flag_b_ffffba26 + uVar1;
  if ((DAT_ffffba50 <= DAT_ffffba80) || (uVar1 = (uint)DAT_ffffb69c, uVar1 != 1)) {
    *puVar2 = 0;
  }
  else {
    *puVar2 = 1;
  }
  return uVar1;
}


