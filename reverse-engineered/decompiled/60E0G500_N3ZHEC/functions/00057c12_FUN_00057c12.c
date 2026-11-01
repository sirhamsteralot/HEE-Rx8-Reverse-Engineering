/* ROM address: 0x00057c12; body bytes: 72; decompiled */

/* Function candidate recovered from ROM pointer at 5fc78 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid1715_pedr_pddr_status(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar1 = DAT_fffff754;
  if ((uVar1 & 0x80) != 0) {
    uVar3 = 0x40;
  }
  uVar1 = DAT_fffff746;
  if ((uVar1 & 0x20) != 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar2 = diag22_subpid_supported_mask(uVar3,1);
  diag_append_u8((int)param_1,uVar2);
  return;
}


