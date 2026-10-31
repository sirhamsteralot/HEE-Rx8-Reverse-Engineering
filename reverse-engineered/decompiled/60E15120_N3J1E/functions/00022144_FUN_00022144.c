/* [ADDITIONAL SOURCE REVIEW]
 * evap_open_loop_condition [medium]: b319 = 1 iff b318 && b12c==1 (open loop) && be00 >= 66.5 && ae1f==0 && !b2f6 && !b0c8 && !b0c9; reached from ref_evapRelated 0x21b8a.
 */
/* ROM address: 0x00022144; body bytes: 200; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00022ab0 (200 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint candidate_evap_open_loop_condition(void)

{
  char cVar1;
  uint uVar2;
  uint extraout_r0;
  
  cVar1 = closed_loop_active_ffffae1f;
  if ((((DAT_ffffb318 != '\x01') || (open_loop_active_ffffb12c != '\x01')) || (DAT_ffffbe00 < 66.5)) ||
     (((closed_loop_active_ffffae1f != '\0' || (DAT_ffffb2f6 != '\0')) ||
      ((DAT_ffffb0c8 != '\0' || (DAT_ffffb0c9 != '\0')))))) {
    DAT_ffffb319 = 0;
  }
  else {
    DAT_ffffb319 = 1;
  }
  uVar2 = (uint)DAT_ffffb319;
  if (uVar2 == 1) {
    DAT_ffffb308 = rx8_min_float(DAT_ffffb308 + 0.0,0.0);
    uVar2 = extraout_r0;
  }
  else {
    DAT_ffffb308 = 0.0;
  }
  if (cVar1 == '\0') {
    uVar2 = rx8_add_u16_saturate((int)DAT_ffffb32a,1);
    DAT_ffffb32a = (short)uVar2;
  }
  else {
    DAT_ffffb32a = 0;
  }
  return uVar2;
}


