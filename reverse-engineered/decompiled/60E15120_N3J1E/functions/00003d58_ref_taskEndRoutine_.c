/* ROM address: 0x00003d58; body bytes: 60; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00003d6a) */
/* Unique exact-byte match to related 60E0FC00 function at 00003d58 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_taskEndRoutine_(void)

{
  undefined1 *puVar1;
  
  puVar1 = os_current_task_record_ptr_ffff764c;
  os_current_task_record_ptr_ffff764c[3] = os_current_task_record_ptr_ffff764c[3] + '\x01';
  os_state_flags_ffff7640 = 0x100;
  ref_consistencyCheck(&os_ctrl_block_ffff7638,(int)(char)puVar1[1]);
  *puVar1 = 0;
  DAT_ffff7644 = *(undefined4 *)(puVar1 + 4);
  os_dispatch(&os_ctrl_block_ffff7638);
  return;
}


