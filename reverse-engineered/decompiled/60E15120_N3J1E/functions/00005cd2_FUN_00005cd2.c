/* ROM address: 0x00005cd2; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005cd2 (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005cd2(void)

{
  ushort uVar1;
  
  uVar1 = CMCSR0_W;
  CMCSR0_W = uVar1 & 0xff7f;
  FUN_00005348(0xbc);
  return;
}


