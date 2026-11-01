/* ROM address: 0x00029090; body bytes: 220; decompiled */

uint FUN_00029090(void)

{
  uint uVar1;
  float *pfVar2;
  float fVar3;
  float extraout_fr0;
  float fVar4;
  
  DAT_ffffbae0 = DAT_ffffbadc;
  fVar3 = (float)FUN_000020dc(DAT_ffffc12c,DAT_ffffb5b8,&DAT_0006ab64);
  fVar4 = 0.0;
  if (DAT_ffffbac8 != '\0') {
    uVar1 = FUN_00002500(0x3c000000,0,0xffffff80);
    DAT_ffffbadc = extraout_fr0 * fVar3;
    DAT_ffffbaf0 = extraout_fr0;
    return uVar1;
  }
  DAT_ffffbaec = (float)FUN_00002500(0x3c000000,0,0xffffff80);
  if (DAT_ffffa6b7 == '\x01') {
    pfVar2 = (float *)&DAT_0007557c;
  }
  else {
    if (DAT_ffffa6b8 != '\x01') {
      uVar1 = (uint)DAT_ffffa6b9;
      DAT_ffffbafc = fVar4;
      if (uVar1 == 1) {
        DAT_ffffbafc = 0.0;
      }
      goto LAB_0002912e;
    }
    pfVar2 = (float *)&DAT_00075580;
  }
  uVar1 = 1;
  DAT_ffffbafc = *pfVar2;
LAB_0002912e:
  DAT_ffffbadc = DAT_ffffbafc + DAT_ffffbaec * fVar3;
  return uVar1;
}


