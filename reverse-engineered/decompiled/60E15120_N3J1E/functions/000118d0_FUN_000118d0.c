/* [ADDITIONAL SOURCE REVIEW]
 * dtc_fault_service_batch [high]: 26-call batch, pool 0x11a74-0x11ad8 ROM-verified: 0x19d24, 0x3957c, 0x21bc6, 0x21434, candidate_knock_rough_correction_update 0x1467c, 0x2253c, 0x28966, ref_setOBDCANTXVars 0x2a39e, ref_someOBDFunctionCaller 0x5a698, 0x5a020, 0x5a0a2, 0x5912c, ref_faultSomething0x1 0x5a130, 0x5a188 (dtc_distance_mil_accumulator per dtc_control_report.md), 0x5a274, 0x5a2f4, 0x559dc, 0x55a06, ref_getVehicleSpeedThreshold 0x59fb6, 0x5965c, 0x59852, 0x5e3d8, ref_checkIfDeviceControl_ 0x5fc18, ref_getCoolantTempConditional 0x5fcbc, 0x16c24, 0x3809a. Called only from task[13].
 */
/* ROM address: 0x000118d0; body bytes: 158; decompiled */

void dtc_fault_service_batch(void)

{
  FUN_00019d24();
  FUN_0003957c();
  FUN_00021bc6();
  FUN_00021434();
  knock_rough_correction_update();
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


