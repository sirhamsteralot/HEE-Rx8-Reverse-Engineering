/* ROM address: 0x0000a30c; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a30c (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000a30c(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = param_1;
  uStack_8 = param_2;
  ref_setSR_PARAM(&local_10,0xe0);
  FUN_0000a438(uStack_c,uStack_8);
  uVar1 = FUN_00002064(local_10);
  return uVar1;
}


