/* [ADDITIONAL SOURCE REVIEW]
 * misfire_event_arm_secondary [high]: Per rotor bank: if DAT_ffffba50 <= DAT_ffffba80 || DAT_ffffb69c != 1 -> (&DAT_ffffba26)[parity] = 0 else 1. Secondary arm flag on the ba50/ba80 path. Called from 0x287aa.
 * RAM 0xffffba26 misfire_event_flag_b (uint8[2]): Secondary per-rotor event flags on the DAT_ffffba50/0xffffba80 path; checked/cleared by 0x4489c (load-limit thresholds).
 */
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


