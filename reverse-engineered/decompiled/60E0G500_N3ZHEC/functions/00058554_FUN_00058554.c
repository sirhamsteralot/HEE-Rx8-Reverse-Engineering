/* ROM address: 0x00058554; body bytes: 194; decompiled */

/* Function candidate recovered from ROM pointer at 5f3b4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_00058554(short param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  char local_18;
  char cStack_17;
  char cStack_16;
  
  uVar1 = DAT_ffffd3f0;
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 == 3) {
      FUN_00068928(0x18,&local_18,3);
      if (((local_18 == '\0') && ((uVar1 & 0xfffc) != 0)) ||
         ((local_18 == '\x01' && ((uVar1 & 0xfffc) != 0)))) {
        if ((cStack_17 == -1) && (cStack_16 == '\0')) {
          param_2 = FUN_0005890c((int)local_18);
          uVar2 = 0;
        }
        else {
          param_2 = FUN_00055112(0x18,0x31);
          uVar2 = param_2;
        }
      }
      else {
        param_2 = FUN_00055112(0x18,0x12);
        uVar2 = param_2;
      }
    }
    else {
      param_2 = FUN_00055112(0x18,0x12);
      uVar2 = param_2;
    }
    if ((uVar2 & 0xffff) != 0) {
      param_2 = FUN_000550ca(0x18,uVar2);
    }
  }
  else if (param_2 == 0) {
    param_2 = FUN_000550ee(0x18);
  }
  return param_2;
}


