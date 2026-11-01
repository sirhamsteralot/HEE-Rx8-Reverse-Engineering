/* ROM address: 0x00058fd0; body bytes: 104; decompiled */

void FUN_00058fd0(void)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 local_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  
  uVar4 = 0;
  fVar2 = 1000.0;
  uVar3 = 0x3b800000;
  fVar1 = (float)FUN_0003eb72(0,&DAT_ffff86ac);
  local_20 = FUN_00002490(fVar1 * fVar2,uVar3,uVar4);
  fVar1 = (float)FUN_0003eb72(uVar4,&DAT_ffff86bc);
  uStack_1e = FUN_00002490(fVar1 * fVar2,uVar3,uVar4);
  uStack_1c = 0xffff;
  FUN_000597ee(&DAT_ffff90ac,&local_20);
  return;
}


