/* ROM address: 0x00013504; body bytes: 228; decompiled */

uint idle_leading_timing_error_correction(void)

{
  uint uVar1;
  uint extraout_r0;
  undefined *puVar2;
  float fVar3;
  float fVar4;
  
  DAT_ffffa728 = DAT_ffffb5b8 - DAT_ffffb5c4;
  fVar4 = DAT_ffffc12c;
  fVar3 = DAT_ffffb5b8;
  if (DAT_ffffb5a4 == '\0') {
    if (DAT_ffffb5ac == '\0') {
      puVar2 = &DAT_0006a5d0;
    }
    else {
      puVar2 = &DAT_0006a5e4;
    }
    DAT_ffffa720 = (float)FUN_00002068(puVar2);
  }
  else {
    if (DAT_ffffb5aa == '\x01') {
      puVar2 = &DAT_0006a5d0;
    }
    else {
      puVar2 = &DAT_0006a5e4;
    }
    DAT_ffffa720 = (float)FUN_00002068(DAT_ffffa728,puVar2);
  }
  if (((DAT_ffffaada != '\x01') || (1500.0 <= fVar3)) ||
     ((fVar3 = DAT_ffffa720, 0.009765625 <= DAT_ffffc084 && (DAT_ffffa424 < 0x177)))) {
    fVar3 = 0.0;
  }
  if (fVar4 < 0.6) {
    if (fVar4 < 0.555) {
      DAT_ffffa730 = 0;
    }
  }
  else {
    DAT_ffffa730 = 1;
  }
  uVar1 = (uint)DAT_ffffa730;
  if (uVar1 == 1) {
    fVar3 = rx8_clamp_float(fVar3,-2.8,0.7);
    uVar1 = extraout_r0;
  }
  DAT_ffffa718 = fVar3;
  return uVar1;
}


