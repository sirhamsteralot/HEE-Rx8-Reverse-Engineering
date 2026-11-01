/* ROM address: 0x00056d8c; body bytes: 234; decompiled */

/* Function candidate recovered from ROM pointer at 5f42c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_00056d8c(uint param_1,uint param_2)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  ushort local_24 [2];
  ushort local_20 [8];
  
  uVar1 = DAT_ffffd3f0;
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if ((param_1 & 0xffff) < 2) {
      param_2 = FUN_00055112(0xb1,0x12);
    }
    else {
      FUN_00068928(0xb1,local_24,2);
      puVar2 = local_20;
      uVar3 = (uint)local_24[0];
      do {
        FUN_00004218();
        uVar4 = (uint)*puVar2;
        if (uVar4 == (uVar3 & 0xffff)) break;
      } while (uVar4 != 0);
      if (uVar4 == 0) {
        param_2 = (**(code **)(puVar2 + 2))();
      }
      else if ((uVar1 & puVar2[4]) == 0) {
        param_2 = FUN_00056f66();
      }
      else if ((uint)puVar2[1] == (param_1 & 0xffff) - 2) {
        param_2 = (**(code **)(puVar2 + 2))();
      }
      else {
        param_2 = FUN_00055112(0xb1,0x12);
      }
    }
    if ((param_2 & 0xffff) != 0) {
      param_2 = FUN_000550ca(0xb1);
    }
  }
  else if (param_2 == 0) {
    param_2 = FUN_000550ee(0xb1);
  }
  return param_2;
}


