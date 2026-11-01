/* ROM address: 0x0000969e; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000969e (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000969e(void)

{
  int iVar1;
  
  iVar1 = os_queue_dequeue_record(0,&DAT_ffffa118);
  if (iVar1 == 0) {
    (*DAT_ffffa118)(&DAT_ffffa11c);
  }
  ref_taskEndRoutine_();
  return;
}


