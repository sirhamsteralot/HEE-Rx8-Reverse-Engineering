/* ROM address: 0x000118d0; body bytes: 158; decompiled */

void dtc_fault_service_batch(void)

{
  FUN_00019d24();
  FUN_0003957c();
  FUN_00021bc6();
  FUN_00021434();
  candidate_knock_rough_correction_update();
  FUN_0002253c();
  FUN_00028966();
  ref_setOBDCANTXVars();
  ref_someOBDFunctionCaller();
  FUN_0005a020();
  FUN_0005a0a2();
  FUN_0005912c();
  ref_faultSomething0x1();
  FUN_0005a188();
  FUN_0005a274();
  FUN_0005a2f4();
  FUN_000559dc();
  FUN_00055a06();
  ref_getVehicleSpeedThreshold();
  FUN_0005965c();
  FUN_00059852();
  FUN_0005e3d8();
  ref_checkIfDeviceControl_();
  ref_getCoolantTempConditional();
  FUN_00016c24();
  FUN_0003809a();
  return;
}


