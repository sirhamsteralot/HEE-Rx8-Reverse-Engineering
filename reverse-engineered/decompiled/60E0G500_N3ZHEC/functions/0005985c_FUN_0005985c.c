/* ROM address: 0x0005985c; body bytes: 108; decompiled */

/* Function candidate recovered from ROM pointer at 5f7bc and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_0005985c(undefined4 param_1,short param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char local_c [8];
  
  local_c[0] = '\0';
  if (param_2 == 0) {
    if (DAT_ffffa41c == '\0') {
      local_c[0] = '\"';
    }
  }
  else {
    local_c[0] = '\x12';
  }
  if (local_c[0] == '\0') {
    uVar3 = 0;
    DAT_ffffd27f = 1;
    uVar2 = 0;
  }
  else {
    DAT_ffffd27f = 0;
    param_3 = param_3 & 0xff;
    if (param_3 != 1) {
      if (param_3 != 0) {
        DAT_ffffd27f = 0;
        return param_3;
      }
      uVar1 = FUN_00067424(1,local_c,0);
      return uVar1;
    }
    uVar3 = 1;
    uVar2 = 2;
  }
  uVar1 = FUN_00067424(uVar2,local_c,uVar3);
  return uVar1;
}


