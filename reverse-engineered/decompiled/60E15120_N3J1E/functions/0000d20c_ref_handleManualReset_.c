/* [ADDITIONAL SOURCE REVIEW]
 * manual_reset_finalize [high]: Was ref_handleManualReset_: r1 = pool 0xd2c8=0xd730 (cell holding 0xffff768c), jsr 0x4c7a (pool 0xd2cc=0x4c7a) with r4 = *(0xd730), jsr 0x9e68 (pool 0xd2d0=0x9e68, recovery_finalize_set_pf3_halt), halt at 0xd21a. Entered from the recovery block at 0xd204 (ldc vbr 0x7fc50 pool 0xd2c0=0x7fc50, lds fpscr 0x40001 pool 0xd2c4=0x40001, then falls into 0xd20c); 0xd204 is the value of u32 @ROM 0x7fff8.
 */
/* ROM address: 0x0000d20c; body bytes: 18; decompiled_with_warnings */

/* Unique exact-byte match to related 60E0FC00 function at 0000d20c (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void manual_reset_finalize(void)

{
  FUN_00004c7a(&DAT_ffff768c);
  recovery_finalize_set_pf3_halt();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


