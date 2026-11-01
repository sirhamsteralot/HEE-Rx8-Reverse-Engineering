/* ROM address: 0x000572b2; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f9d8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0033_ram_ad10_scaled(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_ad10();
  diag_append_u8((int)param_1,uVar1);
  return;
}


