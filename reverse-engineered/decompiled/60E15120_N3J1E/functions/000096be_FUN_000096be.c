/* [ADDITIONAL SOURCE REVIEW]
 * uds_service_task_entry [high]: task[2] entry (task table 0x49b8): 0x6010(1,&blk) then (*blk.handler)(&blk+1)
 * RAM 0xffffa12c msg_dequeue_scratch_slot1 (uint32[5]): Dequeue output buffer of consumer task 0x96be (slot 1).
 */
/* ROM address: 0x000096be; body bytes: 32; decompiled */

/* Function candidate recovered from ROM pointer at 49b8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void uds_service_task_entry(void)

{
  int iVar1;
  
  iVar1 = os_queue_dequeue_record(1,&msg_dequeue_scratch_slot1_ffffa12c);
  if (iVar1 == 0) {
    (*msg_dequeue_scratch_slot1_ffffa12c)(&DAT_ffffa130);
  }
  ref_taskEndRoutine_();
  return;
}


