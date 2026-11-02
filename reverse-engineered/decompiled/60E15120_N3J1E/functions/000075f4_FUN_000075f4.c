/* ROM address: 0x000075f4; body bytes: 48; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00007618) */
/* Unique exact-byte match to related 60E0FC00 function at 000075f4 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

void cmi10b_tick_service(void)

{
  if (DAT_ffff9fa5 == '\0') {
    FUN_00007f22();
    FUN_00007b90();
    crank_capture_poll();
    FUN_00007be4();
  }
  ch10b_compare_rearm();
  return;
}


