/* ROM address: 0x0004a356; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00049312 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004a356(void)

{
  uint uVar1;
  
  DAT_ffffcdb2 = DAT_ffffcd8a;
  uVar1 = (uint)DAT_ffffcd9c;
  if (uVar1 == 1) {
    DAT_ffffcd78 = rx8_first_order_filter(DAT_ffffb074,DAT_ffffcd78,0.03,1e-05);
    DAT_ffffcd88 = rx8_add_u16_saturate((int)DAT_ffffcd88,1);
    uVar1 = rx8_add_u16_saturate((int)DAT_ffffcd8a,1);
    DAT_ffffcd8a = (short)uVar1;
  }
  else {
    DAT_ffffcd8a = 0;
  }
  return uVar1;
}


