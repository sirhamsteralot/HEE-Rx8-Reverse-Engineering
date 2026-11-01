/* ROM address: 0x00059260; body bytes: 92; decompiled */

void FUN_00059260(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined2 local_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  
  uVar3 = 0;
  uVar2 = 0x37ffda40;
  uVar1 = FUN_0003eb72(0,&DAT_ffff86d0);
  local_1c = FUN_00002490(uVar1,uVar2,uVar3);
  uVar1 = FUN_0003eb72(uVar3,&DAT_ffff86e0);
  uStack_1a = FUN_00002490(uVar1,uVar2,uVar3);
  uStack_18 = 0xffff;
  FUN_000597ee(&DAT_ffff90cc,&local_1c);
  return;
}


