/* ROM address: 0x00035116; body bytes: 126; decompiled */

uint FUN_00035116(void)

{
  uint uVar1;
  float extraout_fr0;
  float fVar2;
  float fVar3;
  
  fVar3 = DAT_ffffc1d4;
  DAT_ffffc18c = (float)FUN_00002068(DAT_ffffc1d4,&DAT_0006b538);
  fVar2 = 0.0;
  DAT_ffffc190 = (float)FUN_00002500(0x3d4ccccc,0,0x14);
  DAT_ffffc188 = fVar2;
  if (0.0 <= fVar3) {
    DAT_ffffc188 = DAT_ffffc18c * 1.0 * DAT_ffffc190;
  }
  uVar1 = (uint)DAT_ffffa42c;
  if ((uVar1 != 1) && (DAT_ffffc078 != '\0')) {
    uVar1 = FUN_000020dc(DAT_ffffb5b8,DAT_ffffaa10,&DAT_0006b5bc);
    fVar2 = extraout_fr0;
  }
  DAT_ffffc194 = fVar2;
  return uVar1;
}


