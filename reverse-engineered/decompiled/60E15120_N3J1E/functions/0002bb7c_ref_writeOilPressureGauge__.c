/* ROM address: 0x0002bb7c; body bytes: 136; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002c2d0 (136 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_writeOilPressureGauge__(void)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = ref_getFromGPIO_(2);
  bVar1 = (uVar2 & 1) != 0;
  if (engine_running_ffffa428 == '\0') {
    DAT_ffffbc14 = 1;
  }
  else if (bVar1) {
    if (1 < DAT_ffffbc16) {
      DAT_ffffbc14 = 0;
    }
  }
  else if (0x270 < DAT_ffffbc18) {
    DAT_ffffbc14 = 1;
  }
  if (bVar1) {
    DAT_ffffbc16 = rx8_add_u16_saturate((int)(short)DAT_ffffbc16,1);
    DAT_ffffbc18 = 0;
  }
  else {
    DAT_ffffbc18 = rx8_add_u16_saturate((int)(short)DAT_ffffbc18,1);
    DAT_ffffbc16 = 0;
  }
  return;
}


