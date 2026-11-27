/* [ADDITIONAL SOURCE REVIEW]
 * immo_eeprom_write_dispatch [high]: ref_afterImmoMain (unique_exact_bytes to 60E0FC00 0x37028), tail-called by the dispatcher. Calls ref_afterImmo_1..8 (0x36acc/0x36c3c/0x36ed4/0x3703c/0x37134/0x36dae/0x3728c/0x374be) + 0x37568.
 */
/* ROM address: 0x00036908; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00037028 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void immo_eeprom_write_dispatch(void)

{
  candidate_immo_eeprom_write_step_1();
  ref_afterImmo_2();
  ref_afterImmo_3();
  ref_afterImmo_4();
  ref_afterImmo_5();
  ref_afterImmo_6();
  ref_afterImmo_7();
  ref_afterImmo_8();
  FUN_00037568();
  return;
}


