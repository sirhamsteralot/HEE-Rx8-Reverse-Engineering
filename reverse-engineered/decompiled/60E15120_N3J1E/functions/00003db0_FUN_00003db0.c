/* [ADDITIONAL SOURCE REVIEW]
 * os_wake_check_context_switch [high]: Called from ref_setSR (0x3934, call-site literal 0x3950). If DAT_ffff763c != DAT_ffff763e and (DAT_ffff7640 & 0x1000)==0: sets 0xffff7640=0x100, calls 0x3bf4 (context switch). Task-dispatch wake on ISR exit.
 * RAM 0xffff763c os_scheduled_count (uint16): u16 at ctrl+4; direct mov.l pool 0x3960 in 0x3954; compared with 0xffff763e in os_wake_check_context_switch 0x3db0; initialized to 0xffff by os_init 0x3e10.
 * RAM 0xffff763e os_dispatched_count (uint16): u16 at ctrl+6 (base 0xffff7638 pool-referenced in 0x3db0 via pool 0x3e00); compared with 0xffff763c in the 0x3db0 wake check.
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


