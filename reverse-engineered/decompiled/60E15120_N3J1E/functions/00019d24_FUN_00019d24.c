/* ROM address: 0x00019d24; body bytes: 102; decompiled */

void FUN_00019d24(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_adcCoolantTemp2Volts();
  FUN_00018e7a();
  FUN_00018e84();
  ref_decrementTempForCatModel__();
  FUN_00018ee0();
  ref_adcIAT2Volts();
  FUN_0001be4a();
  FUN_0001be54();
  FUN_0001be6e();
  FUN_0001be98();
  FUN_0001bf94();
  FUN_0001ad3c();
  FUN_0001ad54();
  ref_pcmBoardTempADCtoVolts();
  ref_setSR(uVar1);
  return;
}


