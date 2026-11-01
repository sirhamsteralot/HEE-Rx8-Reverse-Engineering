/* ROM address: 0x00057950; body bytes: 56; decompiled */

/* Function candidate recovered from ROM pointer at 5fbe8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00057950(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_fffff754;
  uVar2 = FUN_0005814c((uVar1 & 0x400) != 0,1);
  FUN_000581d2((int)param_1,uVar2);
  FUN_000581d2((int)param_1,0);
  return;
}


