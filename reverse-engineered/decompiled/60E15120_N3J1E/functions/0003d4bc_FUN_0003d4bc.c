/* ROM address: 0x0003d4bc; body bytes: 44; decompiled */

uint FUN_0003d4bc(void)

{
  uint uVar1;
  
  if (DAT_ffffc61e == '\x01') {
    uVar1 = dtc_set_fault_x0(0x3a,1);
    return uVar1;
  }
  if (DAT_ffffc61f == 1) {
    uVar1 = dtc_set_fault_x0(0x3a,2);
    return uVar1;
  }
  return (uint)DAT_ffffc61f;
}


