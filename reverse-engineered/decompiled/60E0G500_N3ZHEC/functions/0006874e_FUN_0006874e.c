/* ROM address: 0x0006874e; body bytes: 208; decompiled */

uint FUN_0006874e(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined2 uVar5;
  uint uVar6;
  
  uVar6 = *param_1;
  uVar4 = param_1[1];
  uVar2 = param_1[3];
  uVar1 = FUN_0006928c(uVar6);
  if ((char)uVar1 != -1) {
    uVar5 = (undefined2)uVar4;
    if ((DAT_ffffde31 & 0x10) == 0) {
      if ((char)uVar2 == '\0') {
        DAT_ffffde31 = DAT_ffffde31 & 0xbf | 0x10;
        FUN_00068b3c();
        FUN_000692ea(uVar1);
        uVar4 = uVar4 & 0xffff;
        DAT_ffffde18 = uVar5;
        if (0xfff < uVar4) {
          DAT_ffffde18 = 0xfff;
        }
        DAT_ffffde32 = 0;
        if (uVar4 < 8) {
          uVar3 = 0;
        }
        else {
          uVar3 = 0x10;
        }
        DAT_ffffde1c = (char)uVar6;
        DAT_ffffde1e = (char)uVar1;
        FUN_00068f1a(uVar3);
        thunk_FUN_000551a4((int)DAT_ffffde1c);
      }
      else {
        FUN_0006933c(uVar1);
        DAT_ffffde31 = DAT_ffffde31 & 0xbf;
      }
      FUN_000693fc(1);
      uVar1 = FUN_000693fc(0);
      return uVar1;
    }
    uVar1 = (uint)DAT_ffffde32;
    if (DAT_ffffde32 == 1) {
      DAT_ffffde33 = 1;
      uVar1 = uVar6;
      DAT_ffffde14 = uVar5;
      DAT_ffffde16 = (char)uVar6;
    }
  }
  return uVar1;
}


