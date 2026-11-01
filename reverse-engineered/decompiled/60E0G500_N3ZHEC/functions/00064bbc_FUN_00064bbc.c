/* ROM address: 0x00064bbc; body bytes: 102; decompiled */

uint FUN_00064bbc(undefined4 param_1,byte param_2)

{
  uint uVar1;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 local_8;
  
  uVar1 = FUN_0006359c();
  uVar1 = uVar1 & 0xff;
  if (((uVar1 == 0) || (uVar1 == 0x50)) && (uVar1 = (uint)param_2, uVar1 == 1)) {
    FUN_00062e0c();
    uStack_14 = FUN_0006049c();
    uStack_10 = FUN_00060496();
    uStack_c = FUN_000604a2();
    local_8 = FUN_00060488();
    FUN_00067ed6(&uStack_14);
    uVar1 = FUN_00063098();
  }
  return uVar1;
}


