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


