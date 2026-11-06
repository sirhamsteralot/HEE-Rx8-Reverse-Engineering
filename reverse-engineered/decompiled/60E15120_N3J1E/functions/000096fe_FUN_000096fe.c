/* [ADDITIONAL SOURCE REVIEW]
 * msg_queue_task_slot3 [high]: Task rec[4] entry: dequeue slot 3 (&0xffffa154) -> call handler -> taskEnd.
 * RAM 0xffffa154 msg_dequeue_scratch_slot3 (uint32[5]): Dequeue output buffer of consumer task 0x96fe (slot 3).
 */
/* ROM address: 0x000096fe; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000096fe (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void msg_queue_task_slot3(void)

{
  int iVar1;
  
  iVar1 = os_queue_dequeue_record(3,&msg_dequeue_scratch_slot3_ffffa154);
  if (iVar1 == 0) {
    (*msg_dequeue_scratch_slot3_ffffa154)(&DAT_ffffa158);
  }
  ref_taskEndRoutine_();
  return;
}


