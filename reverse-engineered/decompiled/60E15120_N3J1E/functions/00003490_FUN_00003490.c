/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00003490; body bytes: 218; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000034fa) */
/* WARNING: Removing unreachable block (ram,0x00003542) */
/* Unique exact-byte match to related 60E0FC00 function at 00003490 (218 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00003490(char param_1)

{
  char cVar1;
  int snapshot_os_current_task_record_ptr_ffff764c;
  int snapshot_os_task_table_ptr_ffff7650;
  int iVar4;
  uint in_sr;
  uint uVar5;
  
  snapshot_os_current_task_record_ptr_ffff764c = os_current_task_record_ptr_ffff764c;
  uVar5 = in_sr & 0xfffffffe | (uint)(param_1 == '\0');
  if (((byte)uVar5 & 1) == 1) {
    if ((os_scheduled_count_ffff763c == os_dispatched_count_ffff763e) || (*(char *)(os_task_table_ptr_ffff7650 + 1) != '\0')) {
      os_state_flags_ffff7640 = 0;
    }
    else {
      os_state_flags_ffff7640 = 0x100;
      os_context_switch(&os_ctrl_block_ffff7638,uVar5,os_task_table_ptr_ffff7650);
    }
  }
  else {
    iVar4 = *(char *)(os_current_task_record_ptr_ffff764c + 2) * 2;
    *(undefined *)(os_current_task_record_ptr_ffff764c + 2) = (&DAT_ffff762c)[iVar4];
    snapshot_os_task_table_ptr_ffff7650 = os_task_table_ptr_ffff7650;
    if ((&DAT_ffff762d)[iVar4] != *(char *)(snapshot_os_current_task_record_ptr_ffff764c + 1)) {
      cVar1 = *(char *)(snapshot_os_current_task_record_ptr_ffff764c + 1);
      *(undefined *)(snapshot_os_current_task_record_ptr_ffff764c + 1) = (&DAT_ffff762d)[iVar4];
      os_state_flags_ffff7640 = os_state_flags_ffff7640 + 0x100;
      ref_consistencyCheck(&os_ctrl_block_ffff7638,(int)cVar1);
      if (((*(char *)(snapshot_os_task_table_ptr_ffff7650 + 1) == '\0') && (os_scheduled_count_ffff763c != os_dispatched_count_ffff763e)) &&
         ((os_state_flags_ffff7640 & 0x1000) == 0)) {
        os_context_switch(&os_ctrl_block_ffff7638,uVar5,snapshot_os_task_table_ptr_ffff7650);
      }
      else {
        os_state_flags_ffff7640 = os_state_flags_ffff7640 - 0x100;
      }
    }
  }
  return 0;
}


