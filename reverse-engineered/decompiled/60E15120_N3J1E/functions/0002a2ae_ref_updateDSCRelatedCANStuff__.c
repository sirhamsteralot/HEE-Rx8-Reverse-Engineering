/* ROM address: 0x0002a2ae; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002aa02 (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_updateDSCRelatedCANStuff__(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_can212RXSignalValidity__();
  ref_calculateEngineMaxTorqueAllowed___();
  FUN_0002b496();
  FUN_0002b6a4();
  ref_DSC_checkIfMode_x80();
  ref_DSC_checkIfMode_x40();
  ref_DSC_checkIfMode_x20();
  ref_DSC_checkIfMode_x10();
  FUN_0002b7c4();
  FUN_0002b046();
  ref_calculateIfVehicleMoving();
  ref_calculateWheelspeed_LR_Validity();
  ref_calculateWheelspeed_RR_Validity();
  ref_setSR(uVar1);
  return;
}


