/* ROM address: 0x00004c80; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004c80 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004c80(void)

{
  FUN_00005292();
  ICR_W = 0xff;
  FUN_00004dee();
  FUN_00004e0e();
  FUN_00004e6c();
  FUN_00004fd6();
  ref_writeWatchdog_disable_00005024();
  FUN_00005036();
  FUN_0000503e();
  FUN_0000505a();
  FUN_00005062();
  FUN_000050aa();
  ref_callsFlash_0000527e();
  return;
}


