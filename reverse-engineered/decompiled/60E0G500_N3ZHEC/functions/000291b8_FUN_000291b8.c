/* ROM address: 0x000291b8; body bytes: 218; decompiled */

uint FUN_000291b8(void)

{
  uint uVar1;
  float *pfVar2;
  float fVar3;
  float extraout_fr0;
  float extraout_fr0_00;
  float fVar4;
  
  DAT_ffffbae8 = DAT_ffffbae4;
  fVar3 = (float)FUN_000020dc(DAT_ffffc12c,DAT_ffffb5b8,&DAT_0006ab80);
  fVar4 = 0.0;
  if (DAT_ffffbac8 != '\0') {
    if (DAT_ffffb5aa == '\x01') {
      uVar1 = FUN_00002068(DAT_ffffaa10,&DAT_0006ab50);
      DAT_ffffbaf8 = extraout_fr0;
    }
    else {
      uVar1 = FUN_00002500(0x3c000000,0,0xffffff80);
      DAT_ffffbaf8 = extraout_fr0_00;
    }
    DAT_ffffbae4 = DAT_ffffbaf8 * fVar3;
    return uVar1;
  }
  if (DAT_ffffb5aa == '\x01') {
    DAT_ffffbaf4 = (float)FUN_00002068(&DAT_0006ab50);
  }
  else {
    DAT_ffffbaf4 = (float)FUN_00002500(0x3c000000,0);
  }
  if (DAT_ffffa6b7 == '\x01') {
    pfVar2 = (float *)&DAT_00075588;
  }
  else {
    if (DAT_ffffa6b8 != '\x01') {
      uVar1 = (uint)DAT_ffffa6b9;
      DAT_ffffbb00 = fVar4;
      if (uVar1 == 1) {
        DAT_ffffbb00 = 0.0;
      }
      goto LAB_00029254;
    }
    pfVar2 = (float *)&DAT_0007558c;
  }
  uVar1 = 1;
  DAT_ffffbb00 = *pfVar2;
LAB_00029254:
  DAT_ffffbae4 = DAT_ffffbb00 + DAT_ffffbaf4 * fVar3;
  return uVar1;
}


