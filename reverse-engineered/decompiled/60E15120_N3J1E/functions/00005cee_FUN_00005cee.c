/* ROM address: 0x00005cee; body bytes: 16; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00005cee (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00005cee(void)

{
  ushort uVar1;
  
  uVar1 = CMCSR1_W;
  CMCSR1_W = uVar1 & 0xff7f;
  FUN_0000a522();
  return;
}


