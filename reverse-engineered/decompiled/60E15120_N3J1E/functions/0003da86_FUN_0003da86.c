/* ROM address: 0x0003da86; body bytes: 92; decompiled */

uint FUN_0003da86(void)

{
  uint uVar1;
  
  if (DAT_ffffc630 == '\x01') {
    dtc_set_fault_x0(0x48,1);
  }
  else if (DAT_ffffc634 == 1) {
    dtc_set_fault_x0(0x48,2);
  }
  if (DAT_ffffc631 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x49,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc634;
    if (uVar1 == 1) {
      uVar1 = dtc_set_fault_x0(0x49,2);
    }
  }
  return uVar1;
}


