/* ROM address: 0x0005e058; body bytes: 244; decompiled */

/* Function candidate recovered from ROM pointer at 5f3a8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint uds_service_3b(ushort param_1,uint param_2)

{
  char cVar2;
  uint uVar1;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    cVar2 = FUN_00056678(1);
    if ((cVar2 == '\0') || (cVar2 = FUN_00056678(2), cVar2 == '\0')) {
      if (param_1 < 2) {
        param_2 = FUN_00055112(0x3b,0x12);
        uVar1 = param_2;
      }
      else {
        FUN_00068928(0x3b,&DAT_ffffd3ae,1);
        DAT_ffffd3ac = param_1 - 1;
        if ((DAT_ffffd208 == '\x01') &&
           ((DAT_ffffd3ae < 0xe0 || (cVar2 = FUN_000565e2(3), cVar2 == '\0')))) {
          param_2 = FUN_0005e2dc();
          if ((param_2 & 0xff) == 0) {
            DAT_ffffd3b1 = 1;
            DAT_ffffd3b2 = 1;
            uVar1 = 0;
          }
          else {
            param_2 = FUN_00055112(0x3b);
            uVar1 = param_2;
          }
        }
        else {
          param_2 = FUN_00055112(0x3b,0x22);
          uVar1 = param_2;
        }
      }
    }
    else {
      param_2 = FUN_00055112(0x3b,0x33);
      uVar1 = param_2;
    }
    if ((uVar1 & 0xffff) != 0) {
      uVar1 = FUN_000550ca(0x3b,uVar1);
      return uVar1;
    }
  }
  else if (param_2 == 0) {
    uVar1 = FUN_000550ee(0x3b);
    return uVar1;
  }
  return param_2;
}


