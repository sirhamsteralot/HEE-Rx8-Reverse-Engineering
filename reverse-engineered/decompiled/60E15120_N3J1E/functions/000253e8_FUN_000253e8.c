/* [ADDITIONAL SOURCE REVIEW]
 * key_off_state_machine_step [high]: Interrupt-masked step wrapper: ref_setSR_PARAM 0xe0 (pool 0x2540e=0xe0, jsr pool 0x25428=0x2054), jsr 0x252c2 (pool 0x2542c=0x252c2), restore via 0x2064 (pool 0x25430); called from slow task 0x11534.
 */
/* ROM address: 0x000253e8; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025c70 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 key_off_state_machine_step(void)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  key_off_shutdown_state_machine();
  uVar1 = FUN_00002064(local_8[0]);
  return uVar1;
}


