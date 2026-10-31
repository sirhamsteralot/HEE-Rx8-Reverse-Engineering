/* ROM address: 0x00064122; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062a12 (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00064122(undefined4 param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00062df8();
  if ((param_2 & 0xff) != (uVar1 & 0xff)) {
    FUN_00062dd8(param_2);
    uVar1 = FUN_000621d8(uVar1,param_2);
    return uVar1;
  }
  return uVar1;
}


