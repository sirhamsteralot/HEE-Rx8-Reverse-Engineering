/* ROM address: 0x0005741e; body bytes: 34; decompiled */

/* Function candidate recovered from ROM pointer at 5f4bc and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_0005741e(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_ffffa8f5 == '\x01') {
    uVar1 = 4;
  }
  uVar1 = FUN_000579a8(uVar1,1);
  diag_append_u8((int)param_1,uVar1);
  return;
}


