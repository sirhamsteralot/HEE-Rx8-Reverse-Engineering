/* ROM address: 0x0001f0f4; body bytes: 814; decompiled_with_warnings */

/* WARNING: Type propagation algorithm not settling */

uint FUN_0001f0f4(void)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  undefined2 uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined4 uVar11;
  float arg1;
  char local_3c;
  
  bVar1 = DAT_ffffb14a;
  cVar3 = DAT_ffffaada;
  uVar11 = 0;
  uVar5 = (uint)DAT_ffffb14c;
  puVar6 = (undefined *)(int)DAT_ffffb148;
  fVar9 = DAT_ffffae74;
  arg1 = DAT_ffffae68;
  fVar8 = (float)FUN_0003eb72(0,&DAT_ffff80ec + (uint)DAT_ffffb16e * 8);
  fVar8 = rx8_absolute_difference(DAT_ffffb140,fVar8);
  fVar9 = rx8_absolute_difference(DAT_ffffaae8,fVar9);
  fVar10 = rx8_absolute_difference(DAT_ffffae64,arg1);
  DAT_ffffb16c = FUN_000020c4(DAT_ffffb5b8,&DAT_0006a2c4);
  uVar4 = (uint)bVar1;
  if ((((uVar4 != 1) || (DAT_ffffb160 < DAT_ffffb16c)) || (0.02 <= fVar8)) || (0.02 <= fVar10)) {
    uVar5 = 0;
    puVar6 = (undefined *)0x8000;
    DAT_ffffb14f = '\0';
  }
  else {
    DAT_ffffb14f = '\x01';
  }
  if ((DAT_ffffb14f != '\x01') ||
     ((((cVar3 != '\x01' || (7 < (uVar5 & 0xffff))) || (0.05 <= fVar9)) &&
      ((cVar3 != '\0' || (7 < (uVar5 & 0xffff))))))) {
    sVar2 = 0;
    puVar6 = (undefined *)0x8000;
    DAT_ffffb150 = '\0';
  }
  else {
    DAT_ffffb150 = '\x01';
    sVar2 = FUN_00002460(uVar5,1);
  }
  if (DAT_ffffb150 == '\x01') {
    if (1.01 <= arg1) {
      puVar6 = (undefined *)FUN_00002460(puVar6,1);
    }
    if ((arg1 < 0.99) && (((uint)puVar6 & 0xffff) != 0)) {
      puVar6 = puVar6 + (int)(undefined *)0xffff;
    }
  }
  uVar7 = SUB42(puVar6,0);
  if ((DAT_ffffb14f == '\x01') &&
     (((cVar3 == '\0' && (sVar2 == 8)) || ((cVar3 == '\x01' && (sVar2 == 8)))))) {
    DAT_ffffb151 = '\x01';
  }
  else {
    DAT_ffffb151 = '\0';
  }
  if (DAT_ffffb151 == '\x01') {
    fVar9 = (float)FUN_0003eb72(uVar11,&DAT_ffff80ec + (uint)DAT_ffffb16e * 8);
    local_3c = FUN_0003eaa4(&DAT_ffff810c + (uint)DAT_ffffb16e * 2,0);
    if (cVar3 == '\0') {
      if (0x8007 < ((uint)puVar6 & 0xffff)) {
        puVar6 = (undefined *)0x8000;
        local_3c = '\x01';
        sVar2 = 0;
        fVar9 = fVar9 + 0.0009999999;
      }
      uVar7 = SUB42(puVar6,0);
      if (((uint)puVar6 & 0xffff) < 0x7ff9) {
        fVar9 = fVar9 - 0.0009999999;
        uVar7 = 0x8000;
        sVar2 = 0;
        local_3c = '\x01';
      }
    }
    else {
      if (0x8007 < ((uint)puVar6 & 0xffff)) {
        puVar6 = (undefined *)0x8000;
        local_3c = '\x01';
        sVar2 = 0;
        fVar9 = fVar9 + 0.0009999999;
      }
      uVar7 = SUB42(puVar6,0);
      if (((uint)puVar6 & 0xffff) < 0x7ff9) {
        fVar9 = fVar9 - 0.0009999999;
        uVar7 = 0x8000;
        sVar2 = 0;
        local_3c = '\x01';
      }
    }
    fVar9 = rx8_clamp_float(fVar9,-0.23,0.23);
    FUN_0003ec20(fVar9,&DAT_ffff80ec + (uint)DAT_ffffb16e * 8);
    FUN_0003ebc0(&DAT_ffff810c + (uint)DAT_ffffb16e * 2,(int)local_3c);
  }
  cVar3 = FUN_0003eaa4(&DAT_ffff810c,0);
  if (cVar3 == '\0') {
    FUN_0003ec20(uVar11,&DAT_ffff80ec);
  }
  cVar3 = FUN_0003eaa4(&DAT_ffff810e,0);
  if (cVar3 == '\0') {
    fVar9 = (float)FUN_0003eb72(uVar11,&DAT_ffff80ec);
    FUN_0003ec20(fVar9 * 1.0,&DAT_ffff80f4);
  }
  cVar3 = FUN_0003eaa4(&DAT_ffff8110,0);
  if (cVar3 == '\0') {
    fVar9 = (float)FUN_0003eb72(uVar11,&DAT_ffff80f4);
    FUN_0003ec20(fVar9 * 1.0,&DAT_ffff80fc);
  }
  cVar3 = FUN_0003eaa4(&DAT_ffff8112,0);
  if (cVar3 == '\0') {
    fVar9 = (float)FUN_0003eb72(uVar11,&DAT_ffff80fc);
    FUN_0003ec20(fVar9 * 1.0,&DAT_ffff8104);
  }
  if (uVar4 == 1) {
    uVar4 = FUN_00002460((int)(short)DAT_ffffb160,1);
    DAT_ffffb160 = (ushort)uVar4;
  }
  else {
    DAT_ffffb160 = 0;
  }
  DAT_ffffb14c = sVar2;
  DAT_ffffb148 = uVar7;
  return uVar4;
}


