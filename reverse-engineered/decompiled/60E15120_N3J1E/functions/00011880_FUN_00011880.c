/* [ADDITIONAL SOURCE REVIEW]
 * monitor_service_batch [medium]: 13-call batch, pool 0x11a40-0x11a70 ROM-verified: 0x19cf4 (ref_filterVehicleSpeed/ref_calculateVehicleAccel/ref_filterVehicleAccel + knock_state_reset_rpm_window), 0x2e6ec, 0x394ee, 0x212fa, 0x26850, 0x3eb16, 0x2894e, 0x2a374, 0x5629e, ref_diagControlModeSomething 0x5bf9c, 0x65630, ref_coolantTempPlausibilityCheck___ 0x65658, 0x16be6. Called only from task[12] 0x6592.
 */
/* ROM address: 0x00011880; body bytes: 80; decompiled */

void monitor_service_batch(void)

{
  FUN_00019cf4();
  FUN_0002e6ec();
  FUN_000394ee();
  FUN_000212fa();
  FUN_00026850();
  FUN_0003eb16();
  FUN_0002894e();
  FUN_0002a374();
  FUN_0005629e();
  ref_diagControlModeSomething();
  FUN_00065630();
  ref_coolantTempPlausibilityCheck___();
  FUN_00016be6();
  return;
}


