/* ROM address: 0x00005ef4; body bytes: 12; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005ef4 (12 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005ef4(void)

{
  ushort uVar1;
  
  uVar1 = HCAN1_IRR_W;
  HCAN1_IRR_W = uVar1 | 1;
  FUN_00009c9c();
  return;
}


