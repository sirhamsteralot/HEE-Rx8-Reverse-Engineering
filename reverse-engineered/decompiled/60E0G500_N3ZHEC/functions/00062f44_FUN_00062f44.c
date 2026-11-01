/* ROM address: 0x00062f44; body bytes: 250; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00062f44(void)

{
  ushort uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  undefined4 uVar6;
  
  uVar1 = DAT_ffff87c4;
  cVar2 = DAT_ffff87cc._0_1_;
  cVar3 = DAT_ffff87ce._0_1_;
  cVar4 = DAT_ffff87d0._0_1_;
  cVar5 = DAT_ffff87d4._0_1_;
  _DAT_ffff87c0 = FUN_00002420(0);
  uVar6 = FUN_00003920(0x10);
  if (cVar2 == '\0') {
    DAT_ffff8e94 = FUN_00002420((int)DAT_ffff8e98._0_1_);
    *(ushort *)(&DAT_ffff8d7c + (uint)uVar1 * 2) =
         (ushort)DAT_ffff8e9a._0_1_ * 0x100 + (ushort)DAT_ffff8e9c._0_1_;
    DAT_ffff8e96 = FUN_00002420((int)DAT_ffff8e98._0_1_);
  }
  if (cVar3 == '\0') {
    _DAT_ffff8928 = FUN_00002430((int)DAT_ffff892c);
  }
  if (cVar4 == '\0') {
    _DAT_ffff8d74 = FUN_00002430((int)DAT_ffff8d78);
  }
  if (DAT_ffff87d2 == '\0') {
    FUN_00067d54();
  }
  if (cVar5 == '\0') {
    FUN_000682ba();
  }
  FUN_00003934(uVar6);
  _DAT_ffff87c0 = FUN_00002420(1);
  DAT_ffff87cc = FUN_00002420(2);
  DAT_ffff87ce = FUN_00002420(2);
  DAT_ffff87d0 = FUN_00002420(2);
  _DAT_ffff87d2 = FUN_00002420(2);
  DAT_ffff87d4 = FUN_00002420(2);
  return;
}


