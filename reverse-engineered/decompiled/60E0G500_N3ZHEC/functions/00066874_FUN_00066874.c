/* ROM address: 0x00066874; body bytes: 162; decompiled */

/* Function candidate recovered from ROM pointer at 5f30c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_00066874(short param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 local_2c [4];
  char cStack_28;
  undefined4 local_24;
  undefined **ppuStack_20;
  
  bVar1 = param_1 != 0;
  cStack_28 = (char)param_2;
  if (!bVar1) {
    param_2 = FUN_0006693e();
    if ((param_2 & 0xff) == 0) {
      DAT_ffffd994 = 1;
      local_24 = 4;
      ppuStack_20 = &PTR_FUN_0000ff00;
      FUN_00009630(2,3);
      local_2c[0] = 0x44;
      param_2 = FUN_000688c8(4,local_2c,1);
    }
    else {
      bVar1 = false;
    }
  }
  uVar2 = (uint)bVar1;
  if (uVar2 != 0) {
    if (uVar2 == 1) {
      if (cStack_28 == '\x01') {
        uVar3 = 2;
      }
      else {
        uVar3 = 1;
      }
      param_2 = FUN_00066ece(4,0x12,uVar3);
    }
    else {
      param_2 = uVar2;
      if (uVar2 == 2) {
        param_2 = FUN_00066ece(4,0x22,1);
      }
    }
  }
  return param_2;
}


