/* [ADDITIONAL SOURCE REVIEW]
 * can_error_supervision_step [high]: sh_raise_interrupt_mask_return_previous(0x10), then ref_checkCANsomethingKeyOnBased 0xdcc0 (jsr @r3 at 0x2a252, pool 0x2a44c = 0xdcc0), then FUN_000547d8, then ref_setSR; called from FUN_000114b0 0x114b0 (jsr at 0x114b8, pool 0x11680 = 0x2a248), called from OS task 7 entry ref_interruptSetup___ 0x63f0 (task-table record 7 at 0x4a08 = 0x63f0; jsr at 0x6414, pool 0x6528 = 0x114b0).
 */
/* ROM address: 0x0002a248; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002a99c (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

void can_error_supervision_step(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_checkCANsomethingKeyOnBased();
  FUN_000547d8();
  ref_setSR(uVar1);
  return;
}


