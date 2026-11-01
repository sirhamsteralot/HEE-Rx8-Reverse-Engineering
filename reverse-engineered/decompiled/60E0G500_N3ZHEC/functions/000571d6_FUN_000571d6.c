/* ROM address: 0x000571d6; body bytes: 38; decompiled */

/* Function candidate recovered from ROM pointer at 5f96c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_000571d6(char param_1)

{
  byte bVar2;
  uint uVar1;
  
  bVar2 = FUN_00055d2a();
  uVar1 = FUN_00055d50();
  FUN_000581b0((int)param_1,(uVar1 & 0xff) + (uint)bVar2 * 0x100);
  return;
}


