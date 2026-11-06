/* [ADDITIONAL SOURCE REVIEW]
 * adc_read_ect_iat_group [medium]: was ref_readADCs_coolantTempInHere__. Reads ADDR24H-ADDR31H into 0xffff9f14-0xffff9f22 when DAT_ffff9f31 selects the group (ECT ADDR28H -> 0xffff9f1c, IAT ADDR29H -> 0xffff9f1e per fueling labels).
 */
/* ROM address: 0x00006cdc; body bytes: 114; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00006cdc (114 bytes). Names prefixed ref_
   are inherited hypotheses. */

char candidate_adc_read_ect_iat_group(void)

{
  char cVar1;
  
  if (DAT_ffff9f31 == '\0') {
    return '\0';
  }
  if (DAT_ffff9f31 == '\b') {
    DAT_ffff9f22 = ADDR31H_B;
    DAT_ffff9f20 = ADDR30H_B;
    DAT_ffff9f1e = ADDR29H_B;
    DAT_ffff9f1c = ADDR28H_B;
  }
  else if (DAT_ffff9f31 != '\x04') {
    cVar1 = '\x01';
    if (DAT_ffff9f31 != '\x01') {
      DAT_ffff9f2f = 0;
      DAT_ffff9f30 = 0;
      return DAT_ffff9f31;
    }
    goto LAB_00006d42;
  }
  DAT_ffff9f1a = ADDR27H_B;
  DAT_ffff9f18 = ADDR26H_B;
  cVar1 = '2';
  DAT_ffff9f16 = ADDR25H_B;
LAB_00006d42:
  DAT_ffff9f14 = ADDR24H_B;
  DAT_ffff9f30 = 0;
  DAT_ffff9f2f = 0;
  return cVar1;
}


