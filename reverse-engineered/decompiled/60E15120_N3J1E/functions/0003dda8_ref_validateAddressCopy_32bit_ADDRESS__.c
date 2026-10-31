/* ROM address: 0x0003dda8; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003e330 (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_validateAddressCopy_32bit_ADDRESS__(undefined4 *param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  short local_10;
  short sStack_e;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  sStack_e = (short)*param_1;
  local_10 = (short)((uint)*param_1 >> 0x10);
  uVar2 = ~(sStack_e + local_10);
  if ((uVar2 == *(ushort *)(param_1 + 1)) || (uVar2 == *(ushort *)((int)param_1 + 6))) {
    uVar3 = 0;
    *(ushort *)(param_1 + 1) = uVar2;
    *(ushort *)((int)param_1 + 6) = uVar2;
  }
  else {
    uVar3 = 1;
    FUN_0003df7c();
  }
  ref_setSR(uVar1);
  return uVar3;
}


