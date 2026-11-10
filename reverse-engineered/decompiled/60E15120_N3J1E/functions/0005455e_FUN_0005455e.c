/* ROM address: 0x0005455e; body bytes: 28; decompiled */

void FUN_0005455e(void)

{
  if (DAT_ffffd1b8 == '\x01') {
    dtc_set_fault_x0(0x45,1);
    return;
  }
  dtc_set_fault_x0(0x45,2);
  return;
}


