/* ROM address: 0x0000a2ec; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a2ec (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000a2ec(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 auStack_c [4];
  undefined4 uStack_8;
  
  uStack_8 = param_1;
  ref_setSR_PARAM(auStack_c,0xe0);
  FUN_0000a438(uStack_8,0xffffffff);
  uVar1 = FUN_0000a4be();
  return uVar1;
}


