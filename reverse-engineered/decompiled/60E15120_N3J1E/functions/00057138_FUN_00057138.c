/* ROM address: 0x00057138; body bytes: 56; decompiled */

/* Function candidate recovered from ROM pointer at 5f438 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00057138(char param_1)

{
  undefined4 uVar1;
  byte bVar2;
  
  bVar2 = DAT_ffffb5b4 == '\x01';
  if (DAT_ffffbc35 == '\x01') {
    bVar2 = bVar2 | 0x20;
  }
  uVar1 = FUN_000579a8(bVar2,1);
  diag_append_u8((int)param_1,uVar1);
  diag_append_u8((int)param_1,0);
  return;
}


