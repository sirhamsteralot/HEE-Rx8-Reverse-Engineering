/* ROM address: 0x00057440; body bytes: 46; decompiled */

/* Function candidate recovered from ROM pointer at 5f4c8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00057440(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = PEDR_W;
  uVar2 = FUN_000579a8((uVar1 & 4) != 0,1);
  diag_append_u8((int)param_1,uVar2);
  return;
}


