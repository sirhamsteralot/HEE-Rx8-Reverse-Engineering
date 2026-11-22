/* [ADDITIONAL SOURCE REVIEW]
 * fuel_pump_grace_eval_locked [high]: SR-masked wrapper: 0x3920 with mask 0x10 (pool 0x2f9b0), then 0x2fcac (pool 0x2f9cc), then tail-jump to the SR restore 0x3934 (pool 0x2f9c8). Entered from 0x11b80 (pool 0x11d20, jmp at 0x11ba0).
 */
/* ROM address: 0x0002f98c; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002fe44 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002f98c(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0002fcac();
  ref_setSR(uVar1);
  return;
}


