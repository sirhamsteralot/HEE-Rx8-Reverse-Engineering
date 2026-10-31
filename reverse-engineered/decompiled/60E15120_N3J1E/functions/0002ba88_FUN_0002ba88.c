/* ROM address: 0x0002ba88; body bytes: 94; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002c1dc (94 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002ba88(void)

{
  uint uVar1;
  
  uVar1 = ref_getFromGPIO_(1);
  if ((uVar1 & 0x20) == 0) {
    if (0xf < DAT_ffffbc08) {
      DAT_ffffbc04 = 0;
    }
    DAT_ffffbc08 = rx8_add_u16_saturate((int)(short)DAT_ffffbc08,1);
    DAT_ffffbc06 = 0;
  }
  else {
    if (0xf < DAT_ffffbc06) {
      DAT_ffffbc04 = 1;
    }
    DAT_ffffbc06 = rx8_add_u16_saturate((int)(short)DAT_ffffbc06,1);
    DAT_ffffbc08 = 0;
  }
  return;
}


