/* ROM address: 0x00057bc2; body bytes: 34; decompiled */

/* Function candidate recovered from ROM pointer at 5fc60 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00057bc2(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_ffffa976 == '\x01') {
    uVar1 = 4;
  }
  uVar1 = FUN_0005814c(uVar1,1);
  FUN_000581d2((int)param_1,uVar1);
  return;
}


