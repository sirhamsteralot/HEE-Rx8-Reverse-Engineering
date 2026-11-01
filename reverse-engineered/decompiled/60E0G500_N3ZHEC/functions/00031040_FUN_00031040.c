/* ROM address: 0x00031040; body bytes: 460; decompiled */

uint FUN_00031040(void)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  uint extraout_r0;
  uint uVar4;
  byte bVar5;
  float fVar6;
  float fVar7;
  
  cVar2 = DAT_ffffce6e;
  bVar1 = DAT_ffffa42c;
  uVar4 = (uint)(char)DAT_ffffbf06;
  fVar7 = DAT_ffffaa10;
  if (6 < DAT_ffffbf11) {
    uVar4 = FUN_00002478(uVar4,1);
    DAT_ffffbf11 = 0;
    DAT_ffffbf16 = 0;
  }
  bVar5 = (byte)uVar4;
  if (((-20.0 <= fVar7) || (5 < (uVar4 & 0xff))) || (DAT_ffffa7bc <= DAT_ffffb5b8)) {
    bVar5 = 0;
    DAT_ffffbf11 = 0;
    DAT_ffffbf16 = 0;
  }
  if ((DAT_ffffbf15 == '\0') && (bVar1 == 1)) {
    DAT_ffffbf11 = 0;
    DAT_ffffbf16 = 1;
  }
  uVar4 = (uint)DAT_ffffbf16;
  if (uVar4 == 1) {
    uVar4 = FUN_00002478((int)(char)DAT_ffffbf11,1);
    DAT_ffffbf11 = (byte)uVar4;
  }
  fVar6 = 1.0;
  DAT_ffffbf06 = bVar5;
  if (DAT_ffffa428 == '\0') {
    if ((DAT_ffffbf15 == '\0') && (bVar1 == 1)) {
      if (cVar2 == '\x01') {
        uVar3 = FUN_000020c4(fVar7,&PTR_LAB_0006aa88);
        DAT_ffffbf0c = uVar3 >> 4;
        DAT_ffffbf04 = FUN_00002460(DAT_ffffbf0c,0xea);
        DAT_ffffbefc = 0.5;
      }
      else {
        if (bVar5 < 200) {
          uVar3 = FUN_000020ac(fVar7,&PTR_LAB_0006afc0);
          DAT_ffffbf04 = uVar3 & 0xff;
        }
        else {
          DAT_ffffbf04 = 8;
        }
        if (DAT_ffffbf06 < 200) {
          DAT_ffffbefc = 0.0;
        }
        else {
          DAT_ffffbefc = 0.34375;
        }
      }
    }
    if (((cVar2 == '\x01') && (1e+07 <= DAT_ffffbf00)) ||
       ((bVar1 == 1 && (DAT_ffffbf04 <= DAT_ffffbf0e)))) {
      DAT_ffffbf07 = '\x01';
    }
    else {
      DAT_ffffbf07 = '\0';
    }
    uVar4 = (uint)bVar1;
    if (uVar4 == 1) {
      uVar4 = FUN_00002460((int)(short)DAT_ffffbf0e,1);
      DAT_ffffbf0e = (ushort)uVar4;
    }
    else {
      DAT_ffffbf0e = 0;
    }
    if (DAT_ffffbf07 != '\0') {
      fVar6 = rx8_max_float(DAT_ffffbef0 + -0.046899997,DAT_ffffbefc);
      uVar4 = extraout_r0;
    }
  }
  else {
    DAT_ffffbef0 = 1.0;
    DAT_ffffbf07 = '\0';
    DAT_ffffbf0e = 0;
    fVar6 = DAT_ffffbef0;
  }
  DAT_ffffbef0 = fVar6;
  DAT_ffffbf15 = bVar1;
  return uVar4;
}


