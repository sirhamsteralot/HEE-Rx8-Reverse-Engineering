/* [ADDITIONAL SOURCE REVIEW]
 * external_wdt_heartbeat_pulse [high]: External watchdog heartbeat on PB15: under SR mask 0xe0 (pool 0xa88a=0xe0, jsr 0x2054 pool 0xa894=0x2054) sets PBDR_W 0xfffff738 (pool 0xa88e=0xf738) |= 0x8000 (pool 0xa89c=0x8000), busy-waits 0x96*8 via 0x239c (pools 0xa890=0x96, 0xa8a0=0x239c), then PBDR &= 0x7fff (pool 0xa88c=0x7fff). Called from the 0x9ea2 shutdown wait loop, 0x60c8 and 0xd518.
 */
/* ROM address: 0x0000a850; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a850 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

void external_wdt_heartbeat_pulse(void)

{
  ushort uVar1;
  undefined4 local_c [2];
  
  ref_setSR_PARAM(local_c,0xe0);
  uVar1 = PBDR_W;
  PBDR_W = uVar1 | 0x8000;
  sh_busy_wait_count_times_8(0x96);
  uVar1 = PBDR_W;
  PBDR_W = uVar1 & 0x7fff;
  sh_busy_wait_count_times_8(0x96);
  FUN_00002064(local_c[0]);
  return;
}


