/* ROM address: 0x0002efd0; body bytes: 310; decompiled */

uint FUN_0002efd0(void)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  cVar2 = DAT_ffffc021;
  bVar1 = DAT_ffffc01d;
  fVar6 = DAT_ffffc00c;
  fVar7 = DAT_ffffbd38;
  fVar8 = DAT_ffffc008;
  fVar4 = (float)FUN_0003eb72(0,&DAT_ffff8694);
  fVar5 = DAT_ffffc014 - 0.5;
  if ((((DAT_ffffbd59 == '\0') || (DAT_ffffbd64 < DAT_ffffaa38)) ||
      ((cVar2 == '\0' && (bVar1 == 0)))) ||
     ((bVar1 == 1 &&
      (((0.0 <= fVar8 - fVar4 && (fVar8 - fVar4 <= 1.6)) ||
       ((0.0 <= fVar4 - fVar8 && (fVar4 - fVar8 <= 0.5)))))))) {
    DAT_ffffbdcc = 0;
  }
  else if ((((cVar2 == '\x01') || (bVar1 == 1)) && (0x7c < DAT_ffffbdce)) &&
          ((((fVar7 < 2.0 && (fVar8 < fVar6)) && (fVar8 < fVar5)) && (0x18 < DAT_ffffbdd0)))) {
    DAT_ffffbdcc = 1;
  }
  if ((cVar2 == '\x01') || (uVar3 = (uint)bVar1, uVar3 == 1)) {
    uVar3 = FUN_00002460((int)(short)DAT_ffffbdce,1);
    DAT_ffffbdce = (ushort)uVar3;
  }
  else {
    DAT_ffffbdce = 0;
  }
  if (((2.0 <= fVar7) || (fVar6 <= fVar8)) || (fVar5 <= fVar8)) {
    DAT_ffffbdd0 = 0;
  }
  else {
    uVar3 = FUN_00002460((int)(short)DAT_ffffbdd0,1);
    DAT_ffffbdd0 = (ushort)uVar3;
  }
  return uVar3;
}


