/* ROM address: 0x00066a46; body bytes: 18; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065336 (18 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getFaultEvalState(void)

{
  uint uVar1;
  
  uVar1 = ref_setFaultEvalState_();
  DAT_ffffd930 = uVar1 & 0xffff;
  return;
}


