/* ROM address: 0x0003dcd0; body bytes: 70; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003dd06) */
/* Unique exact-byte match to related 60E0FC00 function at 0003e258 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_updateMemoryAtAddress_float_VAL_ADDR(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  short local_14;
  short sStack_12;
  
  sStack_12 = (short)param_1;
  local_14 = (short)((uint)param_1 >> 0x10);
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  *(short *)(param_2 + 1) = ~(sStack_12 + local_14);
  *param_2 = param_1;
  *(short *)((int)param_2 + 6) = ~(sStack_12 + local_14);
  ref_setSR(uVar1);
  return 0;
}


