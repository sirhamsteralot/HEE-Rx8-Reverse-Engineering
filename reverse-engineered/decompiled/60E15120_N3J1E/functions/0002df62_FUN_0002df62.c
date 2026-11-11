/* [ADDITIONAL SOURCE REVIEW]
 * cruise_set_speed_apply [high]: Applies the integrator output to the cruise set speed: when cruise active (0xffffbced set, 0xffffbd3e set) 0xffffbcf8 = clamp(0xffffbd00 + 0xffffbd08, 0, 100); 0xffffbcf8 is the set speed compared against vehicle speed 0xffffa9b4 by 0x4c896 (enable flag 0xffffcf34).
 * RAM 0xffffbd08 cruise_output_integrator (float): Integrator output of 0x2d83c in the percent domain, clamped [0,100]; folded into the cruise output by 0x2df62 as 0xffffbcf8 = clamp(0xffffbd00 + 0xffffbd08, 0, 100). (Was cruise_set_speed_adjust; corrected: 0xffffbcf8 is a percent output, the set speed in km/h is 0xffff866c.)
 * RAM 0xffffbd00 cruise_control_law_output (float): Control-law output of 0x2d638 = clamp(bd04*bd18*0.01, -100, 100) from gear-band 2-D tables 0x6a844-0x6a874 on speed error 0xffffbfa0-0xffffbfa4; percent domain, folded into 0xffffbcf8 by 0x2df62. Emulator: vss=100, target=90, band 3 -> -23.93.
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


