/* ROM address: 0x000573f0; body bytes: 46; decompiled */

/* Function candidate recovered from ROM pointer at 5f4b0 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_000573f0(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = PEDR_W;
  if ((uVar1 & 2) != 0) {
    uVar2 = 0x80;
  }
  uVar2 = FUN_000579a8(uVar2,1);
  diag_append_u8((int)param_1,uVar2);
  return;
}


