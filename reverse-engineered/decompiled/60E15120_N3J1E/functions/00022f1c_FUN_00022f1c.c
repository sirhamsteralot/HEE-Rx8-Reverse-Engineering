/* ROM address: 0x00022f1c; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00023784 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00022f1c(void)

{
  uint uVar1;
  uint extraout_r0;
  
  uVar1 = (uint)DAT_ffffccbb;
  if (uVar1 == 1) {
    DAT_ffffb404 = rx8_max_float(1.0,1.0);
    uVar1 = extraout_r0;
  }
  else {
    DAT_ffffb404 = 0.0;
  }
  return uVar1;
}


