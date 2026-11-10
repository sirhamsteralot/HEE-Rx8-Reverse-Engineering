/* ROM address: 0x00054486; body bytes: 28; decompiled */

void FUN_00054486(void)

{
  if (DAT_ffffd1b4 == '\x01') {
    dtc_set_fault_x0(0x43,1);
    return;
  }
  dtc_set_fault_x0(0x43,2);
  return;
}


