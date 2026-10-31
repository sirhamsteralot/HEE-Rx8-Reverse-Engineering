/* ROM address: 0x00007b58; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007b58 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00007b58(void)

{
  ATUII_OCR10B_B = (&DAT_0000d76d)[(uint)DAT_ffff9f95 * 2] & 0x7f;
  ATUII_TCNT10B_B = 0;
  DAT_ffff9fc3 = (&DAT_0000d76d)[(uint)DAT_ffff9f95 * 2] & 0x7f;
  return;
}


