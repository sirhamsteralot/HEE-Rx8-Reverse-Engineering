/* ROM address: 0x0003b1b2; body bytes: 44; decompiled */

uint FUN_0003b1b2(void)

{
  uint uVar1;
  
  if (DAT_ffffc581 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x2f,1);
    return uVar1;
  }
  if (DAT_ffffc582 == 1) {
    uVar1 = dtc_set_fault_x0(0x2f,2);
    return uVar1;
  }
  return (uint)DAT_ffffc582;
}


