/* ROM address: 0x0000ffd6; body bytes: 358; decompiled */

int FUN_0000ffd6(char *param_1)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  ushort uVar4;
  float fVar5;
  float fVar6;
  
  fVar6 = 0.25;
  iVar3 = (int)*param_1;
  if (iVar3 == 0) {
    uVar1 = *(ushort *)(param_1 + 4);
    uVar4 = FUN_0000f344();
    if ((uVar4 & 0xff) < uVar1) {
      fVar5 = DAT_ffffbec4 / fVar6;
      *(int *)(param_1 + 0x18) = (int)fVar5;
      if ((int)fVar5 < 1) {
        param_1[0x24] = '\x01';
      }
      else {
        param_1[0x24] = '\0';
      }
      iVar3 = (int)(DAT_ffffbec8 / fVar6);
      *(int *)(param_1 + 0x30) = iVar3;
      if (iVar3 < 1) {
        param_1[0x3c] = '\x01';
      }
      else {
        param_1[0x3c] = '\0';
      }
      *(int *)(param_1 + 0x48) = iVar3;
      if (0 < iVar3) {
        param_1[0x54] = '\0';
        return 0x54;
      }
    }
    else {
      iVar3 = (int)(300.0 / fVar6);
      fVar5 = DAT_ffffbec4 / fVar6;
      *(int *)(param_1 + 0x18) = iVar3;
      if ((iVar3 < 1) || ((int)fVar5 == 0)) {
        param_1[0x24] = '\x01';
      }
      else {
        param_1[0x24] = '\0';
      }
      bVar2 = (int)(DAT_ffffbec8 / fVar6) != 0;
      *(int *)(param_1 + 0x30) = iVar3;
      if ((iVar3 < 1) || (!bVar2)) {
        param_1[0x3c] = '\x01';
      }
      else {
        param_1[0x3c] = '\0';
      }
      *(int *)(param_1 + 0x48) = iVar3;
      if ((0 < iVar3) && (bVar2)) {
        param_1[0x54] = '\0';
        return 0x54;
      }
    }
  }
  else {
    if (iVar3 != 1) {
      return iVar3;
    }
    fVar6 = DAT_ffffbeb8 / 0.25;
    *(int *)(param_1 + 0x18) = (int)fVar6;
    if ((int)fVar6 < 1) {
      param_1[0x24] = '\x01';
    }
    else {
      param_1[0x24] = '\0';
    }
    fVar6 = DAT_ffffbebc / 0.25;
    *(int *)(param_1 + 0x30) = (int)fVar6;
    if ((int)fVar6 < 1) {
      param_1[0x3c] = '\x01';
    }
    else {
      param_1[0x3c] = '\0';
    }
    fVar6 = DAT_ffffbec0 / 0.25;
    *(int *)(param_1 + 0x48) = (int)fVar6;
    if (0 < (int)fVar6) {
      param_1[0x54] = '\0';
      return 0x54;
    }
  }
  param_1[0x54] = '\x01';
  return 0x54;
}


