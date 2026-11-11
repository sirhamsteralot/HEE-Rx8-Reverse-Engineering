/* [ADDITIONAL SOURCE REVIEW]
 * diag22_pid1101_io_status_bf3c_ad18_cdd8 [high]: dispatch record 0x5f448 -> handler verified in ROM bytes + function_index; 0x579a8 over DAT_ffffbf3c(1), ffffad18(2), ffffcdd8(8) | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 * RAM 0xffffbf3c inferred_ram_bf3c_ffffbf3c (uint8): PID 0x1101 -> bit 1
 * RAM 0xffffad18 inferred_ram_ad18_ffffad18 (uint8): PID 0x1101 -> bit 2
 * RAM 0xffffcdd8 inferred_ram_cdd8_ffffcdd8 (uint8): PID 0x1101 -> bit 8
 */
/* ROM address: 0x000571e4; body bytes: 66; decompiled */

/* Function candidate recovered from ROM pointer at 5f450 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1101_io_status_bf3c_ad18_cdd8(char param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  bVar2 = inferred_ram_bf3c_ffffbf3c_ffffbf3c == '\x01';
  if (inferred_ram_ad18_ffffad18_ffffad18 == '\x01') {
    bVar2 = bVar2 | 2;
  }
  if (inferred_ram_cdd8_ffffcdd8_ffffcdd8 == '\x01') {
    bVar2 = bVar2 | 8;
  }
  uVar1 = diag22_subpid_supported_mask(bVar2,1);
  diag_append_u8((int)param_1,uVar1);
  return;
}


