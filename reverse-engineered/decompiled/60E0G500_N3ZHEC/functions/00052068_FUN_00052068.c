/* ROM address: 0x00052068; body bytes: 190; decompiled */

uint FUN_00052068(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = rx8_absolute_difference((DAT_ffffae64 + -1.0) * 100.0,DAT_ffffd114);
  fVar3 = rx8_absolute_difference(DAT_ffffd128,DAT_ffffd124);
  DAT_ffffd136 = 0;
  if ((DAT_ffffd201 == '\x01') || (DAT_ffffd077 == '\x01')) {
    uVar1 = 1;
    DAT_ffffd130 = 0;
  }
  else {
    uVar1 = (uint)DAT_ffffd12e;
    if (((uVar1 == 1) && (uVar1 = 0x88, DAT_ffffcfe6 == 0x88)) && (DAT_ffffd118 < DAT_ffffd11c)) {
      if (fVar2 < 10.0098) {
        uVar1 = 0xffffffff;
      }
      if (fVar3 < 10.0098) {
        uVar1 = FUN_000671a4(0x2d);
        uVar1 = uVar1 & 0xff;
        if (uVar1 == 0) {
          DAT_ffffd130 = 1;
          DAT_ffffd136 = 1;
        }
      }
    }
  }
  return uVar1;
}


