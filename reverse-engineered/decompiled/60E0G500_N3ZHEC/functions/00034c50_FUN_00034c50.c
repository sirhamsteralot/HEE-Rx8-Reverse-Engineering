/* ROM address: 0x00034c50; body bytes: 116; decompiled */

undefined4 FUN_00034c50(void)

{
  undefined4 uVar1;
  float extraout_fr0;
  float fVar2;
  float fVar3;
  
  fVar3 = DAT_ffffc1cc;
  DAT_ffffc15c = (float)FUN_00002068(DAT_ffffc1cc,&DAT_0006b458);
  fVar2 = 0.0;
  DAT_ffffc160 = (float)FUN_00002500(0x3d4ccccc,0,0x14);
  DAT_ffffc158 = fVar2;
  if (fVar3 < 0.0) {
    DAT_ffffc158 = DAT_ffffc15c * 1.0 * DAT_ffffc160;
  }
  if (DAT_ffffa42c == '\x01') {
    uVar1 = 1;
    DAT_ffffc164 = fVar2;
  }
  else {
    uVar1 = FUN_000020dc(DAT_ffffb5b8,DAT_ffffaa10,&DAT_0006b49c);
    DAT_ffffc164 = extraout_fr0;
  }
  return uVar1;
}


