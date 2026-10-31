/* ROM address: 0x00041bd4; body bytes: 286; decompiled */

uint FUN_00041bd4(void)

{
  char cVar1;
  char cVar2;
  char cVar4;
  uint uVar3;
  
  cVar2 = DAT_ffffd1c5;
  cVar1 = DAT_ffffc92f;
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc948 = 0;
  }
  else if ((DAT_ffffc966 == '\x01') && (DAT_ffffc92f == '\0')) {
    DAT_ffffc948 = 0x494;
  }
  else if (DAT_ffffc948 != 0) {
    DAT_ffffc948 = DAT_ffffc948 + -1;
  }
  cVar4 = rx8_is_outside_tolerance_band(DAT_ffffb2f0,0,0x3727c5ac);
  if (cVar2 == '\x01') {
    DAT_ffffc965 = 0;
    DAT_ffffc956 = 0;
    DAT_ffffc96b = 0;
  }
  else if ((DAT_ffffc964 == '\0') && (cVar4 != '\0')) {
    DAT_ffffc965 = 1;
    DAT_ffffc956 = 0;
  }
  else if (DAT_ffffc965 == 1) {
    DAT_ffffc956 = rx8_add_u16_saturate((int)DAT_ffffc956,1);
  }
  uVar3 = (uint)DAT_ffffc94c;
  if (((uVar3 != 1) || (DAT_ffffc948 != 0)) ||
     ((cVar4 != '\0' &&
      ((uVar3 = (uint)DAT_ffffc965, uVar3 != 1 || (uVar3 = (uint)DAT_ffffb2f4, 1.0 <= DAT_ffffb220))
      )))) {
    DAT_ffffc94e = 0;
  }
  else {
    DAT_ffffc94e = 1;
    DAT_ffffc96b = 1;
  }
  DAT_ffffc966 = cVar1;
  DAT_ffffc964 = cVar4;
  return uVar3;
}


