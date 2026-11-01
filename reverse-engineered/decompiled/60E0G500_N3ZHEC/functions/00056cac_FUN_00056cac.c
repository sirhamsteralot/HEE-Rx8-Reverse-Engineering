/* ROM address: 0x00056cac; body bytes: 166; decompiled */

/* Function candidate recovered from ROM pointer at 5f36c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_00056cac(short param_1,uint param_2)

{
  ushort uVar1;
  short sVar2;
  char local_10 [4];
  short sStack_c;
  
  uVar1 = DAT_ffffd3f0;
  param_2 = param_2 & 0xff;
  sStack_c = param_1;
  if (param_2 == 1) {
    if (param_1 == 1) {
      FUN_00068928(0x3e,local_10,1);
      if ((local_10[0] == '\x01') && ((uVar1 & 0xfffc) != 0)) {
        sVar2 = FUN_00056d52();
      }
      else if ((local_10[0] == '\x02') && ((uVar1 & 0xfffc) != 0)) {
        sVar2 = 0;
      }
      else {
        sVar2 = FUN_00055112(0x3e,0x12);
      }
    }
    else {
      sVar2 = FUN_00055112(0x3e,0x12);
    }
    if (sVar2 == 0) {
      param_2 = FUN_000550ee(0x3e);
    }
    else {
      param_2 = FUN_000550ca(0x3e);
    }
  }
  else if (param_2 == 0) {
    param_2 = FUN_000550ee(0x3e);
  }
  return param_2;
}


