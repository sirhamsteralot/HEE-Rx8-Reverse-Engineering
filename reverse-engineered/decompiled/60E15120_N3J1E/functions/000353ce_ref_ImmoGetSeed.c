/* [ADDITIONAL SOURCE REVIEW]
 * immo_compute_seed [high]: ref_ImmoGetSeed (unique_exact_bytes to 60E0FC00 0x35aee). c200 = FUN_000354dc(c26c, c270, c208). This is the value a correct keyless response must echo back in cmd 8 (compared at 0x34f5c).
 * RAM 0xffffc200 immo_seed_expected (u32): c200 = 0x354dc(c26c,c270,c208); the cmd-8 word c204 must equal it
 * RAM 0xffffc26c immo_key_reg_a (u32): EEPROM immo key bytes 0x02-0x05 half; default 0x10001 when erased; e2ram param id 2 writes (2, 0xffffc26c, 8)
 * RAM 0xffffc270 immo_key_reg_b (u32): EEPROM immo key bytes 0x06-0x09 half; default 0x55aa55aa; same chain as c26c
 */
/* ROM address: 0x000353ce; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035aee (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_ImmoGetSeed(void)

{
  DAT_ffffc200 = FUN_000354dc(DAT_ffffc26c,DAT_ffffc270,DAT_ffffc208);
  return;
}


