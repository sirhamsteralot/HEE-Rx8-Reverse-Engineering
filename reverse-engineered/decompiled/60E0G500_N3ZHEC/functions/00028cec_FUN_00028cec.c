/* ROM address: 0x00028cec; body bytes: 440; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00028cec(void)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  float fVar9;
  undefined4 uVar10;
  float fVar11;
  float fVar12;
  float local_3c;
  float local_38;
  short sStack_34;
  
  uVar1 = DAT_ffffb734;
  uVar10 = 0;
  iVar8 = (int)(short)DAT_ffffb734;
  uVar2 = (int)DAT_ffffb6d0 & 1;
  iVar6 = uVar2 * 4;
  fVar11 = DAT_ffffb6d8;
  if ((DAT_ffffb5b8 < 820.0) || (9000.0 <= DAT_ffffb5b8)) {
    if (uVar2 == 0) {
      _DAT_ffffbacc = FUN_0003eb72(0,&DAT_ffff8130 + (uint)DAT_ffffb734 * 8);
    }
    else {
      uVar10 = FUN_0003eb72(0,&DAT_ffff8350 + (uint)DAT_ffffb734 * 8);
      *(undefined4 *)(&DAT_ffffbacc + iVar6) = uVar10;
    }
  }
  else {
    uVar7 = 0;
    sStack_34 = DAT_ffffb734 - 1;
    fVar12 = DAT_ffffb5b8;
    do {
      uVar3 = FUN_00002478(uVar7,1);
      iVar5 = iVar8;
      if (((float)(&DAT_00075ae0)[uVar7 & 0xff] <= fVar12) &&
         (fVar12 < *(float *)(&DAT_00075a34 + (uVar3 & 0xff) * 4))) {
        if (uVar1 < 0x43) {
          iVar8 = FUN_00002460(iVar8,1);
        }
LAB_00028df4:
        FUN_00028fd8(uVar2,iVar5,iVar8,&local_3c,&local_38);
        break;
      }
      if ((*(float *)(&DAT_00075a34 + (uVar3 & 0xff) * 4) <= fVar12) &&
         (fVar12 < (float)(&DAT_00075ae0)[uVar3 & 0xff])) {
        if (uVar1 != 0) {
          iVar5 = (int)sStack_34;
        }
        goto LAB_00028df4;
      }
      uVar7 = uVar7 + 1;
    } while ((uVar7 & 0xff) < 0x10);
    fVar9 = (float)(&DAT_00075ae0)[uVar3 & 0xff] - (float)(&DAT_00075ae0)[uVar7 & 0xff];
    cVar4 = FUN_00002440(fVar9,uVar10,0x3727c5ac);
    if (cVar4 != '\0') {
      local_3c = local_3c +
                 ((fVar12 - (float)(&DAT_00075ae0)[uVar7 & 0xff]) / fVar9) * (local_38 - local_3c);
    }
    *(float *)(&DAT_ffffbacc + iVar6) = local_3c;
  }
  DAT_ffffbab0 = DAT_ffffbaac;
  DAT_ffffbaac = DAT_ffffbaa8;
  DAT_ffffba94 = (fVar11 - (DAT_ffffb6f0 - fVar11) / 6.0) - DAT_ffffb6d4;
  DAT_ffffba98 = DAT_ffffba94 - *(float *)(&DAT_ffffbacc + iVar6);
  return;
}


