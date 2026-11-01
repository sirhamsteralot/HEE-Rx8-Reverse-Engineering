/* ROM address: 0x00057950; body bytes: 56; decompiled */

/* Function candidate recovered from ROM pointer at 5fbe8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid09d3_pedr_bit10_status(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_fffff754;
  uVar2 = diag22_subpid_supported_mask((uVar1 & 0x400) != 0,1);
  diag_append_u8((int)param_1,uVar2);
  diag_append_u8((int)param_1,0);
  return;
}


