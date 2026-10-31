/* ROM address: 0x0005738e; body bytes: 72; decompiled */

/* Function candidate recovered from ROM pointer at 5f4a4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_0005738e(char param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (DAT_ffffb53b == '\x01') {
    uVar2 = 4;
  }
  if (DAT_ffffaa62 == '\0') {
    uVar2 = uVar2 | 0x10;
  }
  uVar1 = FUN_000579a8(uVar2,1);
  diag_append_u8((int)param_1,uVar1);
  uVar1 = FUN_000579a8(DAT_ffffbf9c == '\x01',2);
  diag_append_u8((int)param_1,uVar1);
  return;
}


