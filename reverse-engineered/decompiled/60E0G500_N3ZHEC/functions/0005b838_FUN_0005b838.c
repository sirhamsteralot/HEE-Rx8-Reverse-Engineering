/* ROM address: 0x0005b838; body bytes: 154; decompiled */

/* Function candidate recovered from ROM pointer at 5f3c0 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint uds_service_12(ushort param_1,uint param_2)

{
  uint uVar1;
  char local_18;
  char cStack_17;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 < 2) {
      param_2 = FUN_00055112(0x12);
      uVar1 = param_2;
    }
    else {
      FUN_00068928(0x12,&local_18,2);
      if ((local_18 == '\0') && (cStack_17 == '\x04')) {
        if (param_1 == 4) {
          param_2 = FUN_0005ba96(2);
          uVar1 = 0;
        }
        else {
          param_2 = FUN_00055112(0x12);
          uVar1 = param_2;
        }
      }
      else {
        param_2 = FUN_00055112(0x12,0x31);
        uVar1 = param_2;
      }
    }
    if ((uVar1 & 0xffff) != 0) {
      param_2 = FUN_000550ca(0x12,uVar1);
    }
  }
  else if (param_2 == 0) {
    param_2 = FUN_000550ee(0x12);
  }
  return param_2;
}


