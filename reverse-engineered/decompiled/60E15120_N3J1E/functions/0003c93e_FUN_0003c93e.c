/* ROM address: 0x0003c93e; body bytes: 92; decompiled */

uint FUN_0003c93e(void)

{
  uint uVar1;
  
  if (DAT_ffffc5de == '\x01') {
    dtc_set_fault_x0(0xf,1);
  }
  else if (DAT_ffffc5e0 == 1) {
    dtc_set_fault_x0(0xf,2);
  }
  if (DAT_ffffc5df == '\x01') {
    uVar1 = dtc_set_fault_x0(0x10,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc5e0;
    if (uVar1 == 1) {
      uVar1 = dtc_set_fault_x0(0x10,2);
    }
  }
  return uVar1;
}


