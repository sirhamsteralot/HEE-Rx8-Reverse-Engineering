/* ROM address: 0x0003c856; body bytes: 176; decompiled */

uint FUN_0003c856(void)

{
  uint uVar1;
  uint extraout_r0;
  uint extraout_r0_00;
  float fVar2;
  
  uVar1 = 1;
  if ((DAT_ffffd201 == '\x01') || (uVar1 = (uint)DAT_ffffd1e9, uVar1 == 1)) {
    DAT_ffffc60c = DAT_ffffcfc8;
    DAT_ffffc610 = DAT_ffffcfc8;
    DAT_ffffc616 = '\x02';
    DAT_ffffc617 = '\x02';
  }
  else {
    fVar2 = DAT_ffffcfc8;
    if (DAT_ffffc60c <= DAT_ffffcfc8) {
      if (DAT_ffffc616 == '\0') {
        DAT_ffffc616 = '\x02';
        DAT_ffffc60c = rx8_min_float(DAT_ffffc60c + 0.0625,DAT_ffffcfc8);
        uVar1 = extraout_r0;
      }
      else {
        DAT_ffffc616 = DAT_ffffc616 + -1;
      }
    }
    else {
      DAT_ffffc616 = '\x02';
      DAT_ffffc60c = DAT_ffffcfc8;
    }
    if (fVar2 <= DAT_ffffc610) {
      if (DAT_ffffc617 == '\0') {
        DAT_ffffc617 = '\x02';
        DAT_ffffc610 = rx8_max_float(DAT_ffffc610 - 0.0625,fVar2);
        uVar1 = extraout_r0_00;
      }
      else {
        DAT_ffffc617 = DAT_ffffc617 + -1;
      }
    }
    else {
      DAT_ffffc617 = '\x02';
      DAT_ffffc610 = fVar2;
    }
  }
  return uVar1;
}


