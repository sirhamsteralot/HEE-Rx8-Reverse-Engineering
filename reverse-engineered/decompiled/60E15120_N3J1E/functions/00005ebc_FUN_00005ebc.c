/* ROM address: 0x00005ebc; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005ebc (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005ebc(void)

{
  ushort uVar1;
  
  uVar1 = HCAN0_IRR_W;
  HCAN0_IRR_W = uVar1 | 1;
  FUN_00009c9c();
  return;
}


