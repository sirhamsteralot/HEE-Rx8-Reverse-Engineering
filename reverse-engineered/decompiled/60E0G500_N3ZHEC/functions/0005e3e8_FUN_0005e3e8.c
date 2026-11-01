/* ROM address: 0x0005e3e8; body bytes: 180; decompiled */

/* Function candidate recovered from ROM pointer at 5f348 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint uds_service_85_control_dtc_setting(short param_1,uint param_2)

{
  ushort uVar1;
  char cVar3;
  undefined4 uVar2;
  char local_18 [4];
  short sStack_14;
  
  uVar1 = DAT_ffffd3f0;
  param_2 = param_2 & 0xff;
  sStack_14 = param_1;
  if (param_2 == 1) {
    if (param_1 == 1) {
      cVar3 = FUN_000565e2(0);
      if (cVar3 == '\0') {
        FUN_00068928(0x85,local_18,(int)sStack_14);
        if (((local_18[0] == '\x01') && ((uVar1 & 0xfffc) != 0)) ||
           ((local_18[0] == '\x02' && ((uVar1 & 0xfffc) != 0)))) {
          FUN_0005e58c((int)local_18[0]);
          uVar2 = FUN_0005e5bc((int)local_18[0]);
        }
        else {
          uVar2 = FUN_00055112(0x85,0x12);
        }
      }
      else {
        uVar2 = FUN_00055112(0x85,0x22);
      }
    }
    else {
      uVar2 = FUN_00055112(0x85,0x12);
    }
    param_2 = FUN_000550ca(0x85,uVar2);
  }
  else if (param_2 == 0) {
    param_2 = FUN_000550ee(0x85);
  }
  return param_2;
}


