/* ROM address: 0x00005e58; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005e58 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005e58(void)

{
  ushort uVar1;
  
  uVar1 = HCAN0_IRR_W;
  HCAN0_IRR_W = uVar1 | 0x6000;
  FUN_00005348(0xdc);
  return;
}


