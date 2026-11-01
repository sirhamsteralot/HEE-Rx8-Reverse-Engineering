/* ROM address: 0x00057248; body bytes: 116; decompiled */

/* Function candidate recovered from ROM pointer at 5f468 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void candidate_diag22_pid1103_io_status_pedr_cab4_d1a(char param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar1 = PEDR_W;
  uVar2 = PEDR_W;
  if ((uVar1 & 0x800) != 0) {
    uVar4 = 4;
  }
  if ((uVar2 & 0x10) != 0) {
    uVar4 = uVar4 | 8;
  }
  if (inferred_ram_cab4_ffffcab4_ffffcab4 == '\x01') {
    uVar4 = uVar4 | 0x10;
  }
  if ((inferred_ram_d1a2_ffffd1a2_ffffd1a2 == '\x01') || (inferred_ram_d1a1_ffffd1a1_ffffd1a1 == '\x01')) {
    uVar4 = uVar4 | 0x20;
  }
  uVar3 = diag22_subpid_supported_mask(uVar4,1);
  diag_append_u8((int)param_1,uVar3);
  return;
}


