/* [ADDITIONAL SOURCE REVIEW]
 * pedal_learned_zero_subtract [high]: a9ac = rx8_max_float(0.0, a99c - readValue_float(0xffff8068)) and a9b0 likewise with 0xffff8070 (pools 0x19386=0x8068, 0x19388=0x8070/0x8078, 0x1938c=0xa99c/0xa9a4, helpers 0x193bc=0x3dc22 ref_readValue_float, 0x19394=0x23e4 rx8_max_float, outputs 0x19390=0xa9ac/0xa9b0). Learned default 0x412db22d=10.856 written by 0x18fe8.
 * RAM 0xffffa9ac pedal_1_volts_zeroed (float): a9ac = max(0, a99c - learned zero 0xffff8068) in 0x1933a (pools 0x19386=0x8068, 0x1938c=0xa99c, 0x19394=0x23e4, store 0x19390=0xa9ac).
 */
/* ROM address: 0x0001933a; body bytes: 76; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00019f36 (76 bytes). Names prefixed ref_
   are inherited hypotheses. */

void pedal_learned_zero_subtract(void)

{
  float fVar1;
  float fVar2;
  float arg0;
  
  fVar1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x412db22d,&learned_pedal_zero_1_ffff8068);
  fVar1 = pedal_1_volts_clamped25_ffffa99c - fVar1;
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x412db22d,&learned_pedal_zero_2_ffff8070);
  arg0 = 0.0;
  fVar2 = DAT_ffffa9a4 - fVar2;
  pedal_1_volts_zeroed_ffffa9ac = rx8_max_float(0.0,fVar1);
  DAT_ffffa9b0 = rx8_max_float(arg0,fVar2);
  return;
}


