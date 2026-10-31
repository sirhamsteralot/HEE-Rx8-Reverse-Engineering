/* ROM address: 0x00005ede; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005ede (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005ede(void)

{
  ushort uVar1;
  
  uVar1 = HCAN1_IRR_W;
  HCAN1_IRR_W = uVar1 | 0x9910;
  FUN_00005348(0xe5);
  return;
}


