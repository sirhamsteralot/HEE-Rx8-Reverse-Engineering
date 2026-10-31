/* ROM address: 0x00067faa; body bytes: 208; decompiled */

uint FUN_00067faa(uint *param_1)

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
  uVar1 = FUN_00068ae8(uVar6);
  if ((char)uVar1 != -1) {
    uVar5 = (undefined2)uVar4;
    if ((DAT_ffffddf5 & 0x10) == 0) {
      if ((char)uVar2 == '\0') {
        DAT_ffffddf5 = DAT_ffffddf5 & 0xbf | 0x10;
        FUN_00068398();
        FUN_00068b46(uVar1);
        uVar4 = uVar4 & 0xffff;
        DAT_ffffdddc = uVar5;
        if (0xfff < uVar4) {
          DAT_ffffdddc = 0xfff;
        }
        DAT_ffffddf6 = 0;
        if (uVar4 < 8) {
          uVar3 = 0;
        }
        else {
          uVar3 = 0x10;
        }
        DAT_ffffdde0 = (char)uVar6;
        DAT_ffffdde2 = (char)uVar1;
        FUN_00068776(uVar3);
        thunk_FUN_00054a00((int)DAT_ffffdde0);
      }
      else {
        FUN_00068b98(uVar1);
        DAT_ffffddf5 = DAT_ffffddf5 & 0xbf;
      }
      FUN_00068c58(1);
      uVar1 = FUN_00068c58(0);
      return uVar1;
    }
    uVar1 = (uint)DAT_ffffddf6;
    if (DAT_ffffddf6 == 1) {
      DAT_ffffddf7 = 1;
      uVar1 = uVar6;
      DAT_ffffddd8 = uVar5;
      DAT_ffffddda = (char)uVar6;
    }
  }
  return uVar1;
}


