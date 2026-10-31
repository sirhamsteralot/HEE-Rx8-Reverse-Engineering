/* ROM address: 0x000052b0; body bytes: 28; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000052b0 (28 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000052b0(void)

{
  byte bVar1;
  uint uVar2;
  
  SYSCR_B = 1;
  bVar1 = MSTCR__W__W._1_1_;
  if ((bVar1 & 2) != 0) {
    uVar2 = FUN_0000a370();
    return uVar2;
  }
  return (uint)bVar1;
}


