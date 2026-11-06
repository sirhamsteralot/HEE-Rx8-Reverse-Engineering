/* [ADDITIONAL SOURCE REVIEW]
 * task16_uds_diag_utility_entry [high]: ROADMAP C item 7. rec[16] @ROM 0x4a90 entry; pool 0x66e4 = 0x11b22. Dynamic: harness call 0x65e8 visits 0x11b22 and ref_getTireSize 0x5de74.
 */
/* ROM address: 0x000065e8; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000065e8 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void task16_uds_diag_utility_entry(void)

{
  uds_diag_utility_batch();
  ref_taskEndRoutine_();
  return;
}


