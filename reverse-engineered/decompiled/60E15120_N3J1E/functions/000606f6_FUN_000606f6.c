/* ROM address: 0x000606f6; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005efe6 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_000606f6(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = FUN_00063998();
  bVar1 = (uVar2 & 0xff) != 0;
  if (bVar1) {
    FUN_00063c1c(uVar2,param_2);
  }
  return !bVar1;
}


