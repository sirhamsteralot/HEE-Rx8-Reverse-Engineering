/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_save_encode_entry [high]: Interrupt-masked wrapper (sh_raise_interrupt_mask 0x10 / ref_setSR): calls 0x242ae (fault status collect) then 0x244bc (block encode); called from 0x236cc, which then writes magic 0xa55a (mov.w via pool 0x23734) at 0xffffb440, checksum (sum of 0x1b u16, loop at 0x236f0-0x236fe) at +0x36, and writes 0x1c u16 via E2RAM write 0xb886 (pool 0x23738), setting 0xffffb43b on success.
 */
/* ROM address: 0x0002377a; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00023fee (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

void e2ram_save_encode_entry(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  e2ram_fault_status_collect();
  ref_setSR(uVar1);
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  e2ram_block_encode();
  ref_setSR(uVar1);
  return;
}


