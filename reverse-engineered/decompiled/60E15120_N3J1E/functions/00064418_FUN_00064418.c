/* ROM address: 0x00064418; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062d08 (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00064418(undefined4 param_1,byte param_2)

{
  uint uVar1;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 local_8;
  
  uVar1 = FUN_00062df8();
  uVar1 = uVar1 & 0xff;
  if (((uVar1 == 0) || (uVar1 == 0x50)) && (uVar1 = (uint)param_2, uVar1 == 1)) {
    FUN_00062668();
    uStack_14 = FUN_0005fcf8();
    uStack_10 = FUN_0005fcf2();
    uStack_c = FUN_0005fcfe();
    local_8 = ref_returnCoolantTempGreaterThan71();
    FUN_00067732(&uStack_14);
    uVar1 = FUN_000628f4();
  }
  return uVar1;
}


