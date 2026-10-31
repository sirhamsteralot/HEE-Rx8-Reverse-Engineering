/* ROM address: 0x000264f0; body bytes: 238; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00026e14 (238 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000264f0(void)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  float arg0;
  
  uVar2 = 0x42480000;
  fVar3 = 30.0;
  DAT_ffffb5e4 = DAT_ffffb5a4;
  arg0 = DAT_ffffb5e0;
  DAT_ffffb5e8 = rx8_first_order_filter(DAT_ffffb5e0,DAT_ffffb5e8,1.0,1e-05);
  fVar1 = (float)rx8_divide_with_zero_fallback((arg0 - 0.0) - DAT_ffffb5e8,uVar2);
  fVar1 = rx8_clamp_float(fVar1,0.0,1.0);
  DAT_ffffb5ec = arg0 * fVar1;
  if ((engine_running_ffffa428 != '\x01') || (0.0 <= engine_speed_rpm_ffffb548)) {
    if (DAT_ffffb615 == 1) {
      DAT_ffffb5a8 = rx8_max_float(arg0,DAT_ffffb5a8 - 124.51);
    }
    else {
      DAT_ffffb5a8 = DAT_ffffb5ec + arg0;
    }
    if (DAT_ffffb5a8 <= arg0) {
      DAT_ffffb615 = 0;
    }
  }
  else {
    DAT_ffffb5a8 = rx8_max_float(arg0,DAT_ffffb5a8);
    DAT_ffffb615 = 1;
  }
  if (DAT_ffffb5e4 < 40.0) {
    if (DAT_ffffb5e4 < fVar3) {
      DAT_ffffb5b3 = 0;
    }
  }
  else {
    DAT_ffffb5b3 = 1;
  }
  return;
}


