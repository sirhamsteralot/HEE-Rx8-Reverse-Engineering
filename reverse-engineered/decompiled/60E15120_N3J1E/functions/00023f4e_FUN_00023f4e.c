/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_stored_dtc_replay [high]: Maps stored flag bits 0xffffb4ec-0xffffb51b (unpacked by 0x23844) to 38 set_fault calls 0x5fd38(id, 1|2) for ids 0x13,0x14,0x21,0x22,0x42,0x47,0x4f,0x5b-0x5d,0x5f,0x60,0x61,0x65,0x6a,0x6b,0x83,0x84,100; restores the DTC history stored in E2RAM at load.
 * RAM 0xffffb4ec stored_dtc_flag_bits (uint8): Unpacked DTC history flags (0xffffb4ec-0xffffb51b) decoded by 0x23844 via 0x24b00; replayed by 0x23f4e through 0x5fd38.
 */
/* ROM address: 0x00023f4e; body bytes: 772; decompiled */

uint e2ram_stored_dtc_replay(void)

{
  uint uVar1;
  
  if (DAT_ffffb500 == '\x01') {
    dtc_set_fault_x0(0x14,1);
  }
  else if (DAT_ffffb501 == '\x01') {
    dtc_set_fault_x0(0x14,2);
  }
  if (DAT_ffffb503 == '\x01') {
    dtc_set_fault_x0(0x13,1);
  }
  else if (DAT_ffffb504 == '\x01') {
    dtc_set_fault_x0(0x13,2);
  }
  if (DAT_ffffb50a == '\x01') {
    dtc_set_fault_x0(0x6a,1);
  }
  else if (DAT_ffffb50b == '\x01') {
    dtc_set_fault_x0(0x6a,2);
  }
  if (DAT_ffffb505 == '\x01') {
    dtc_set_fault_x0(0x22,1);
  }
  else if (DAT_ffffb506 == '\x01') {
    dtc_set_fault_x0(0x22,2);
  }
  if (DAT_ffffb507 == '\x01') {
    dtc_set_fault_x0(0x21,1);
  }
  else if (DAT_ffffb508 == '\x01') {
    dtc_set_fault_x0(0x21,2);
  }
  if (DAT_ffffb4f0 == '\x01') {
    dtc_set_fault_x0(0x47,1);
  }
  else if (DAT_ffffb4f1 == '\x01') {
    dtc_set_fault_x0(0x47,2);
  }
  if (DAT_ffffb4f3 == '\x01') {
    dtc_set_fault_x0(100,1);
  }
  else if (DAT_ffffb4f4 == '\x01') {
    dtc_set_fault_x0(100,2);
  }
  if (DAT_ffffb4f5 == '\x01') {
    dtc_set_fault_x0(0x5d,1);
  }
  else if (DAT_ffffb4f6 == '\x01') {
    dtc_set_fault_x0(0x5d,2);
  }
  if (DAT_ffffb4f7 == '\x01') {
    dtc_set_fault_x0(0x5b,1);
  }
  else if (DAT_ffffb4f8 == '\x01') {
    dtc_set_fault_x0(0x5b,2);
  }
  if (DAT_ffffb4f9 == '\x01') {
    dtc_set_fault_x0(0x5c,1);
  }
  else if (DAT_ffffb4fa == '\x01') {
    dtc_set_fault_x0(0x5c,2);
  }
  if (DAT_ffffb4fb == '\x01') {
    dtc_set_fault_x0(0x83,1);
  }
  else if (DAT_ffffb4fc == '\x01') {
    dtc_set_fault_x0(0x83,2);
  }
  if (DAT_ffffb4fd == '\x01') {
    dtc_set_fault_x0(0x65,1);
  }
  else if (DAT_ffffb4fe == '\x01') {
    dtc_set_fault_x0(0x65,2);
  }
  if (DAT_ffffb50c == '\x01') {
    dtc_set_fault_x0(0x4f,1);
  }
  else if (DAT_ffffb50d == '\x01') {
    dtc_set_fault_x0(0x4f,2);
  }
  if (DAT_ffffb50e == '\x01') {
    dtc_set_fault_x0(0x61,1);
  }
  else if (DAT_ffffb50f == '\x01') {
    dtc_set_fault_x0(0x61,2);
  }
  if (DAT_ffffb510 == '\x01') {
    dtc_set_fault_x0(0x5f,1);
  }
  else if (DAT_ffffb511 == '\x01') {
    dtc_set_fault_x0(0x5f,2);
  }
  if (DAT_ffffb512 == '\x01') {
    dtc_set_fault_x0(0x60,1);
  }
  else if (DAT_ffffb513 == '\x01') {
    dtc_set_fault_x0(0x60,2);
  }
  if (DAT_ffffb514 == '\x01') {
    dtc_set_fault_x0(0x6b,1);
  }
  else if (DAT_ffffb515 == '\x01') {
    dtc_set_fault_x0(0x6b,2);
  }
  if (DAT_ffffb518 == '\x01') {
    dtc_set_fault_x0(0x42,1);
  }
  else if (DAT_ffffb519 == '\x01') {
    dtc_set_fault_x0(0x42,2);
  }
  if (DAT_ffffb516 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x84,1);
  }
  else {
    uVar1 = (uint)DAT_ffffb517;
    if (uVar1 == 1) {
      uVar1 = dtc_set_fault_x0(0x84,2);
    }
  }
  return uVar1;
}


