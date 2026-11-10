/* ROM address: 0x0003d71c; body bytes: 44; decompiled */

uint FUN_0003d71c(void)

{
  uint uVar1;
  
  if (DAT_ffffc62a == '\x01') {
    uVar1 = dtc_set_fault_x0(0x4c,1);
    return uVar1;
  }
  if (DAT_ffffc62b == 1) {
    uVar1 = dtc_set_fault_x0(0x4c,2);
    return uVar1;
  }
  return (uint)DAT_ffffc62b;
}


