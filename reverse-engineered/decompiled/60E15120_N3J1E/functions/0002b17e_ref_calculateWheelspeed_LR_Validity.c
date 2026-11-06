/* [ADDITIONAL SOURCE REVIEW]
 * wheelspeed_lr_validity [high]: 0xffffbbb9 = 1 when 0xffffbbac == -1 (invalid) or 0xffffbbbe > 0x1e (stale). Pool 0x2a494.
 * RAM 0xffffbbb9 wheelspeed_lr_invalid (uint8): LR wheelspeed invalid/stale flag from 0x2b17e (0xffffbbac == -1 || 0xffffbbbe > 0x1e).
 */
/* ROM address: 0x0002b17e; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002b8d2 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void wheelspeed_lr_validity(void)

{
  if ((wheelspeed_lr_raw_ffffbbac == -1) || (0x1e < DAT_ffffbbbe)) {
    wheelspeed_lr_invalid_ffffbbb9 = 1;
  }
  else {
    wheelspeed_lr_invalid_ffffbbb9 = 0;
  }
  return;
}


