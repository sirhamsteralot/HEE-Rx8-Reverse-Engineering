/* ROM address: 0x0003dbd4; body bytes: 78; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003e15c (78 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_readValue_32bit_ADDRESS_VAL(short *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if (((short)~(param_1[1] + *param_1) == param_1[2]) ||
     ((short)~(param_1[1] + *param_1) == param_1[3])) {
    param_2 = *(undefined4 *)param_1;
  }
  else {
    FUN_0003de68();
  }
  ref_setSR(uVar1);
  return param_2;
}


