/* ROM address: 0x0005df60; body bytes: 104; decompiled */

/* Function candidate recovered from ROM pointer at 5f408 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint uds_service_34_request_download(short param_1,uint param_2)

{
  char cVar2;
  uint uVar1;
  undefined4 uVar3;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    cVar2 = FUN_00056678(1);
    if (cVar2 == '\0') {
      if (param_1 == 8) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = 0x12;
      }
      uVar3 = FUN_00055112(0x34,uVar3);
    }
    else {
      uVar3 = FUN_00055112(0x34,0x33);
    }
    uVar1 = FUN_000550ca(0x34,uVar3);
    return uVar1;
  }
  if (param_2 == 0) {
    uVar1 = FUN_000550ee(0x34);
    return uVar1;
  }
  return param_2;
}


