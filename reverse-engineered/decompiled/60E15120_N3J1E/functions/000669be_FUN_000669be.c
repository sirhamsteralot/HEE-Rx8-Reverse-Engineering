/* ROM address: 0x000669be; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000652ae (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000669be(uint param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  param_1 = param_1 & 0x1f;
  uVar2 = 1;
  if (param_1 == 0) {
    param_1 = 0x20;
  }
  uVar1 = FUN_000044e0(param_1,param_2,param_3,1);
  if ((uVar1 & param_2) != 0) {
    uVar2 = 0;
  }
  return uVar2;
}


