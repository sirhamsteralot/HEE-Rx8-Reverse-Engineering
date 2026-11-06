/* ROM address: 0x0003d774; body bytes: 44; decompiled */

uint FUN_0003d774(void)

{
  uint uVar1;
  
  if (DAT_ffffc628 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x4b,1);
    return uVar1;
  }
  if (DAT_ffffc629 == 1) {
    uVar1 = dtc_set_fault_x0(0x4b,2);
    return uVar1;
  }
  return (uint)DAT_ffffc629;
}


