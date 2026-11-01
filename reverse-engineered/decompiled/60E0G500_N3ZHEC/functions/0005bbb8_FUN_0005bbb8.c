/* ROM address: 0x0005bbb8; body bytes: 110; decompiled */

/* Function candidate recovered from ROM pointer at 5f384 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_0005bbb8(short param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 != 1) {
      uVar1 = FUN_00055112(0x21,0x12);
      uVar2 = FUN_000550ca(0x21,uVar1);
      return uVar2;
    }
    FUN_00068928(0x21,&DAT_ffffd324,1);
    param_2 = FUN_0005bc8c();
    if ((param_2 & 0xff) != 0) {
      uVar1 = FUN_00055112(0x21);
      uVar2 = FUN_000550ca(0x21,uVar1);
      return uVar2;
    }
    DAT_ffffd32c = 1;
    DAT_ffffd32d = 1;
  }
  else if (param_2 == 0) {
    uVar2 = FUN_000550ee(0x21);
    return uVar2;
  }
  return param_2;
}


