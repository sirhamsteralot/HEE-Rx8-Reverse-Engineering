/* ROM address: 0x00062d14; body bytes: 248; decompiled */

undefined4 FUN_00062d14(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  short local_24 [2];
  char cStack_20;
  
  uVar2 = 1;
  local_24[0] = -1;
  cStack_20 = param_1;
  if (DAT_ffff87d0._0_1_ == '\x02') {
    iVar3 = (int)DAT_ffff87c4;
    DAT_ffff87d0 = FUN_00002420(1);
    cVar1 = FUN_00063e24(iVar3);
    if (cVar1 == '\0') {
      FUN_000042b0();
    }
    else if (cVar1 == '\x01') {
      iVar4 = (uint)DAT_ffff8d74 * 0x34;
      (&DAT_ffff8962)[iVar4] = (&DAT_ffff8962)[iVar4] + (&DAT_ffff8937)[iVar4];
      (&DAT_ffff8937)[iVar4] = 0;
    }
    else {
      cVar1 = FUN_00063eaa(iVar3,(int)cStack_20,local_24);
      if (cVar1 != '\x02') {
        uVar2 = 0;
        goto LAB_00062dee;
      }
      iVar4 = (uint)DAT_ffff8d74 * 0x34;
      (&DAT_ffff8962)[iVar4] = (&DAT_ffff8962)[iVar4] + (&DAT_ffff8937)[iVar4];
      (&DAT_ffff8937)[iVar4] = 0;
    }
    FUN_00064006(iVar3);
  }
  else if (DAT_ffff87d0._0_1_ == '\x01') {
    uVar2 = 0;
  }
  else {
    DAT_ffff87d0 = FUN_00002420(1);
  }
LAB_00062dee:
  DAT_ffff87bc = FUN_00002430((int)local_24[0]);
  return uVar2;
}


