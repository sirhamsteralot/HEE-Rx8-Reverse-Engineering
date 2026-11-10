/* ROM address: 0x0003f11e; body bytes: 132; decompiled */

uint FUN_0003f11e(void)

{
  uint uVar1;
  
  if (DAT_ffffc6b9 == '\x01') {
    dtc_set_fault_x0(0x73,1);
  }
  else if (DAT_ffffc6b8 == '\x01') {
    dtc_set_fault_x0(0x73,2);
  }
  if (DAT_ffffc6bb == '\x01') {
    dtc_set_fault_x0(0x74,1);
  }
  else if (DAT_ffffc6ba == '\x01') {
    dtc_set_fault_x0(0x74,2);
  }
  if (DAT_ffffc6bd == '\x01') {
    uVar1 = dtc_set_fault_x0(0x1d,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc6bc;
    if (uVar1 == 1) {
      uVar1 = dtc_set_fault_x0(0x1d,2);
    }
  }
  return uVar1;
}


