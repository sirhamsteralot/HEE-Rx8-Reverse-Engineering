/* [ADDITIONAL SOURCE REVIEW]
 * cranking_in_progress_calc [high]: Writes 0xffffd15c: reads u16 0xffff86e8 (0x532d8 jsr pool 0x53378 = 0x3db94) and vehicle speed 0xffffbbb4 (pool 0x53366), tests it against a 1.884-wide tolerance band around zero (f32 pool slot 0x5337c, bits 0x3ff126e9; band test 0x2440 via pool 0x53380), requires 0xffffaa62 == 1 (pool 0x5336a, cmp/eq at 0x532fe) and 0xffffa428 == 1 (pool 0x5336c, cmp/eq at 0x5330a), then compares the u16 against ROM 0x7dc9e = 234 (0x53310, cmp/ge at 0x5331a); sets the flag at 0x53328-0x5332c and saturating-adds 1 (pool 0x5338c = 0x2460) while set.
 * RAM 0xffffd15c cranking_in_progress (uint8): Written by 0x532d0: vspeed 0xffffbbb4 ~0 && cranking_active 0xffffaa62==1 && engine_running 0xffffa428==1 && E2-shadow 0xffff86e8 < 0xea. Pool-anchored at 0x532d0.
 * RAM 0xffff86e8 candidate_cranking_dwell_accumulator (uint16): u16 read through 0x3db94 at 0x532d8 and saturating-incremented through 0x2460 at 0x5334e while the cranking flag is set and the count has not reached 234 (ROM 0x7dc9e, cmp/ge at 0x5331a). Stored as a validated pair: value at 0xffff86e8 plus its one's complement at 0xffff86ea, written by 0x3dc80 (0x3dc82-0x3dc8a) and validated by 0x3db94 (cmp/eq at 0x3dbb2), which returns 0 when the halves disagree.
 */
/* ROM address: 0x000532d0; body bytes: 148; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00051254 (148 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint cranking_in_progress_calc(void)

{
  uint uVar1;
  char cVar3;
  undefined4 uVar2;
  
  uVar1 = ref_readValue_16bit_ADDRESS_VAL(&candidate_cranking_dwell_accumulator_ffff86e8,0);
  cVar3 = rx8_is_outside_tolerance_band(vehicle_speed_ffffbbb4,0,0x3ff126e9);
  if ((((cVar3 == '\0') && (cranking_active_ffffaa62_ffffaa62 == '\x01')) && (engine_running_ffffa428 == '\x01')) &&
     ((uVar1 & 0xffff) < 0xea)) {
    cranking_in_progress_ffffd15c = 1;
  }
  else {
    cranking_in_progress_ffffd15c = 0;
  }
  if ((cranking_in_progress_ffffd15c == 1) && ((uVar1 & 0xffff) != 0xea)) {
    uVar2 = rx8_add_u16_saturate(uVar1,1);
    uVar1 = ref_updateMemoryAtAddress_16bit_ADDR_VAL(&candidate_cranking_dwell_accumulator_ffff86e8,uVar2);
    return uVar1;
  }
  return (uint)cranking_in_progress_ffffd15c;
}


