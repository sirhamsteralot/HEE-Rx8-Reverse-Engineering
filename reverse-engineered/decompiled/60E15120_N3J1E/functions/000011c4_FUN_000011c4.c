/* [ADDITIONAL SOURCE REVIEW]
 * immo_diag_bit_clear [medium]: 8 B 'writeImmoBitZero?' (inherited name), called from 0x1378. mov.l pool 0x1284 = 0xffffdfa0; stores byte 0 to it (clears the immo diag bit at boot). Pool word re-read from ROM.
 * RAM 0xffffdfa0 immo_diag_bit (u8 bit0): pool 0x1284=0xffffdfa0 in 0x11c4
 */
/* ROM address: 0x000011c4; body bytes: 8; decompiled */

void FUN_000011c4(void)

{
  DAT_ffffdfa0._0_2_ = 0;
  return;
}


