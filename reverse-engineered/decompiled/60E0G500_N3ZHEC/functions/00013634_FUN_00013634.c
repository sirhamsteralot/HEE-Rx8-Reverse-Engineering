/* ROM address: 0x00013634; body bytes: 228; decompiled */

uint idle_trailing_timing_error_correction(void)

{
  uint uVar1;
  uint extraout_r0;
  undefined *puVar2;
  float fVar3;
  float fVar4;
  
  DAT_ffffa72c = DAT_ffffb5b8 - DAT_ffffb5c4;
  fVar4 = DAT_ffffc12c;
  fVar3 = DAT_ffffb5b8;
  if (DAT_ffffb5a4 == '\0') {
    if (DAT_ffffb5ac == '\0') {
      puVar2 = &DAT_0006a5f8;
    }
    else {
      puVar2 = &DAT_0006a60c;
    }
    DAT_ffffa724 = (float)FUN_00002068(puVar2);
  }
  else {
    if (DAT_ffffb5aa == '\x01') {
      puVar2 = &DAT_0006a5f8;
    }
    else {
      puVar2 = &DAT_0006a60c;
    }
    DAT_ffffa724 = (float)FUN_00002068(DAT_ffffa72c,puVar2);
  }
  if (((DAT_ffffaada != '\x01') || (1500.0 <= fVar3)) ||
     ((fVar3 = DAT_ffffa724, 0.009765625 <= DAT_ffffc084 && (DAT_ffffa424 < 0x177)))) {
    fVar3 = 0.0;
  }
  if (fVar4 < 0.6) {
    if (fVar4 < 0.555) {
      DAT_ffffa731 = 0;
    }
  }
  else {
    DAT_ffffa731 = 1;
  }
  uVar1 = (uint)DAT_ffffa731;
  if (uVar1 == 1) {
    fVar3 = rx8_clamp_float(fVar3,-2.8,0.7);
    uVar1 = extraout_r0;
  }
  DAT_ffffa71c = fVar3;
  return uVar1;
}


