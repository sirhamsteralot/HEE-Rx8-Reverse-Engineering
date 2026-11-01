/* ROM address: 0x00057884; body bytes: 100; decompiled */

/* Function candidate recovered from ROM pointer at 5f564 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pidff10_dtc_status_c1d5_c1d8(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (inferred_ram_c1d8_ffffc1d8_ffffc1d8 == '\x01') {
    uVar2 = 0x40;
  }
  if (inferred_ram_c1d7_ffffc1d7_ffffc1d7 == '\x01') {
    uVar2 = uVar2 | 0x20;
  }
  if (inferred_ram_c1d6_ffffc1d6_ffffc1d6 == '\x01') {
    uVar2 = uVar2 | 8;
  }
  if (inferred_ram_c1d5_ffffc1d5_ffffc1d5 == '\x01') {
    uVar2 = uVar2 | 4;
  }
  uVar1 = diag22_subpid_supported_mask(uVar2,1);
  diag_append_u8(param_1,uVar1);
  diag_append_u8(param_1,0);
  diag_append_u8(param_1,0);
  diag_append_u8(param_1,0);
  return;
}


