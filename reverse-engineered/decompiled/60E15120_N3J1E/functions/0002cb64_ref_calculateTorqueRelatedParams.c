/* ROM address: 0x0002cb64; body bytes: 108; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002d208 (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateTorqueRelatedParams(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_getRPMBasedTorqueAdder();
  ref_getDesiredTorqueCalcVar2();
  ref_getDesiredTorqueCalcVar3();
  FUN_0002ce18();
  FUN_0002ce64();
  FUN_0002cd9c();
  ref_getRPMLoadBasedMult();
  ref_getLeadingTimingTCModeA_4_val();
  ref_getEngineTrqFromLookup();
  ref_calculateTorqueRelated();
  ref_calculateEngineMaxTorquePcnt__();
  ref_calculateTotalRequestedTrqPcnt();
  ref_calculateEngTorqueWithLosses();
  ref_calculateEngineTorqueWithTimingLoss__();
  FUN_0002cd8c();
  ref_setSR(uVar1);
  return;
}


