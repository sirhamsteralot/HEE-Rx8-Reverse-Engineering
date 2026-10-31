/* ROM address: 0x0002bafc; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002c250 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_writeOilPressureLight__(void)

{
  uint uVar1;
  
  uVar1 = ref_getFromGPIO_(1);
  if ((uVar1 & 0x80) == 0) {
    if (0xf < DAT_ffffbc0e) {
      DAT_ffffbc0c = 1;
    }
    DAT_ffffbc0e = rx8_add_u16_saturate((int)(short)DAT_ffffbc0e,1);
    DAT_ffffbc10 = 0;
  }
  else {
    if (0xf < DAT_ffffbc10) {
      DAT_ffffbc0c = 0;
    }
    DAT_ffffbc10 = rx8_add_u16_saturate((int)(short)DAT_ffffbc10,1);
    DAT_ffffbc0e = 0;
  }
  return;
}


