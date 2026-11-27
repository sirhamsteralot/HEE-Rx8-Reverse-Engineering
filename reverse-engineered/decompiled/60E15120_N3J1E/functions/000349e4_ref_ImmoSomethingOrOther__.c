/* [ADDITIONAL SOURCE REVIEW]
 * immo_boot_init [high]: ref_ImmoSomethingOrOther__ (unique_exact_bytes to 60E0FC00 0x35104), called from boot task 0x1102a (callgraph 0x1102a -> 0x349e4). Calls ref_loadDatafromE2intoRAM_ 0x35956, e2ram_boot_param_read 0x3599c, ref_checkImmoStatus_ 0x35f64, immo_random_seed_gen 0x3587c, immo_key_defaults_init 0x34a74.
 */
/* ROM address: 0x000349e4; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035104 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void immo_boot_init(void)

{
  ref_loadDatafromE2intoRAM_();
  e2ram_boot_param_read();
  immo_status_housekeeping();
  immo_random_seed_gen();
  candidate_immo_key_defaults_init();
  return;
}


