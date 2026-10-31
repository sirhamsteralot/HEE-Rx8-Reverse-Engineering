/* ROM address: 0x00011bfa; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00011c72 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_bulkInits__(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0001975c();
  FUN_000141aa();
  FUN_00038bdc();
  FUN_00020dc4();
  FUN_00028784();
  ref_setSR(uVar1);
  return;
}


