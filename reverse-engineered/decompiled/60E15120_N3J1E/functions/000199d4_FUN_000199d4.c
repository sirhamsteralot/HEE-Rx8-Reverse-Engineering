/* ROM address: 0x000199d4; body bytes: 204; decompiled */

void FUN_000199d4(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_000454d2();
  ref_calculateKeyOnTime();
  ref_calculateKeyOffTime();
  FUN_000312f8();
  FUN_00031318();
  ref_calculateEngineRunning();
  FUN_0000e060();
  FUN_0000e0f4();
  ref_calculateEngineRunningTimer2();
  ref_calculateEngineRunningTimer();
  FUN_0001a394();
  FUN_00018f60();
  ref_filterSomething();
  FUN_00018fa4();
  ref_filterSomething2();
  FUN_00018fe8();
  FUN_0001933a();
  throttle_percent_and_demand_calc();
  ref_getDriverOffThrottleTimer__();
  ref_getDriverOffThrottleInstatanious();
  FUN_0001b08e();
  FUN_0001b14c();
  FUN_0001b166();
  FUN_0001b3f2();
  FUN_0001b6fc();
  ref_calculateThrottlePedalPercentForSomethingElse_();
  FUN_0001ba20();
  FUN_0001bcae();
  ref_getACSwitchStatus();
  FUN_0003ebe4();
  FUN_00049490();
  ref_setSR(uVar1);
  return;
}


