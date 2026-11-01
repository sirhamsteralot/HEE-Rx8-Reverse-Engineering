/* ROM address: 0x00023118; body bytes: 188; decompiled */

uint FUN_00023118(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar3 = -52.5;
  fVar4 = DAT_ffffb600;
  fVar5 = DAT_ffffaa10;
  fVar2 = (float)FUN_0003eb72(DAT_ffff9f70,&DAT_ffff8088);
  DAT_ffffb3cc = fVar2 - DAT_ffffaa1c;
  DAT_ffffb3f6 = FUN_0000213c(DAT_ffffb3cc,DAT_ffffae58,&PTR_DAT_0006a8b0);
  if (fVar5 < -50.0) {
    if (fVar5 < fVar3) {
      DAT_ffffb3f8 = 0;
    }
  }
  else {
    DAT_ffffb3f8 = 1;
  }
  uVar1 = (uint)DAT_ffffa428;
  if ((((uVar1 != 1) || (uVar1 = (uint)DAT_ffffa424, uVar1 < (uint)(int)DAT_ffffb3f6)) ||
      (uVar1 = (uint)DAT_ffffb3f8, uVar1 != 1)) ||
     (((fVar4 < 9.0 || (16.0 <= fVar4)) || (uVar1 = (uint)DAT_ffffcdb0, uVar1 != 0)))) {
    DAT_ffffb3c8 = 0;
  }
  else {
    DAT_ffffb3c8 = 1;
  }
  return uVar1;
}


