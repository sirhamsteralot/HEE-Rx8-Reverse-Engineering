/* ROM address: 0x00034d20; body bytes: 116; decompiled */

undefined4 FUN_00034d20(void)

{
  undefined4 uVar1;
  float extraout_fr0;
  float fVar2;
  float fVar3;
  
  fVar3 = DAT_ffffc1d4;
  DAT_ffffc16c = (float)FUN_00002068(DAT_ffffc1d4,&DAT_0006b46c);
  fVar2 = 0.0;
  DAT_ffffc170 = (float)FUN_00002500(0x3d4ccccc,0,0x14);
  DAT_ffffc168 = fVar2;
  if (fVar3 < 0.0) {
    DAT_ffffc168 = DAT_ffffc16c * 0.0 * DAT_ffffc170;
  }
  if (DAT_ffffa42c == '\x01') {
    uVar1 = 1;
    DAT_ffffc174 = fVar2;
  }
  else {
    uVar1 = FUN_000020dc(DAT_ffffb5b8,DAT_ffffaa10,&DAT_0006b4b8);
    DAT_ffffc174 = extraout_fr0;
  }
  return uVar1;
}


