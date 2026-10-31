/* ROM address: 0x000571e4; body bytes: 66; decompiled */

/* Function candidate recovered from ROM pointer at 5f450 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_000571e4(char param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  bVar2 = DAT_ffffbf3c == '\x01';
  if (DAT_ffffad18 == '\x01') {
    bVar2 = bVar2 | 2;
  }
  if (DAT_ffffcdd8 == '\x01') {
    bVar2 = bVar2 | 8;
  }
  uVar1 = FUN_000579a8(bVar2,1);
  diag_append_u8((int)param_1,uVar1);
  return;
}


