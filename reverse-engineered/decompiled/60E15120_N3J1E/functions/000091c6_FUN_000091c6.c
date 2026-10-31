/* ROM address: 0x000091c6; body bytes: 500; decompiled */

undefined4 * FUN_000091c6(uint param_1)

{
  short sVar1;
  short sVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  short sVar8;
  uint uVar9;
  short sVar10;
  undefined4 local_18 [2];
  
  iVar5 = (param_1 & 0xff) * 8;
  DAT_ffffa0f8 = *(float *)(&DAT_ffffa0d8 + iVar5) - DAT_ffffa0fc;
  if (-90.0 <= DAT_ffffa0f8) {
    if (630.0 <= DAT_ffffa0f8) {
      DAT_ffffa0f8 = DAT_ffffa0f8 + -720.0;
    }
  }
  else {
    DAT_ffffa0f8 = DAT_ffffa0f8 + 720.0;
  }
  if ((&DAT_ffffa0dd)[iVar5] == '\0') {
    if (60.0 <= DAT_ffffa0f8 -
                ((float)(int)((&DAT_ffffa0c4)[param_1 & 0xff] + (uint)DAT_ffffa0d4 * 0x10) * 30.0) /
                (float)DAT_ffffa100) {
      return &DAT_000092e0;
    }
    FUN_00009440(param_1,&PTR_DAT_00003e80);
  }
  else if (*(short *)(&PTR_ATUII_DCNT8I_W_0000d81c)[(param_1 & 0xff) * 6] == 0) {
    iVar5 = (param_1 & 0xff) * 8;
    (&DAT_ffffa0dc)[iVar5] = 0;
    (&DAT_ffffa0dd)[iVar5] = 0;
    return (undefined4 *)0x0;
  }
  iVar5 = (int)(((float)DAT_ffffa100 * DAT_ffffa0f8) / 480.0) -
          ((int)(&DAT_ffffa0c4)[param_1 & 0xff] >> 4);
  uVar9 = DAT_ffffa104 + iVar5;
  sVar2 = (short)uVar9;
  sVar8 = sVar2 - DAT_ffffa0d4;
  ref_setSR_PARAM(local_18,0xe0);
  uVar4 = param_1 & 0xff;
  sVar10 = *(short *)(&PTR_ATUII_TCNT2B_W_0000d828)[uVar4 * 6];
  sVar1 = (short)((int)sVar10 + 3U);
  if (-1 < (short)(*(short *)(&PTR_ATUII_OCR2A_W_0000d820)[uVar4 * 6] - sVar1)) {
    if ((short)(sVar8 - sVar1) < 0) {
      sVar8 = sVar1;
    }
    *(short *)(&PTR_ATUII_OCR2A_W_0000d820)[uVar4 * 6] = sVar8;
  }
  iVar6 = (param_1 & 0xff) * 8;
  if (iVar5 - (DAT_ffffa100 >> 4) < 0x7d) {
    uVar7 = (int)((float)DAT_ffffa0d4 * 0.5) +
            (int)(short)*(ushort *)(&PTR_ATUII_OCR2A_W_0000d820)[uVar4 * 6];
    if ((short)(sVar2 - (short)uVar7) < 0) {
      uVar9 = uVar7;
    }
    if ((short)((short)uVar9 - sVar1) < 0) {
      uVar9 = (int)sVar10 + 3U;
    }
    sVar10 = (short)uVar9;
    if ((uVar9 & 0xffff) == (uint)*(ushort *)(&PTR_ATUII_OCR2A_W_0000d820)[uVar4 * 6]) {
      sVar10 = sVar10 + 1;
    }
    (&DAT_ffffa0de)[iVar6] = 1;
    *(short *)(&PTR_ATUII_GR2A_W_0000d824)[uVar4 * 6] = sVar10;
  }
  else if ((&DAT_ffffa0de)[iVar6] == '\0') {
    *(short *)(&PTR_ATUII_GR2A_W_0000d824)[uVar4 * 6] =
         *(short *)(&PTR_ATUII_TCNT2B_W_0000d828)[uVar4 * 6] + -1;
  }
  puVar3 = (undefined4 *)FUN_00002064(local_18[0]);
  return puVar3;
}


