/* ROM address: 0x0005e704; body bytes: 196; decompiled */

/* Function candidate recovered from ROM pointer at 5f3e4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_0005e704(short param_1,uint param_2)

{
  char cVar2;
  undefined4 uVar1;
  int iVar3;
  char local_18;
  char cStack_17;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 == 2) {
      FUN_00068928(0x31,&local_18,2);
      iVar3 = (int)local_18;
      cVar2 = FUN_0005999e(iVar3);
      if (cVar2 == '\0') {
        cVar2 = FUN_00059934(iVar3);
        if ((cVar2 == '\0') && (cVar2 = FUN_0005998c(iVar3,(int)cStack_17), cVar2 == '\0')) {
          uVar1 = FUN_0005ea12(iVar3);
          DAT_ffffd3c3 = 1;
          FUN_00059abe(iVar3,(int)cStack_17);
        }
        else {
          uVar1 = FUN_00055112(0x31);
          FUN_00059b2c();
        }
      }
      else {
        uVar1 = FUN_00055112(0x31,0x22);
      }
    }
    else {
      uVar1 = FUN_00055112(0x31,0x12);
    }
    param_2 = FUN_000550ca(0x31,uVar1);
  }
  else if (param_2 == 0) {
    param_2 = FUN_000550ee(0x31);
  }
  return param_2;
}


