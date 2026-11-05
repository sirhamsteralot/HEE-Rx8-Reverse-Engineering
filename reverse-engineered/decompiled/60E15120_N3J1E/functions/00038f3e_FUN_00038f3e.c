/* ROM address: 0x00038f3e; body bytes: 72; decompiled */

void FUN_00038f3e(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00045fd6();
  FUN_00046028();
  FUN_000460ee();
  FUN_0004b4f8();
  FUN_0004281c();
  FUN_00042968();
  FUN_00044ffc();
  o2_response_monitor_accumulate();
  o2_response_monitor_evaluate();
  ref_setSR(uVar1);
  return;
}


