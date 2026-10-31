/* ROM address: 0x00012cd6; body bytes: 214; decompiled */

uint FUN_00012cd6(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  uint extraout_r0;
  float fVar4;
  
  cVar2 = fuel_cut_flag_b_ffffa445;
  cVar1 = fuel_cut_flag_a_ffffa444;
  fVar4 = 0.0;
  if (((DAT_ffffc590 == '\0') && (0x9c3 < engine_running_timer_ffffa424)) && (DAT_ffffaa62 == '\0')) {
    DAT_ffffa674 = (float)rx8_divide_with_zero_fallback(engine_load_raw_ffffc0b0 - engine_load_ffffc0b4);
  }
  else {
    DAT_ffffa674 = 0.0;
  }
  if (((DAT_ffffa6a5 == '\x01') && (cVar1 == '\0')) || ((DAT_ffffa6a6 == '\x01' && (cVar2 == '\0')))
     ) {
    uVar3 = 1;
    DAT_ffffa687 = 0xff;
  }
  else {
    uVar3 = (uint)DAT_ffffa687;
    if (uVar3 != 0) {
      DAT_ffffa687 = DAT_ffffa687 - 1;
    }
  }
  if (DAT_ffffa687 == 0) {
    if ((DAT_ffffa66c <= 0.0) && (DAT_ffffa670 <= 0.0)) {
      DAT_ffffa678 = fVar4;
    }
  }
  else {
    DAT_ffffa678 = rx8_max_float(DAT_ffffa678,DAT_ffffa674);
    uVar3 = extraout_r0;
  }
  DAT_ffffa6a5 = cVar1;
  DAT_ffffa6a6 = cVar2;
  return uVar3;
}


