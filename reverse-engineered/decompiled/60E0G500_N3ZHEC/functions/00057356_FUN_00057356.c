/* ROM address: 0x00057356; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5fa2c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void diag22_pid0045_ram_ad48_pct(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = diag_encode_ad48();
  diag_append_u8((int)param_1,uVar1);
  return;
}


