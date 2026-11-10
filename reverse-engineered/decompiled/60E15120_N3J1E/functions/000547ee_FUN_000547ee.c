/* ROM address: 0x000547ee; body bytes: 108; decompiled */

void FUN_000547ee(void)

{
  undefined4 uVar1;
  
  if (DAT_ffffa402 == '\0') {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  dtc_set_fault_x0(0x7f,uVar1);
  dtc_set_fault_x0(0x80);
  if (DAT_ffffa403 == '\0') {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  dtc_set_fault_x0(0x81,uVar1);
  if (DAT_ffffa404 == '\0') {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  dtc_set_fault_x0(0x82,uVar1);
  return;
}


