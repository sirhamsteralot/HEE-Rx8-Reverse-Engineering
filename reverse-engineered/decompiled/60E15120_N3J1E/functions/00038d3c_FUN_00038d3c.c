/* ROM address: 0x00038d3c; body bytes: 142; decompiled */

void FUN_00038d3c(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ref_fuelCutRelated_Something_();
  ref_fuelCutTimerAfterReset();
  FUN_0004aa60();
  FUN_0004aab0();
  FUN_0004ab02();
  FUN_0004ab68();
  FUN_0004ab9e();
  FUN_0004ac64();
  FUN_00044dc8();
  if ((((param_1 == '\x03') || (param_1 == '\t')) || (param_1 == '\x0f')) || (param_1 == '\x15')) {
    FUN_00044e90();
    FUN_00044ee8();
    FUN_00044f62();
    FUN_00045054();
    FUN_0004525c();
  }
  ref_setSR(uVar1);
  return;
}


