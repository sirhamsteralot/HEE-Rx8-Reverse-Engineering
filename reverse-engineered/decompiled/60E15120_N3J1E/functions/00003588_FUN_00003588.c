/* ROM address: 0x00003588; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003588 (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00003588(void)

{
  os_state_flags_ffff7640 = os_state_flags_ffff7640 | (uint)&DAT_00010000;
  (*(code *)0x0)();
  os_state_flags_ffff7640 = os_state_flags_ffff7640 & 0xfffeffff;
  return;
}


