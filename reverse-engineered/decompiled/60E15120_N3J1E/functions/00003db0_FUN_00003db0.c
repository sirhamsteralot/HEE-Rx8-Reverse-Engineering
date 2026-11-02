/* [ADDITIONAL SOURCE REVIEW]
 * os_wake_check_context_switch [high]: Called from ref_setSR (0x3934, call-site literal 0x3950). If DAT_ffff763c != DAT_ffff763e and (DAT_ffff7640 & 0x1000)==0: sets 0xffff7640=0x100, calls 0x3bf4 (context switch). Task-dispatch wake on ISR exit.
 */
/* ROM address: 0x00003db0; body bytes: 76; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00003ddc) */
/* Unique exact-byte match to related 60E0FC00 function at 00003db0 (76 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 os_wake_check_context_switch(void)

{
  if ((os_scheduled_count_ffff763c != os_dispatched_count_ffff763e) && ((os_state_flags_ffff7640 & 0x1000) == 0)) {
    os_state_flags_ffff7640 = 0x100;
    os_context_switch(&os_ctrl_block_ffff7638);
  }
  return 0;
}


