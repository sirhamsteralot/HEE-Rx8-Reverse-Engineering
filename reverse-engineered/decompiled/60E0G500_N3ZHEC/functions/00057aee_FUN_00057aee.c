/* ROM address: 0x00057aee; body bytes: 34; decompiled */

/* Function candidate recovered from ROM pointer at 5fc30 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00057aee(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_ffffce58 == '\x01') {
    uVar1 = 0x40;
  }
  uVar1 = FUN_0005814c(uVar1,1);
  FUN_000581d2((int)param_1,uVar1);
  return;
}


