/* ROM address: 0x00056050; body bytes: 150; decompiled */

/* Function candidate recovered from ROM pointer at 5f3cc and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_00056050(short param_1,uint param_2)

{
  uint uVar1;
  undefined1 local_10;
  undefined1 uStack_f;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 == 2) {
      FUN_00068928(0x14,&local_10,2);
      DAT_ffffd202 = CONCAT11(local_10,uStack_f);
      if (DAT_ffffd202 == -0x100) {
        FUN_00056136(0x14);
        param_2 = FUN_000622a6(&PTR_FUN_0000ff00);
        uVar1 = 0;
      }
      else {
        param_2 = FUN_00055112(0x14,0x31);
        uVar1 = param_2;
      }
    }
    else {
      param_2 = FUN_00055112(0x14,0x12);
      uVar1 = param_2;
    }
    if ((uVar1 & 0xffff) != 0) {
      param_2 = FUN_000550ca(0x14,uVar1);
    }
  }
  else if (param_2 == 0) {
    param_2 = FUN_000550ee(0x14);
  }
  return param_2;
}


