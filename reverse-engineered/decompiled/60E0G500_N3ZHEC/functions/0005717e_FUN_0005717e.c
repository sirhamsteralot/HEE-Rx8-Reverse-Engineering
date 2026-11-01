/* ROM address: 0x0005717e; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f93c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0010_maf_g_s(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_maf();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


