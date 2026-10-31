/* ROM address: 0x000518c4; body bytes: 190; decompiled */

uint FUN_000518c4(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = rx8_absolute_difference((DAT_ffffadec + -1.0) * 100.0,DAT_ffffd0d8);
  fVar3 = rx8_absolute_difference(DAT_ffffd0ec,DAT_ffffd0e8);
  DAT_ffffd0fa = 0;
  if ((DAT_ffffd1c5 == '\x01') || (DAT_ffffd03b == '\x01')) {
    uVar1 = 1;
    DAT_ffffd0f4 = 0;
  }
  else {
    uVar1 = (uint)DAT_ffffd0f2;
    if (((uVar1 == 1) && (uVar1 = 0x88, DAT_ffffcfaa == 0x88)) && (DAT_ffffd0dc < DAT_ffffd0e0)) {
      if (fVar2 < 10.0098) {
        uVar1 = 0xffffffff;
      }
      if (fVar3 < 10.0098) {
        uVar1 = ref_getFaultStatus__(0x2d);
        uVar1 = uVar1 & 0xff;
        if (uVar1 == 0) {
          DAT_ffffd0f4 = 1;
          DAT_ffffd0fa = 1;
        }
      }
    }
  }
  return uVar1;
}


