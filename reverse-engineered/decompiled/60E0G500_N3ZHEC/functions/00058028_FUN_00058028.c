/* ROM address: 0x00058028; body bytes: 100; decompiled */

/* Function candidate recovered from ROM pointer at 5fd08 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00058028(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (DAT_ffffc248 == '\x01') {
    uVar2 = 0x40;
  }
  if (DAT_ffffc247 == '\x01') {
    uVar2 = uVar2 | 0x20;
  }
  if (DAT_ffffc246 == '\x01') {
    uVar2 = uVar2 | 8;
  }
  if (DAT_ffffc245 == '\x01') {
    uVar2 = uVar2 | 4;
  }
  uVar1 = FUN_0005814c(uVar2,1);
  FUN_000581d2(param_1,uVar1);
  FUN_000581d2(param_1,0);
  FUN_000581d2(param_1,0);
  FUN_000581d2(param_1,0);
  return;
}


