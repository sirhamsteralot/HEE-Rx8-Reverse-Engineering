/* ROM address: 0x000117ac; body bytes: 212; decompiled */

void FUN_000117ac(void)

{
  FUN_00019ae8();
  ref_calcBatteryRelatedFaults__();
  FUN_00059768();
  FUN_00059938();
  FUN_00059a58();
  FUN_00059af4();
  FUN_00059d80();
  FUN_00059eae();
  FUN_00059fa0();
  FUN_000597d8();
  FUN_0005980c();
  FUN_00059d98();
  FUN_00059e90();
  FUN_00059fe0();
  FUN_00059408();
  FUN_000390fc();
  fueling_slow_task();
  FUN_0001465e();
  FUN_00023076();
  ref_acCompressorControlMain___();
  FUN_0002f266();
  ref_getOBDFuelModificationRequest();
  candidate_secondary_air_on_time_task();
  secondary_air_solenoid_control();
  ref_evapRelated();
  FUN_00016f98();
  FUN_00028930();
  ref_calculateDiagSessionConditional();
  FUN_0005e3ae();
  FUN_0005e402();
  ref_getBrakingOrInNeutral();
  FUN_0005e4b2();
  FUN_0005b9e4();
  ref_checkCANFaults__();
  FUN_00016bb4();
  return;
}


