/* ROM address: 0x0003de70; body bytes: 268; decompiled */

uint FUN_0003de70(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  ref_readValue_16bit_ADDRESS_VAL(&DAT_ffff8704,0);
  if (DAT_ffffc63c == 1) {
    uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
    DAT_ffffc63c = 0;
    ref_updateMemoryAtAddress_16bit_ADDR_VAL(&DAT_ffff8704,0);
    FUN_00060318();
    thunk_FUN_0002529e();
    thunk_FUN_00028db0();
    FUN_00019dd2();
    FUN_0002e70a();
    FUN_00039d96();
    FUN_0002148e();
    thunk_FUN_00013814();
    thunk_FUN_00015f74();
    FUN_00016fce();
    FUN_0003eb5e();
    FUN_00023094();
    FUN_0002897e();
    thunk_FUN_00034a64();
    FUN_0005a2c8();
    FUN_0005a3d8();
    FUN_0005a662();
    FUN_0005e34e();
    FUN_0005825c();
    FUN_000582e0();
    FUN_00058404();
    FUN_000584a8();
    FUN_00058516();
    FUN_000585c2();
    FUN_000586fa();
    FUN_000587f2();
    FUN_00058930();
    FUN_00058a78();
    FUN_00058bb4();
    FUN_00058cd0();
    FUN_00058e9c();
    FUN_00058f30();
    FUN_00054c6c();
    FUN_0003e1f0();
    uVar2 = ref_setSR(uVar1);
    return uVar2;
  }
  return (uint)DAT_ffffc63c;
}


