/* ROM address: 0x0005dfd8; body bytes: 50; decompiled */

/* Function candidate recovered from ROM pointer at 5f414 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint uds_service_36_transfer_data(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    uVar1 = FUN_00055112(0x36,0x22);
    uVar2 = FUN_000550ca(0x36,uVar1);
    return uVar2;
  }
  if (param_2 == 0) {
    uVar2 = FUN_000550ee(0x36);
    return uVar2;
  }
  return param_2;
}


