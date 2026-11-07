/* ROM address: 0x0003ae02; body bytes: 44; decompiled */

uint FUN_0003ae02(void)

{
  uint uVar1;
  
  if (DAT_ffffc578 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x39,1);
    return uVar1;
  }
  if (DAT_ffffc579 == 1) {
    uVar1 = dtc_set_fault_x0(0x39,2);
    return uVar1;
  }
  return (uint)DAT_ffffc579;
}


