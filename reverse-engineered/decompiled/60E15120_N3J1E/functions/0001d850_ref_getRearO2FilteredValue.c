/* ROM address: 0x0001d850; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001e2b0 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_getRearO2FilteredValue(void)

{
  undefined4 extraout_r0;
  undefined4 uVar1;
  
  DAT_ffffb080 = rx8_first_order_filter(DAT_ffffad20,DAT_ffffb080,0.25,1e-05);
  uVar1 = extraout_r0;
  if (DAT_ffffb080 < DAT_ffffb078) {
    if (DAT_ffffb080 < DAT_ffffb078 - 0.0) {
      uVar1 = 0;
      DAT_ffffb07c = 0;
    }
  }
  else {
    DAT_ffffb07c = 1;
  }
  return uVar1;
}


