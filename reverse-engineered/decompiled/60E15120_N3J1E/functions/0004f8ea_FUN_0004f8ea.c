/* ROM address: 0x0004f8ea; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004d506 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004f8ea(void)

{
  uint uVar1;
  byte bVar2;
  
  bVar2 = -((((int)DAT_ffffcfb5 & 0x80U) == 0) + -1);
  uVar1 = (uint)bVar2;
  if ((uVar1 == 1) && (DAT_ffffd011 == '\0')) {
    uVar1 = (uint)engine_on_time_counter_ffffa426;
    DAT_ffffd00c = engine_on_time_counter_ffffa426;
  }
  DAT_ffffd011 = bVar2;
  return uVar1;
}


