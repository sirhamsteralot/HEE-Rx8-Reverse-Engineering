/* ROM address: 0x000524fc; body bytes: 188; decompiled */

uint FUN_000524fc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  byte bVar3;
  
  uVar1 = (uint)DAT_ffffcff1;
  bVar3 = -(((uVar1 & 0x80) == 0) + -1);
  if ((DAT_ffffd166 == '\0') && (uVar1 = (uint)bVar3, uVar1 == 1)) {
    uVar2 = FUN_00003920(0x10);
    DAT_ffffd148 = 0;
    FUN_00003934(uVar2);
    DAT_ffffd14a = 0;
    DAT_ffffd14b = 0;
    DAT_ffffd14c = 0;
    DAT_ffffd14d = 0;
    DAT_ffffd14e = 0;
    DAT_ffffd14f = 0;
    DAT_ffffd150 = 0;
    DAT_ffffd151 = 0;
    DAT_ffffd152 = 0;
    DAT_ffffd153 = 0;
    DAT_ffffd154 = 0;
    DAT_ffffd155 = 0;
    DAT_ffffd156 = 0;
    FUN_0003ebc0(&DAT_ffff86f0,0,param_3,param_4,uVar2);
    FUN_0003ebc0(&DAT_ffff86f2,0);
    FUN_0003ebc0(&DAT_ffff86f4,0);
    FUN_0003ebc0(&DAT_ffff86f6,0);
    FUN_0003ebc0(&DAT_ffff86f8,0);
    FUN_0003ebc0(&DAT_ffff86fa,0);
    FUN_0003ebc0(&DAT_ffff86fc,0);
    FUN_0003ebc0(&DAT_ffff86fe,0);
    FUN_0003ebc0(&DAT_ffff8700,0);
    uVar1 = FUN_0003ebc0(&DAT_ffff8702,0);
  }
  DAT_ffffd166 = bVar3;
  return uVar1;
}


