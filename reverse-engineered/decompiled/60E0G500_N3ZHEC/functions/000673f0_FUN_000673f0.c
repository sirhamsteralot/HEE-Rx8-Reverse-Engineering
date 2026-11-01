/* ROM address: 0x000673f0; body bytes: 52; decompiled */

/* Function candidate recovered from ROM pointer at 679f0 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined4 FUN_000673f0(char param_1,undefined4 param_2,short param_3,char param_4)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    uVar1 = FUN_00067458(param_2,(int)param_3);
  }
  else {
    uVar1 = FUN_00067534(param_2,(int)param_3,(int)param_4);
  }
  return uVar1;
}


