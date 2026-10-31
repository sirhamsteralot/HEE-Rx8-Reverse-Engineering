/* ROM address: 0x0003dc90; body bytes: 64; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003e218 (64 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_updateMemoryAtAddress_32bit_ADDR_VAL(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  short local_10;
  short sStack_e;
  
  sStack_e = (short)param_2;
  local_10 = (short)((uint)param_2 >> 0x10);
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  *(short *)(param_1 + 1) = ~(sStack_e + local_10);
  *param_1 = param_2;
  *(short *)((int)param_1 + 6) = ~(sStack_e + local_10);
  ref_setSR(uVar1);
  return 0;
}


