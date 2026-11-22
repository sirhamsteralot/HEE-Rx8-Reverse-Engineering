/* [ADDITIONAL SOURCE REVIEW]
 * immo_diag_bit_clear [medium]: 8 B 'writeImmoBitZero?' (inherited name), called from 0x1378. mov.l pool 0x1284 = 0xffffdfa0; stores byte 0 to it (clears the immo diag bit at boot). Pool word re-read from ROM.
 * RAM 0xffffdfa0 immo_diag_bit (u16): pool 0x1284 = 0xffffdfa0 stored as a word in 0x11c4 (0x11ca mov.w); 0x11cc increments it as u16 when the WDT overflow bit is set; 0x16b20 tests the whole byte; 0x169d4 writes 1 while ROM[0x6e224] == 0xff (0x00 in this ROM). Dual-labeled with the SBL counter (ROADMAP D14).
 */
/* ROM address: 0x000011c4; body bytes: 8; decompiled */

void FUN_000011c4(void)

{
  DAT_ffffdfa0._0_2_ = 0;
  return;
}


