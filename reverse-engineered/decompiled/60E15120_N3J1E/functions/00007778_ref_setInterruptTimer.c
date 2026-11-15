/* [ADDITIONAL SOURCE REVIEW]
 * atu_ch10b_tick_enable [high]: was ref_setInterruptTimer. Clears TSR10 (write 0xb), calls 0x7b58 (OCR10B from table 0xd76d[DAT_ffff9f95*2]&0x7f, TCNT10B=0), sets TIER10 bit2 (CMFB). OS tick setup; ch10 started by TSTR3 bit0 (0xfffff402).
 */
/* ROM address: 0x00007778; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007778 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

void atu_ch10b_tick_enable(void)

{
  ushort uVar1;
  
  if (DAT_ffff9fc4 == '\0') {
    ATUII_TSR10_W = 0xb;
    ch10b_compare_rearm();
    uVar1 = ATUII_TIER10_W;
    ATUII_TIER10_W = uVar1 & 0xfffb | 4;
    DAT_ffff9fc4 = '\x01';
  }
  return;
}


