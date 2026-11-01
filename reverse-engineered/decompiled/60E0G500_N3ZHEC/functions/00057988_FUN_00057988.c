/* ROM address: 0x00057988; body bytes: 66; decompiled */

/* Function candidate recovered from ROM pointer at 5fbf4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1101_io_status_bf3c_ad18_cdd8(char param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  bVar2 = DAT_ffffbfa4 == '\x01';
  if (DAT_ffffad90 == '\x01') {
    bVar2 = bVar2 | 2;
  }
  if (DAT_ffffce18 == '\x01') {
    bVar2 = bVar2 | 8;
  }
  uVar1 = diag22_subpid_supported_mask(bVar2,1);
  diag_append_u8((int)param_1,uVar1);
  return;
}


