/* ROM address: 0x000035cc; body bytes: 34; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000035cc (34 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000035cc(void)

{
  os_state_flags_ffff7640 = os_state_flags_ffff7640 | 0x4000;
  FUN_00009e58();
  os_state_flags_ffff7640 = os_state_flags_ffff7640 & 0xffffbfff;
  return;
}


