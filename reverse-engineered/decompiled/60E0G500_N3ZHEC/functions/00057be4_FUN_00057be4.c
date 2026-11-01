/* ROM address: 0x00057be4; body bytes: 46; decompiled */

/* Function candidate recovered from ROM pointer at 5fc6c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00057be4(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_fffff754;
  uVar2 = FUN_0005814c((uVar1 & 4) != 0,1);
  FUN_000581d2((int)param_1,uVar2);
  return;
}


