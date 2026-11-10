/* ROM address: 0x0004a84e; body bytes: 92; decompiled */

uint FUN_0004a84e(void)

{
  uint uVar1;
  
  if (DAT_ffffcd7c == '\x01') {
    dtc_set_fault_x0(0x59,1);
  }
  else if (DAT_ffffcd81 == '\x01') {
    dtc_set_fault_x0(0x59,2);
  }
  if (DAT_ffffcd7e == '\x01') {
    uVar1 = dtc_set_fault_x0(0x5a,1);
  }
  else {
    uVar1 = (uint)DAT_ffffcd80;
    if (uVar1 == 1) {
      uVar1 = dtc_set_fault_x0(0x5a,2);
    }
  }
  return uVar1;
}


