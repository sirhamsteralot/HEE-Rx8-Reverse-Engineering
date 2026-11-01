/* ROM address: 0x000231d4; body bytes: 442; decompiled */

undefined4 FUN_000231d4(void)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  
  if (DAT_ffffaaf0 < 44.0) {
    if (DAT_ffffaaf0 < 39.0) {
      DAT_ffffb3f9 = '\0';
    }
  }
  else {
    DAT_ffffb3f9 = '\x01';
  }
  if (DAT_ffffaaf0 < 45.0) {
    if (DAT_ffffaaf0 < 40.0) {
      DAT_ffffb3fa = '\0';
    }
  }
  else {
    DAT_ffffb3fa = '\x01';
  }
  fVar3 = DAT_ffffaaf0;
  DAT_ffffb3e0 = (float)FUN_00002068(DAT_ffffaaf0,&PTR_LAB_0006a864);
  DAT_ffffb3e4 = (float)FUN_000020dc(DAT_ffffb5b8,DAT_ffffaad0,&PTR_DAT_0006a894);
  DAT_ffffb3e8 = (float)FUN_00002068(DAT_ffffb600,&PTR_LAB_0006a850);
  fVar1 = rx8_min_float(DAT_ffffb3e0,DAT_ffffb3e4);
  DAT_ffffb3d0 = DAT_ffffb3e8 * fVar1;
  if (DAT_ffffb3f9 == '\x01') {
    DAT_ffffb3d4 = DAT_ffffb3c4 - (fVar3 - 30.0) * 4.5;
  }
  else if ((0.0 < DAT_ffffb3c4) && (DAT_ffffb3c4 < DAT_ffffb3d0)) {
    DAT_ffffb3d4 = DAT_ffffb3d4 + (fVar3 - 30.0) * 0.1875;
  }
  if (DAT_ffffb3c8 == '\0') {
    DAT_ffffb3d8 = 0;
  }
  else {
    DAT_ffffb3d8 = FUN_00002460((int)DAT_ffffb3d8,1);
  }
  fVar1 = 0.0;
  uVar2 = FUN_000024c0(0x43000000,0,(int)DAT_ffffb3d8);
  DAT_ffffb3ec = (float)FUN_000020dc(uVar2,DAT_ffffae58,&LAB_0006a878);
  DAT_ffffb3f0 = (float)FUN_00002068(fVar3,&PTR_LAB_0006a83c);
  if (DAT_ffffb3c8 != '\0') {
    fVar1 = DAT_ffffb3ec;
    if ((DAT_ffffb3fa == '\x01') || (fVar1 = DAT_ffffb3f0, DAT_ffffb3f9 == '\x01')) {
      fVar1 = DAT_ffffb3e8 * fVar1;
    }
    else {
      fVar1 = (fVar3 - 30.0) * 4.5;
      if (DAT_ffffb3f4 < 0xea) {
        fVar1 = fVar1 + (DAT_ffffb3dc - fVar3) * 0.75;
      }
      fVar1 = rx8_min_float(fVar1 + DAT_ffffb3d4,DAT_ffffb3d0);
    }
  }
  DAT_ffffb3c4 = fVar1;
  if (DAT_ffffb3f9 == '\x01') {
    DAT_ffffb3f4 = 0;
    uVar2 = 1;
  }
  else {
    uVar2 = FUN_00002460((int)(short)DAT_ffffb3f4,1);
    DAT_ffffb3f4 = (ushort)uVar2;
  }
  DAT_ffffb3dc = fVar3;
  return uVar2;
}


