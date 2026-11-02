/* ROM address: 0x00003854; body bytes: 166; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000038e0) */
/* WARNING: Removing unreachable block (ram,0x000038b8) */
/* Unique exact-byte match to related 60E0FC00 function at 00003854 (166 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 os_wake_posted_task(short param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint in_sr;
  
  uVar3 = 0;
  cVar1 = (&PTR_DAT_00004994)[param_1 * 4][3];
  if (cVar1 == '\0') {
    uVar3 = 4;
  }
  else {
    (&PTR_DAT_00004994)[param_1 * 4][3] = cVar1 + -1;
    iVar2 = os_mark_task_ready(&os_ctrl_block_ffff7638,(int)param_1,(int)(char)(&DAT_00004992)[param_1 * 0x10]);
    if (((iVar2 != 0) && ((in_sr & 0xf0) == 0 && os_state_flags_ffff7640 == 0)) &&
       (*(char *)(os_task_table_ptr_ffff7650 + 1) == '\0')) {
      os_state_flags_ffff7640 = 0x100;
      os_context_switch(&os_ctrl_block_ffff7638);
    }
  }
  return uVar3;
}


