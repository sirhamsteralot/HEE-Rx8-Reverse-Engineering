/* ROM address: 0x0005bef4; body bytes: 156; decompiled */

/* Function candidate recovered from ROM pointer at 5f39c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_0005bef4(short param_1,uint param_2)

{
  char cVar3;
  undefined4 uVar1;
  uint uVar2;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 == 6) {
      cVar3 = FUN_00056678(1);
      if (cVar3 == '\0') {
        FUN_00068928(0x23,&DAT_ffffd33a,6);
        param_2 = FUN_0005c062();
        if ((param_2 & 0xff) == 0) {
          DAT_ffffd344 = 1;
        }
        else {
          uVar1 = FUN_00055112(0x23,0x31);
          param_2 = FUN_000550ca(0x23,uVar1);
        }
      }
      else {
        uVar1 = FUN_00055112(0x23,0x33);
        param_2 = FUN_000550ca(0x23,uVar1);
      }
    }
    else {
      uVar1 = FUN_00055112(0x23,0x12);
      param_2 = FUN_000550ca(0x23,uVar1);
    }
  }
  else if (param_2 == 0) {
    uVar2 = FUN_000550ee(0x23);
    return uVar2;
  }
  return param_2;
}


