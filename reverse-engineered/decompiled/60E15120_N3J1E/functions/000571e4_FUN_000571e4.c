/* ROM address: 0x000571e4; body bytes: 66; decompiled */

/* Function candidate recovered from ROM pointer at 5f450 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid1101_io_status_bf3c_ad18_cdd8(char param_1)

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


