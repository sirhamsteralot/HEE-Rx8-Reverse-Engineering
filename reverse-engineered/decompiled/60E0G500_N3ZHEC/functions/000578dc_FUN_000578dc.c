/* ROM address: 0x000578dc; body bytes: 56; decompiled */

/* Function candidate recovered from ROM pointer at 5fbdc and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_000578dc(char param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  bVar2 = DAT_ffffb624 == '\x01';
  if (DAT_ffffbca1 == '\x01') {
    bVar2 = bVar2 | 0x20;
  }
  uVar1 = FUN_0005814c(bVar2,1);
  FUN_000581d2((int)param_1,uVar1);
  FUN_000581d2((int)param_1,0);
  return;
}


