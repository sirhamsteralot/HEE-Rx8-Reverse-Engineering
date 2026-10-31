/* ROM address: 0x0003db54; body bytes: 64; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003e0dc (64 bytes). Names prefixed ref_
   are inherited hypotheses. */

int ref_readValue_8bit_ADDRESS_VAL(byte *param_1,byte param_2)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if (*param_1 == (byte)~param_1[1]) {
    param_2 = *param_1;
  }
  else {
    FUN_0003de68();
  }
  ref_setSR(uVar1);
  return (int)(char)param_2;
}


