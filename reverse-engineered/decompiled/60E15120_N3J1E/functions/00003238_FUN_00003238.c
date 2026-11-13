/* [ADDITIONAL SOURCE REVIEW]
 * interrupt_entry_save_context [high]: jsr target of every IVT trampoline at 0x28c0-0x30d0 (literals all = 0x3238). Dynamically executed on every cpu.interrupt in the emulator: saves r2-r7, fr0-fr11, fpscr, fpul (0x324a-0x326e), raises SR mask from ctrl block field +0x10, bumps counter at +0x8, rts to LAB_00003280 restore path.
 * RAM 0xffff7640 os_state_flags (uint16): u16 at ctrl+8; mov.l pool 0x3674 in 0x3588/0x35cc/0x35ee, pool 0x3758 in 0x36d4; incremented in interrupt_entry_save_context 0x3238; bit 0x1000 tested and 0x100 set in the 0x3db0 context-switch check.
 */
/* ROM address: 0x00003238; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003238 (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * interrupt_entry_save_context(void)

{
  os_state_flags_ffff7640 = os_state_flags_ffff7640 + 1;
  return &LAB_00003280;
}


