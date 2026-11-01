/* ROM address: 0x0003fe4c; body bytes: 446; decompiled */

undefined1 * FUN_0003fe4c(void)

{
  float fVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined1 *puVar5;
  char cVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  uVar4 = DAT_ffffc73c;
  uVar3 = DAT_ffffc73a;
  uVar2 = DAT_ffffc738;
  fVar1 = DAT_ffffb5b8;
  fVar7 = DAT_ffffc734 - DAT_ffffc730;
  if (DAT_ffffd201 == '\x01') {
    puVar5 = &DAT_ffffc72a;
    DAT_ffffc72a = 0;
    DAT_ffffc72b = 0;
    DAT_ffffc728 = 0;
    DAT_ffffc729 = 0;
    DAT_ffffc72c = 0;
    DAT_ffffc72d = 0;
    DAT_ffffc742 = 0;
  }
  else {
    fVar8 = DAT_ffffae54;
    fVar9 = DAT_ffffaa10;
    fVar10 = DAT_ffffbc1c;
    fVar11 = DAT_ffffb3a4;
    if ((0x4e2 < DAT_ffffc738) || (DAT_ffffb3a4 <= 15000.0)) {
      cVar6 = FUN_000671a4(0x73);
      if ((((cVar6 == '\0') && (((fVar7 <= 0.2 && (0x4e2 < uVar2)) && (1500.0 < fVar1)))) &&
          (((0.0 < fVar10 && (70.0 < fVar9)) && (-40.0 < fVar8)))) && (15000.0 < fVar11)) {
        DAT_ffffc729 = 1;
      }
    }
    else {
      DAT_ffffc728 = 1;
    }
    if ((0x4e2 < uVar3) || (fVar11 <= 15000.0)) {
      cVar6 = FUN_000671a4(0x74);
      if ((((cVar6 == '\0') &&
           ((((fVar7 <= 0.2 && (0x4e2 < uVar3)) && (1500.0 < fVar1)) &&
            ((0.0 < fVar10 && (70.0 < fVar9)))))) && (-40.0 < fVar8)) && (15000.0 < fVar11)) {
        DAT_ffffc72b = 1;
      }
    }
    else {
      DAT_ffffc72a = 1;
    }
    puVar5 = (undefined1 *)(int)(short)uVar4;
    if (uVar4 == 0) {
      if (0xf < DAT_ffffc742) {
        DAT_ffffc72c = 1;
      }
      puVar5 = (undefined1 *)FUN_00002460((int)(short)DAT_ffffc742,1);
      DAT_ffffc742 = (ushort)puVar5;
    }
    else {
      if (0xf < uVar4) {
        DAT_ffffc72d = 1;
      }
      DAT_ffffc742 = 0;
    }
  }
  return puVar5;
}


