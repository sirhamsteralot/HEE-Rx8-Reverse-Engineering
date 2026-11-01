/* ROM address: 0x000578dc; body bytes: 56; decompiled */

/* Function candidate recovered from ROM pointer at 5fbdc and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0968_io_status_b5b4_bc35(char param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  bVar2 = DAT_ffffb624 == '\x01';
  if (DAT_ffffbca1 == '\x01') {
    bVar2 = bVar2 | 0x20;
  }
  uVar1 = diag22_subpid_supported_mask(bVar2,1);
  diag_append_u8((int)param_1,uVar1);
  diag_append_u8((int)param_1,0);
  return;
}


