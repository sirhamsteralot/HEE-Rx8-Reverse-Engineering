/* [ADDITIONAL SOURCE REVIEW]
 * cranking_in_progress_calc [high]: Computes DAT_ffffd15c = (vspeed 0xffffbbb4 within tolerance band of 0) && DAT_ffffaa62(cranking_active)==1 && DAT_ffffa428(engine_running)==1 && (E2-shadow u16 0xffff86e8 < 0xea); increments 0xffff86e8 while set. Feeds cfbc (0x4ed3c) -> cfb6 (0x4ef86) -> PD7 (0x3a0ec). Dynamically high only in cranking scenario.
 * RAM 0xffffd15c cranking_in_progress (uint8): Written by 0x532d0: vspeed 0xffffbbb4 ~0 && cranking_active 0xffffaa62==1 && engine_running 0xffffa428==1 && E2-shadow 0xffff86e8 < 0xea. Pool-anchored at 0x532d0.
 */
/* ROM address: 0x000532d0; body bytes: 148; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00051254 (148 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000532d0(void)

{
  uint uVar1;
  char cVar3;
  undefined4 uVar2;
  
  uVar1 = ref_readValue_16bit_ADDRESS_VAL(&DAT_ffff86e8,0);
  cVar3 = rx8_is_outside_tolerance_band(vehicle_speed_ffffbbb4,0,0x3ff126e9);
  if ((((cVar3 == '\0') && (cranking_active_ffffaa62_ffffaa62 == '\x01')) && (engine_running_ffffa428 == '\x01')) &&
     ((uVar1 & 0xffff) < 0xea)) {
    DAT_ffffd15c = 1;
  }
  else {
    DAT_ffffd15c = 0;
  }
  if ((DAT_ffffd15c == 1) && ((uVar1 & 0xffff) != 0xea)) {
    uVar2 = rx8_add_u16_saturate(uVar1,1);
    uVar1 = ref_updateMemoryAtAddress_16bit_ADDR_VAL(&DAT_ffff86e8,uVar2);
    return uVar1;
  }
  return (uint)DAT_ffffd15c;
}


