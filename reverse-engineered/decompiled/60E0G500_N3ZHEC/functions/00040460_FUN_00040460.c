/* ROM address: 0x00040460; body bytes: 164; decompiled */

uint FUN_00040460(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  
  uVar4 = 0;
  fVar5 = DAT_ffffad98;
  fVar6 = DAT_ffffb0e4;
  fVar2 = (float)FUN_0003eb72(0,&DAT_ffff8748);
  fVar2 = fVar2 - 0.0003;
  fVar3 = (float)FUN_0003eb72(uVar4,&DAT_ffff8740);
  uVar1 = (uint)DAT_ffffc74e;
  if (uVar1 == 1) {
    uVar1 = (uint)DAT_ffffc748;
    if (uVar1 < 0x1f) {
      return uVar1;
    }
    if ((fVar6 < fVar2) && (fVar5 < 0.7)) {
      if (((fVar3 + 0.0003 < fVar6) && (((fVar2 <= fVar6 || (fVar5 <= 0.2)) || (0.7 <= fVar5)))) &&
         ((fVar3 + 0.0003 < fVar6 && (0.2 < fVar5)))) {
        return uVar1;
      }
      DAT_ffffc74f = 1;
      return uVar1;
    }
  }
  DAT_ffffc74f = 0;
  return uVar1;
}


