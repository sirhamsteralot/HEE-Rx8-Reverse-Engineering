/* ROM address: 0x0005b6f8; body bytes: 194; decompiled */

/* Function candidate recovered from ROM pointer at 5f378 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint uds_service_11_ecu_reset(short param_1,byte param_2)

{
  char cVar2;
  undefined4 uVar1;
  uint uVar3;
  char local_18 [4];
  short sStack_14;
  byte bStack_10;
  
  sStack_14 = param_1;
  bStack_10 = param_2;
  FUN_0005b7bc(0);
  uVar3 = (uint)bStack_10;
  if (uVar3 == 1) {
    if (sStack_14 == 1) {
      FUN_00068928(0x11,local_18,1);
      if (local_18[0] == '\x01') {
        cVar2 = FUN_00056678(1);
        if ((cVar2 == '\0') || (cVar2 = FUN_00056678(2), cVar2 == '\0')) {
          if (DAT_ffffd208 == '\x01') {
            uVar1 = FUN_0005b81a();
            FUN_0005b7bc(1);
          }
          else {
            uVar1 = FUN_00055112(0x11,0x22);
          }
        }
        else {
          uVar1 = FUN_00055112(0x11,0x33);
        }
      }
      else {
        uVar1 = FUN_00055112(0x11,0x12);
      }
    }
    else {
      uVar1 = FUN_00055112(0x11,0x12);
    }
    uVar3 = FUN_000550ca(0x11,uVar1);
  }
  else if (uVar3 == 0) {
    uVar3 = FUN_000550ee(0x11);
  }
  return uVar3;
}


