/* ROM address: 0x0003bf68; body bytes: 172; decompiled */

uint FUN_0003bf68(void)

{
  uint uVar1;
  
  if (DAT_ffffc5af == '\x01') {
    dtc_set_fault_x0(0x34,1);
  }
  else if (DAT_ffffc5b2 == '\x01') {
    dtc_set_fault_x0(0x34,2);
  }
  if (DAT_ffffc5b0 == '\x01') {
    dtc_set_fault_x0(0x36,1);
  }
  else if (DAT_ffffc5b2 == '\x01') {
    dtc_set_fault_x0(0x36,2);
  }
  if (DAT_ffffc5bb == '\x01') {
    dtc_set_fault_x0(0x35,1);
  }
  else if (DAT_ffffc5be == 1) {
    dtc_set_fault_x0(0x35,2);
  }
  if (DAT_ffffc5bc == '\x01') {
    uVar1 = dtc_set_fault_x0(0x37,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc5be;
    if (uVar1 == 1) {
      uVar1 = dtc_set_fault_x0(0x37,2);
    }
  }
  return uVar1;
}


