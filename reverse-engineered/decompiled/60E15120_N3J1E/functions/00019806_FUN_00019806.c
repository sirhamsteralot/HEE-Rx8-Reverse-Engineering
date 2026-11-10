/* ROM address: 0x00019806; body bytes: 30; decompiled */

void FUN_00019806(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  maf_voltage_and_fault_counters();
  FUN_0001a02c();
  ref_setSR(uVar1);
  return;
}


