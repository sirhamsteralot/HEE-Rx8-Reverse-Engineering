/* ROM address: 0x00057b94; body bytes: 46; decompiled */

/* Function candidate recovered from ROM pointer at 5fc54 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1711_pedr_bit1_status(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = DAT_fffff754;
  if ((uVar1 & 2) != 0) {
    uVar2 = 0x80;
  }
  uVar2 = diag22_subpid_supported_mask(uVar2,1);
  diag_append_u8((int)param_1,uVar2);
  return;
}


