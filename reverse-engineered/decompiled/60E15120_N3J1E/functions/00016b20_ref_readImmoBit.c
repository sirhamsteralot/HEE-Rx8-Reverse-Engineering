/* [ADDITIONAL SOURCE REVIEW]
 * immo_diag_bit_check [medium]: ref_readImmoBit (unique_exact_bytes to 60E0FC00 0x16924), called from task 0x114d0. If 0xffffdfa0 bit0==0 && 0xffffdf98==0xa5 && (0xffffdf93 & 0x70)==0 -> FUN_00016a1c(2).
 */
/* ROM address: 0x00016b20; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00016924 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_immo_diag_bit_check(void)

{
  if (((immo_diag_bit_ffffdfa0._0_1_ == '\0') && (DAT_ffffdf98 == -0x5b)) && ((DAT_ffffdf93 & 0x70) == 0)) {
    FUN_00016a1c(2);
    return;
  }
  return;
}


