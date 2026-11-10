/* ROM address: 0x0003cf7e; body bytes: 92; decompiled */

uint FUN_0003cf7e(void)

{
  uint uVar1;
  
  if (DAT_ffffc5fc == '\x01') {
    dtc_set_fault_x0(0x15,1);
  }
  else if (DAT_ffffc5fd == '\x01') {
    dtc_set_fault_x0(0x15,2);
  }
  if (DAT_ffffc601 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x16,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc602;
    if (uVar1 == 1) {
      uVar1 = dtc_set_fault_x0(0x16,2);
    }
  }
  return uVar1;
}


