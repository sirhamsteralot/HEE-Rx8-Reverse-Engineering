/* ROM address: 0x00057988; body bytes: 66; decompiled */

/* Function candidate recovered from ROM pointer at 5fbf4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00057988(char param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  bVar2 = DAT_ffffbfa4 == '\x01';
  if (DAT_ffffad90 == '\x01') {
    bVar2 = bVar2 | 2;
  }
  if (DAT_ffffce18 == '\x01') {
    bVar2 = bVar2 | 8;
  }
  uVar1 = FUN_0005814c(bVar2,1);
  FUN_000581d2((int)param_1,uVar1);
  return;
}


