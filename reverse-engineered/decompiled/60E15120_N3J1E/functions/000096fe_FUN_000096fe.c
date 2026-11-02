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


