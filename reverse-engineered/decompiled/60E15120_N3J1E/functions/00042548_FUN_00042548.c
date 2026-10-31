/* ROM address: 0x00042548; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00041d7c (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00042548(void)

{
  uint uVar1;
  uint extraout_r0;
  
  uVar1 = (uint)DAT_ffffb358;
  if (uVar1 == 1) {
    DAT_ffffc974 = rx8_min_float(1e+06,DAT_ffffb354 + DAT_ffffc974);
    uVar1 = extraout_r0;
  }
  else {
    DAT_ffffc974 = 0.0;
  }
  return uVar1;
}


