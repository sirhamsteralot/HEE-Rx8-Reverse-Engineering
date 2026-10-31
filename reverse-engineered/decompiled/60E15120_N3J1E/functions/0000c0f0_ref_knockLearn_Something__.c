/* ROM address: 0x0000c0f0; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000c0f0 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_knockLearn_Something__(undefined2 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  knock_ignition_threshold_b_ffffa37c = param_2;
  knock_ignition_threshold_a_ffffa37e = param_1;
  ref_setSR(uVar1);
  return;
}


