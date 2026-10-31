/* ROM address: 0x00066678; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064f68 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066678(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_2 & 0xff) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_000666aa(param_1,param_2 + 0xff & 0xe0);
    uVar1 = FUN_000669be(param_2,uVar1);
  }
  return uVar1;
}


