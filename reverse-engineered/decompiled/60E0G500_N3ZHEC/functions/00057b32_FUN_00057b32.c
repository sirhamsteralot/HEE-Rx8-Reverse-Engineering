/* ROM address: 0x00057b32; body bytes: 72; decompiled */

/* Function candidate recovered from ROM pointer at 5fc48 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00057b32(char param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (DAT_ffffb5ab == '\x01') {
    uVar2 = 4;
  }
  if (DAT_ffffaada == '\0') {
    uVar2 = uVar2 | 0x10;
  }
  uVar1 = FUN_0005814c(uVar2,1);
  FUN_000581d2((int)param_1,uVar1);
  uVar1 = FUN_0005814c(DAT_ffffc004 == '\x01',2);
  FUN_000581d2((int)param_1,uVar1);
  return;
}


