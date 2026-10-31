/* ROM address: 0x00056aa8; body bytes: 20; decompiled */

/* Function candidate recovered from ROM pointer at 5f1f8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00056aa8(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_000555f8();
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


