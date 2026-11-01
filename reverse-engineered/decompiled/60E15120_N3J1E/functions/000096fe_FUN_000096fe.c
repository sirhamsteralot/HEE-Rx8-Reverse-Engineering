/* ROM address: 0x000096fe; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000096fe (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000096fe(void)

{
  int iVar1;
  
  iVar1 = os_queue_dequeue_record(3,&DAT_ffffa154);
  if (iVar1 == 0) {
    (*DAT_ffffa154)(&DAT_ffffa158);
  }
  ref_taskEndRoutine_();
  return;
}


