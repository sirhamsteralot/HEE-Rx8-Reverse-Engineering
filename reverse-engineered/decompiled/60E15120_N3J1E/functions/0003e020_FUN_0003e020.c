/* ROM address: 0x0003e020; body bytes: 306; decompiled */

undefined4 FUN_0003e020(void)

{
  bool bVar1;
  short sVar2;
  char cVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  DAT_ffffc63d = '\0';
  ref_validateAddressCopy_16bit_ADDRESS__(&DAT_ffff8704);
  sVar2 = ref_readValue_16bit_ADDRESS_VAL(&DAT_ffff8704,0);
  if (sVar2 == -0x55ab) {
    FUN_000602e0();
    thunk_FUN_000252a6();
    thunk_FUN_00028db8();
    FUN_00019e10();
    FUN_0002e718();
    FUN_00039f64();
    FUN_0002149c();
    thunk_FUN_0001381e();
    thunk_FUN_00015f8e();
    FUN_00016fdc();
    thunk_FUN_0003e300();
    FUN_000230ae();
    thunk_FUN_000270aa();
    thunk_FUN_00034a6c();
    FUN_0005a2b6();
    FUN_0005a3c6();
    FUN_0005a63a();
    FUN_0005e2f8();
    FUN_00058256();
    FUN_000582da();
    FUN_000583fe();
    FUN_000584a2();
    FUN_00058510();
    FUN_000585bc();
    FUN_000586f4();
    FUN_000587ec();
    FUN_0005892a();
    FUN_00058a72();
    FUN_00058bae();
    FUN_00058cca();
    FUN_00058e96();
    FUN_00058f2a();
    cVar3 = FUN_0000ab6c();
    if (cVar3 == '\x01') {
      FUN_0003df7c();
    }
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((DAT_ffffc63d == '\x01') || (bVar1)) {
    DAT_ffffc63d = '\0';
    uVar4 = 1;
    DAT_ffffc63c = 0;
    ref_updateMemoryAtAddress_16bit_ADDR_VAL(&DAT_ffff8704,0);
  }
  return uVar4;
}


