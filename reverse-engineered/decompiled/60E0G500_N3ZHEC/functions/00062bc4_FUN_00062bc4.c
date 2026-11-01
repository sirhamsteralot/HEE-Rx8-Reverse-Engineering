/* ROM address: 0x00062bc4; body bytes: 198; decompiled */

undefined4 FUN_00062bc4(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  short local_18 [2];
  char cStack_14;
  
  local_18[0] = -1;
  uVar2 = 1;
  cStack_14 = param_1;
  if (DAT_ffff87ce._0_1_ == '\x02') {
    iVar3 = (int)DAT_ffff87c4;
    DAT_ffff87ce = FUN_00002420(1);
    cVar1 = FUN_000634d0(iVar3);
    if (cVar1 == '\0') {
      FUN_000042b0(&DAT_ffff87d8);
      FUN_00063552(iVar3);
    }
    else if (cVar1 == '\x01') {
      FUN_00063c5c(iVar3);
    }
    else {
      cVar1 = FUN_00063b3a(iVar3,(int)cStack_14,local_18);
      if (cVar1 == '\x02') {
        FUN_00063c5c(iVar3);
      }
      else {
        uVar2 = 0;
      }
    }
  }
  else if (DAT_ffff87ce._0_1_ == '\x01') {
    uVar2 = 0;
  }
  else {
    DAT_ffff87ce = FUN_00002420(1);
  }
  DAT_ffff87b8 = FUN_00002430((int)local_18[0]);
  return uVar2;
}


