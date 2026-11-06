/* [ADDITIONAL SOURCE REVIEW]
 * crank_tick_message_handler [high]: Group-1 record[9] handler (ROM 0xd98c); posted by crank tick path (0xcf96 -> 0xa156); calls 0x287aa (fuel/load update chain) and 0x3a0bc. Executed dynamically via consumer task 0x96de.
 */
/* ROM address: 0x00011c98; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00011d10 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void crank_tick_message_handler(void)

{
  FUN_000287aa();
  FUN_0003a0bc();
  return;
}


