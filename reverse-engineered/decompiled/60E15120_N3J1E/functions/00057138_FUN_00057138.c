/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid0968_io_status_b5b4_bc35 [high]: dispatch record 0x5f430 -> handler verified in ROM bytes + function_index; 0x579a8 submask over inferred_ram_b5b4_ffffb5b4_ffffb5b4 (bit0) / inferred_ram_bc35_ffffbc35_ffffbc35 (bit5); appends u8 + 0 | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffffb5b4 inferred_ram_b5b4_ffffb5b4 (uint8): PID 0x0968 -> bit 0
 * RAM 0xffffbc35 inferred_ram_bc35_ffffbc35 (uint8): PID 0x0968 -> bit 0x20
 */
/* ROM address: 0x00057138; body bytes: 56; decompiled */

/* Function candidate recovered from ROM pointer at 5f438 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0968_io_status_b5b4_bc35(char param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  bVar2 = inferred_ram_b5b4_ffffb5b4_ffffb5b4 == '\x01';
  if (inferred_ram_bc35_ffffbc35_ffffbc35 == '\x01') {
    bVar2 = bVar2 | 0x20;
  }
  uVar1 = diag22_subpid_supported_mask(bVar2,1);
  diag_append_u8((int)param_1,uVar1);
  diag_append_u8((int)param_1,0);
  return;
}


