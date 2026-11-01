/* ROM address: 0x000096be; body bytes: 32; decompiled */

/* Function candidate recovered from ROM pointer at 49b8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void uds_service_task_entry(void)

{
  int iVar1;
  
  iVar1 = os_queue_dequeue_record(1,&DAT_ffffa12c);
  if (iVar1 == 0) {
    (*DAT_ffffa12c)(&DAT_ffffa130);
  }
  FUN_00003d58();
  return;
}


