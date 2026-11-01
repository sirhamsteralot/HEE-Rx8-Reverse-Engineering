/* ROM address: 0x00057260; body bytes: 22; decompiled */

/* Function candidate recovered from ROM pointer at 5f9a8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid002e_ram_b2f0_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_b2f0();
  diag_append_u8((int)param_1,uVar1);
  return;
}


