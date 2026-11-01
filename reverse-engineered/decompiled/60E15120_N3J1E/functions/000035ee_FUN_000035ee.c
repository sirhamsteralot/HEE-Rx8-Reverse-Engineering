/* ROM address: 0x000035ee; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000035ee (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000035ee(void)

{
  os_state_flags_ffff7640 = os_state_flags_ffff7640 | 0x8000;
  (*(code *)0x0)();
  os_state_flags_ffff7640 = os_state_flags_ffff7640 & (uint)&DAT_ffff7fff;
  return;
}


