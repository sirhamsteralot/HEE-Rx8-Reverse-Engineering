/* [ADDITIONAL SOURCE REVIEW]
 * cruise_set_speed_apply [high]: Applies the integrator output to the cruise set speed: when cruise active (0xffffbced set, 0xffffbd3e set) 0xffffbcf8 = clamp(0xffffbd00 + 0xffffbd08, 0, 100); 0xffffbcf8 is the set speed compared against vehicle speed 0xffffa9b4 by 0x4c896 (enable flag 0xffffcf34).
 * RAM 0xffffbd08 cruise_set_speed_adjust (float): Integrator output of 0x2d83c, clamped [0,100]; folded into set speed by 0x2df62 as 0xffffbcf8 = clamp(0xffffbd00 + 0xffffbd08, 0, 100).
 */
/* ROM address: 0x0002df62; body bytes: 116; decompiled */

void cruise_set_speed_apply(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = 0.0;
  fVar2 = fVar3;
  if ((((DAT_ffffbced != '\0') && (fVar2 = cruise_set_speed_ffffbcf8, DAT_ffffbd3e == '\x01')) &&
      (fVar2 = fVar3, DAT_ffffbceb != '\x01')) &&
     (((DAT_ffffb53a != '\x01' &&
       (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8664,0), fVar2 = fVar3, cVar1 != '\0')) &&
      (DAT_ffffaa68 != '\0')))) {
    fVar2 = rx8_clamp_float(DAT_ffffbd00 + cruise_set_speed_adjust_ffffbd08,0.0,100.0);
  }
  cruise_set_speed_ffffbcf8 = fVar2;
  return;
}


