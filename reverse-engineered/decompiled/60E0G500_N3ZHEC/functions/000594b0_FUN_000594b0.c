/* ROM address: 0x000594b0; body bytes: 106; decompiled */

void FUN_000594b0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 local_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  
  uVar4 = 0;
  uVar3 = 0x3f800000;
  uVar2 = 0x43000000;
  uVar1 = FUN_00002500(0x43000000,0,(int)DAT_ffffc5af);
  local_20 = FUN_00002490(uVar1,uVar3,uVar4);
  uStack_1e = 0;
  uVar1 = FUN_00002500(uVar2,uVar4,0x27);
  uStack_1c = FUN_00002490(uVar1,uVar3,uVar4);
  FUN_000597ee(&DAT_ffff90ec,&local_20);
  return;
}


