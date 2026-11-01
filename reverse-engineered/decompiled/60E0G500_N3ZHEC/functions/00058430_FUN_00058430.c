/* ROM address: 0x00058430; body bytes: 160; decompiled */

/* Function candidate recovered from ROM pointer at 5f354 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_00058430(short param_1,uint param_2)

{
  uint uVar1;
  char cVar4;
  uint uVar2;
  undefined4 uVar3;
  char local_14 [8];
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 == 1) {
      FUN_00068928(0x10,local_14,1);
      uVar1 = FUN_00056586((int)local_14[0]);
      if ((uVar1 & 0xff) == 5) {
        uVar3 = FUN_00055112(0x10,0x12);
      }
      else {
        cVar4 = FUN_000584f4(uVar1);
        if (cVar4 == '\0') {
          uVar2 = FUN_000565ce();
          if ((uVar1 & 0xff) != (uVar2 & 0xff)) {
            FUN_00056454(uVar1);
          }
          uVar3 = FUN_000584d0((int)local_14[0]);
        }
        else {
          uVar3 = FUN_00055112(0x10,0x22);
        }
      }
    }
    else {
      uVar3 = FUN_00055112(0x10,0x12);
    }
    param_2 = FUN_000550ca(0x10,uVar3);
  }
  else if (param_2 == 0) {
    param_2 = FUN_000550ee(0x10);
  }
  return param_2;
}


