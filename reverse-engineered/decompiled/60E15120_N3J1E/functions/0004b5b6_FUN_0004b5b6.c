/* ROM address: 0x0004b5b6; body bytes: 178; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004a76e (178 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004b5b6(void)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_ffffc6b4 == '\0') {
    DAT_ffffce34 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(coolant_temperature_ffff9f70,&DAT_ffff8060);
  }
  else {
    DAT_ffffce34 = rx8_max_float(inferred_coolant_temperature_ffffa98c,5.0);
  }
  ref_E2IntoRAM_(0x7a,2);
  FUN_00037ef0(0x7a,&DAT_ffffce30,2);
  DAT_ffffce46 = DAT_ffffce30;
  DAT_ffffce38 = 0;
  uVar2 = ((int)DAT_ffffce30 & (uint)&PTR_ref_LongFunc_0000ff00) >> 8;
  uVar1 = 0x32;
  if (((uVar2 < 0x32) && (uVar1 = 0xcd, 0xcd < ((int)DAT_ffffce30 & 0xffU))) &&
     (uVar1 = 0xff, (uVar2 + (int)DAT_ffffce30 & 0xff) == 0xff)) {
    DAT_ffffce33 = 1;
    uVar1 = rx8_add_u16_saturate((int)DAT_ffffce30,0xff);
    if ((uVar1 & 0xffff) < (int)&PTR_ref_LongFunc_0000ff00 + 1U) {
      DAT_ffffce30 = (short)uVar1;
      return uVar1;
    }
  }
  else {
    DAT_ffffce33 = 0;
  }
  DAT_ffffce30 = 0xff00;
  return uVar1;
}


