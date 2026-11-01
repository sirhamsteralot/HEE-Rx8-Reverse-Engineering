/* ROM address: 0x00034eb8; body bytes: 164; decompiled */

undefined4 FUN_00034eb8(void)

{
  undefined4 uVar1;
  undefined **ppuVar2;
  undefined4 extraout_fr0;
  undefined4 uVar3;
  float fVar4;
  
  fVar4 = DAT_ffffc1c8;
  DAT_ffffc1ac = (float)FUN_00002068(DAT_ffffc1c8,&DAT_0006b510);
  DAT_ffffc1b0 = (float)FUN_00002068(DAT_ffffc12c,&DAT_0006b4d4);
  uVar3 = 0;
  if (0.0 <= fVar4) {
    DAT_ffffc1a8 = DAT_ffffc1ac * 1.0 * DAT_ffffc1b0;
  }
  else {
    DAT_ffffc1a8 = 0.0;
  }
  if (DAT_ffffc1bc == '\x01') {
    DAT_ffffc184 = rx8_max_float(DAT_ffffc184 - 0.0078125,1.0);
  }
  if (DAT_ffffa42c == '\x01') {
    uVar1 = 1;
    DAT_ffffc1b4 = uVar3;
  }
  else {
    if (DAT_ffffc078 == '\x01') {
      ppuVar2 = (undefined **)&DAT_0006b568;
    }
    else {
      ppuVar2 = &PTR_DAT_0006b54c;
    }
    uVar1 = FUN_000020dc(DAT_ffffb5b8,DAT_ffffaa10,ppuVar2);
    DAT_ffffc1b4 = extraout_fr0;
  }
  return uVar1;
}


