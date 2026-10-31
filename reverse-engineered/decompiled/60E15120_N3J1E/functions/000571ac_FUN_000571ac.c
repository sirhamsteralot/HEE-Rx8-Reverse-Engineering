/* ROM address: 0x000571ac; body bytes: 56; decompiled */

/* Function candidate recovered from ROM pointer at 5f444 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_000571ac(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = PEDR_W;
  uVar2 = FUN_000579a8((uVar1 & 0x400) != 0,1);
  diag_append_u8((int)param_1,uVar2);
  diag_append_u8((int)param_1,0);
  return;
}


