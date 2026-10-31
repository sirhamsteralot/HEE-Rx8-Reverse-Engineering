/* ROM address: 0x000003b0; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000003b0 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined * FUN_000003b0(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffdfb6;
  DAT_ffffdfb6 = DAT_ffffdfb6 + 1;
  if (99 < DAT_ffffdfb6) {
    DAT_ffffdfb6 = 0;
  }
  return &DAT_ffffd4e0 + uVar1 * 8;
}


