/* [ADDITIONAL SOURCE REVIEW]
 * post_crank_tick_message [high]: Thunk: 0x9630(1, 9, arg) (disasm 0xa156: mov #9,r5; pool 0xa1fc = 0x9630) -> group1 rec[9] @0xd98c {id=2, n=1, handler=0x11c98} posted to queue slot 2.
 */
/* ROM address: 0x0000a156; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a156 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 post_crank_tick_message(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  uVar1 = os_schedule_task_event(1,9,local_8);
  return uVar1;
}


