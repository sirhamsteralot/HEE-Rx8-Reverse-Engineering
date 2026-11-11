/* ROM address: 0x000547d8; body bytes: 22; decompiled */

void FUN_000547d8(void)

{
  undefined4 uVar1;
  
  if (can_error_latch_ffffa40a == '\0') {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  dtc_set_fault_x0(0x7e,uVar1);
  return;
}


