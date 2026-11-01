/* ROM address: 0x00032ce8; body bytes: 190; decompiled */

uint FUN_00032ce8(void)

{
  uint uVar1;
  uint uVar2;
  float fVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  
  uVar4 = 0;
  fVar5 = DAT_ffffc008;
  fVar3 = (float)FUN_0003eb72(0,&DAT_ffff8694);
  fVar6 = fVar5 - fVar3;
  fVar5 = fVar3 - fVar5;
  uVar1 = FUN_00002440(fVar3,uVar4,0x3727c5ac);
  uVar2 = uVar1;
  if ((DAT_ffffbd58 == '\0') ||
     ((uVar2 = (uint)DAT_ffffc01d, uVar2 == 1 &&
      ((((0.0 <= fVar6 && (fVar6 <= 1.6)) || ((0.0 <= fVar5 && (fVar5 <= 0.5)))) ||
       ((uVar2 = 1, DAT_ffffc022 == '\x01' || (uVar2 = (uint)DAT_ffffc021, uVar2 == 1)))))))) {
    DAT_ffffc01d = 0;
  }
  else if ((DAT_ffffbd59 == '\0') &&
          (((uVar2 = (uint)(char)DAT_ffffc033, uVar2 == 0 &&
            (uVar2 = (uint)DAT_ffffbca2, uVar2 == 1)) && ((uVar1 & 0xff) != 0)))) {
    DAT_ffffc01d = 1;
  }
  DAT_ffffc033 = DAT_ffffbca2;
  return uVar2;
}


