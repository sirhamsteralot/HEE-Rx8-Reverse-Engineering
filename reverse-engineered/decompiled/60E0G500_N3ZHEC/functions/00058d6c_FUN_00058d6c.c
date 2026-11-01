/* ROM address: 0x00058d6c; body bytes: 108; decompiled */

void FUN_00058d6c(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 local_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  
  uVar4 = 0;
  uVar1 = FUN_000024c0(0x41000000,0,10);
  uVar2 = FUN_000024c0(0x42000000,uVar4,(int)DAT_ffffcd80);
  uVar3 = 0x3f800000;
  local_20 = FUN_00002490(uVar2,0x3f800000,uVar4);
  uStack_1e = 0;
  uStack_1c = FUN_00002490(uVar1,uVar3,uVar4);
  FUN_000597ee(&DAT_ffff908c,&local_20);
  return;
}


