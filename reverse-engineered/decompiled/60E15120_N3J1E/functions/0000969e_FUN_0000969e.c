/* [ADDITIONAL SOURCE REVIEW]
 * msg_queue_task_slot0 [high]: Task rec[1] entry: os_queue_dequeue_record(0, &0xffffa118); if r0==0 call msg.handler(msg.args); then taskEnd 0x3d58.
 * RAM 0xffffa118 msg_dequeue_scratch_slot0 (uint32[5]): Dequeue output buffer of consumer task 0x969e (slot 0); slots 1-3 at 0xffffa12c/a140/a154.
 */
/* ROM address: 0x0000969e; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000969e (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void msg_queue_task_slot0(void)

{
  int iVar1;
  
  iVar1 = os_queue_dequeue_record(0,&msg_dequeue_scratch_slot0_ffffa118);
  if (iVar1 == 0) {
    (*msg_dequeue_scratch_slot0_ffffa118)(&DAT_ffffa11c);
  }
  ref_taskEndRoutine_();
  return;
}


