/* ROM address: 0x0000969e; body bytes: 32; decompiled */

/* Function candidate recovered from ROM pointer at 49a8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_0000969e(void)

{
  int iVar1;
  
  iVar1 = os_queue_dequeue_record(0,&DAT_ffffa118);
  if (iVar1 == 0) {
    (*DAT_ffffa118)(&DAT_ffffa11c);
  }
  FUN_00003d58();
  return;
}


