/* ROM address: 0x00057430; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5fa5c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid004c_ram_b410_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_b410();
  diag_append_u8((int)param_1,uVar1);
  return;
}


