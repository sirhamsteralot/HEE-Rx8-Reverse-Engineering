/* [ADDITIONAL SOURCE REVIEW]
 * msg_queue_task_slot2 [high]: Task rec[3] entry: dequeue slot 2 (&0xffffa140) -> call handler -> taskEnd. Dynamically run: dequeued posted {0x11c98, arg}, executed handler 0x11c98 -> 0x287aa -> 0x3db0 -> 0x3a0bc -> 0x3d58 -> 0x3c2a -> idle.
 * RAM 0xffffa140 msg_dequeue_scratch_slot2 (uint32[5]): Dequeue output buffer of consumer task 0x96de (slot 2); dynamic: held {0x11c98, 0xdeadbeef, 0,0,0} after 0x9630(1,9) post.
 */
/* ROM address: 0x000096de; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000096de (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void msg_queue_task_slot2(void)

{
  int iVar1;
  
  iVar1 = os_queue_dequeue_record(2,&msg_dequeue_scratch_slot2_ffffa140);
  if (iVar1 == 0) {
    (*msg_dequeue_scratch_slot2_ffffa140)(&DAT_ffffa144);
  }
  ref_taskEndRoutine_();
  return;
}


