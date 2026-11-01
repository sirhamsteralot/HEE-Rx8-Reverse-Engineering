/* ROM address: 0x0005732e; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5fa14 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0043_engine_load_g_rev(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_load_g_rev();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


