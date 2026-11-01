/* ROM address: 0x00035044; body bytes: 118; decompiled */

undefined4 FUN_00035044(void)

{
  undefined4 uVar1;
  undefined **ppuVar2;
  undefined4 extraout_fr0;
  float fVar3;
  
  fVar3 = DAT_ffffc1cc;
  DAT_ffffc19c = (float)FUN_00002068(DAT_ffffc1cc,&DAT_0006b524);
  DAT_ffffc1a0 = 0x3f800000;
  if (0.0 <= fVar3) {
    DAT_ffffc198 = DAT_ffffc19c * 1.0 * 1.0;
  }
  else {
    DAT_ffffc198 = 0.0;
  }
  if (DAT_ffffa42c == '\x01') {
    DAT_ffffc1a4 = 0;
    uVar1 = 1;
  }
  else {
    if (DAT_ffffc078 == '\x01') {
      ppuVar2 = (undefined **)&DAT_0006b5a0;
    }
    else {
      ppuVar2 = &PTR_DAT_0006b584;
    }
    uVar1 = FUN_000020dc(DAT_ffffb5b8,DAT_ffffaa10,ppuVar2);
    DAT_ffffc1a4 = extraout_fr0;
  }
  return uVar1;
}


