/* ROM address: 0x000418f8; body bytes: 44; decompiled */

uint FUN_000418f8(void)

{
  uint uVar1;
  
  if (DAT_ffffc91d == '\x01') {
    uVar1 = dtc_set_fault_x0(2,1);
    return uVar1;
  }
  if (DAT_ffffc91c == 1) {
    uVar1 = dtc_set_fault_x0(2);
    return uVar1;
  }
  return (uint)DAT_ffffc91c;
}


