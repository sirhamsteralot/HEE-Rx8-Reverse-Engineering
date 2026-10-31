/* ROM address: 0x000680de; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000669ce (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000680de(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffdde1;
  if (uVar1 == 6) {
    uVar1 = FUN_0006896c();
    return uVar1;
  }
  if (uVar1 == 10) {
    uVar1 = FUN_00068996();
    return uVar1;
  }
  if (uVar1 == 0) {
    uVar1 = (uint)DAT_ffffddeb;
    if (uVar1 == 0) {
      uVar1 = FUN_0006892a();
      return uVar1;
    }
    if (uVar1 == 3) {
      uVar1 = FUN_00068a44();
      return uVar1;
    }
  }
  return uVar1;
}


