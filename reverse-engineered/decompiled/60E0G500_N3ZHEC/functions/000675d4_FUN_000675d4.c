/* ROM address: 0x000675d4; body bytes: 42; decompiled */

/* Function candidate recovered from ROM pointer at 67b74 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined4 FUN_000675d4(char param_1,char *param_2,short param_3)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    uVar1 = FUN_000675fe(param_2,(int)param_3);
  }
  else {
    uVar1 = FUN_000676aa((int)*param_2);
  }
  return uVar1;
}


