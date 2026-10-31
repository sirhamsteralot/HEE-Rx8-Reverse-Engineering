/* ROM address: 0x00003934; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003934 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_setSR(int param_1)

{
  if ((param_1 == 0) && (*(char *)(DAT_ffff7650 + 1) != '\x01')) {
    os_wake_check_context_switch();
    return;
  }
  return;
}


