/* ROM address: 0x0003f7de; body bytes: 92; decompiled */

uint FUN_0003f7de(void)

{
  uint uVar1;
  
  if (DAT_ffffc6d5 == '\x01') {
    dtc_set_fault_x0(0x6e,1);
  }
  else if (DAT_ffffc6d4 == '\x01') {
    dtc_set_fault_x0(0x6e,2);
  }
  if (DAT_ffffc6d7 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x6d,1);
  }
  else {
    uVar1 = (uint)DAT_ffffc6d6;
    if (uVar1 == 1) {
      uVar1 = dtc_set_fault_x0(0x6d,2);
    }
  }
  return uVar1;
}


