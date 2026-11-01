/* ROM address: 0x000576a0; body bytes: 52; decompiled */

/* Function candidate recovered from ROM pointer at 5fb1c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_000576a0(char param_1)

{
  undefined4 uVar1;
  float fVar2;
  
  fVar2 = (float)FUN_0003eb72(0x41700000,&DAT_ffff80a4);
  uVar1 = FUN_00002490((fVar2 - 0.0) / 25.0,0x38a00000,0);
  FUN_000581b0((int)param_1,uVar1);
  return;
}


