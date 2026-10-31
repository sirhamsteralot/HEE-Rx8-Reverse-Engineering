/* ROM address: 0x00021b8a; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000224f6 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_evapRelated(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0004b374();
  FUN_00021cde();
  FUN_00021d8a();
  FUN_00021efc();
  candidate_evap_open_loop_condition();
  FUN_00021c14();
  FUN_00025120();
  ref_setSR(uVar1);
  return;
}


