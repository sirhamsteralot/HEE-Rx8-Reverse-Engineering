/* ROM address: 0x000672ec; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065bdc (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000672ec(undefined4 param_1,short param_2)

{
  undefined4 uVar1;
  
  uVar1 = ref_setupForUdsResponse_(6,param_1,(int)param_2);
  DAT_ffffd950 = DAT_ffffd950 + param_2;
  return uVar1;
}


