/* ROM address: 0x0003898a; body bytes: 44; decompiled */

uint FUN_0003898a(void)

{
  uint uVar1;
  
  if (DAT_ffffc500 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x18,1);
    return uVar1;
  }
  if (DAT_ffffc501 == 1) {
    uVar1 = dtc_set_fault_x0(0x18,2);
    return uVar1;
  }
  return (uint)DAT_ffffc501;
}


