/* ROM address: 0x00057b32; body bytes: 72; decompiled */

/* Function candidate recovered from ROM pointer at 5fc48 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pida211_status_b53b_aa62_bf9c(char param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (DAT_ffffb5ab == '\x01') {
    uVar2 = 4;
  }
  if (DAT_ffffaada == '\0') {
    uVar2 = uVar2 | 0x10;
  }
  uVar1 = diag22_subpid_supported_mask(uVar2,1);
  diag_append_u8((int)param_1,uVar1);
  uVar1 = diag22_subpid_supported_mask(DAT_ffffc004 == '\x01',2);
  diag_append_u8((int)param_1,uVar1);
  return;
}


