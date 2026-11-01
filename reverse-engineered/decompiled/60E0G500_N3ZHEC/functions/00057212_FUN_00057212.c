/* ROM address: 0x00057212; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f984 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid001f_engine_runtime_s(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_read_runtime_s();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


