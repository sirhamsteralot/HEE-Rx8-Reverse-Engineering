/* [ADDITIONAL SOURCE REVIEW]
 * crank_capture_poll [high]: Reads ATUII_ICR0AH_W (0xfffff434) into 0xffff9fb8 and ATUII_ICR10AH_W (0xfffff6d0) into 0xffff9fb0, computes period into 0xffff9fa8. Emulator: ICR values tracked the virtual crank wheel (set_rpm) when called via harness.
 */
/* ROM address: 0x000077f0; body bytes: 138; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000077f0 (138 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint crank_capture_poll(void)

{
  uint uVar1;
  
  crank_icr0ah_sample_ffff9fb8 = ATUII_ICR0AH_W;
  DAT_ffff9fb4 = crank_icr10ah_sample_ffff9fb0;
  crank_icr10ah_sample_ffff9fb0 = ATUII_ICR10AH_W;
  crank_sector_advance();
  if (crank_sector_index_ffff9f95 == 0) {
    FUN_00007a86(0);
  }
  else if (crank_sector_index_ffff9f95 == 0x12) {
    FUN_00007a86(6);
  }
  uVar1 = (uint)DAT_ffff9fc0;
  if ((uVar1 == 1) && (uVar1 = 0, ((int)(char)(&tbl_crank_sector_ocr10b_0000d76d)[(uint)crank_sector_index_ffff9f95 * 2] & 0x80U) != 0)
     ) {
    crank_period_last_ffff9fa8 = crank_icr0ah_sample_ffff9fb8 - DAT_ffff9fac;
    DAT_ffff9fac = crank_icr0ah_sample_ffff9fb8;
    uVar1 = (uint)DAT_ffff9fa3;
    if (uVar1 != 2) {
      uVar1 = ref_geteShaftAngle_();
      return uVar1;
    }
  }
  return uVar1;
}


