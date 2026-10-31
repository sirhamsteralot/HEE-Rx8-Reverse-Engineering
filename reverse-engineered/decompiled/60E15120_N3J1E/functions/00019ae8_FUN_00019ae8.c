/* ROM address: 0x00019ae8; body bytes: 174; decompiled */

void FUN_00019ae8(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0004b4cc();
  FUN_00032094();
  FUN_00024b64();
  FUN_00024b8c();
  ref_calculateEngineLoadMax();
  ref_calcSpeedBasedIATCompensation_0004910e();
  FUN_0001ae5c();
  FUN_0001ae74();
  FUN_0002ba88();
  ref_writeOilPressureLight__();
  ref_writeOilPressureGauge__();
  FUN_0003daf4();
  FUN_0004adfa();
  FUN_0004ae24();
  FUN_0004ae64();
  FUN_0004aea4();
  FUN_0004aec6();
  FUN_0004b808();
  FUN_0004b84a();
  FUN_0004b8a8();
  FUN_0004b982();
  FUN_0004b9a8();
  FUN_0004ba64();
  FUN_0004ba86();
  FUN_0004bab4();
  ref_calcDiagFuelInjectorTrim();
  ref_setSR(uVar1);
  return;
}


