/* ROM address: 0x0003a8cc; body bytes: 92; decompiled */

uint FUN_0003a8cc(void)

{
  uint uVar1;
  
  if (DAT_ffffc561 == '\x01') {
    dtc_set_fault_x0(0x71,1);
  }
  else if (DAT_ffffc563 == 1) {
    dtc_set_fault_x0(0x71,2);
  }
  if (DAT_ffffc562 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x72,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc563;
    if (uVar1 == 1) {
      uVar1 = dtc_set_fault_x0(0x72,2);
    }
  }
  return uVar1;
}


