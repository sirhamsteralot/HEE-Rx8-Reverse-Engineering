/* ROM address: 0x0000cbf8; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000cbf8 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_set_MCR_bits5_7(undefined4 param_1,char param_2)

{
  char *pcVar1;
  uint uVar2;
  
  pcVar1 = (char *)ref_getHCANRegisterAddress(param_1,&HCAN0_MCR_B);
  uVar2 = (int)*pcVar1 & 0xdfU | (int)param_2 << 5;
  *pcVar1 = (char)uVar2;
  return uVar2;
}


