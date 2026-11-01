/* ROM address: 0x00042b24; body bytes: 286; decompiled */

uint FUN_00042b24(void)

{
  char cVar1;
  char cVar2;
  char cVar4;
  uint uVar3;
  
  cVar2 = DAT_ffffd201;
  cVar1 = DAT_ffffc99f;
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc9b8 = 0;
  }
  else if ((DAT_ffffc9d6 == '\x01') && (DAT_ffffc99f == '\0')) {
    DAT_ffffc9b8 = 0x494;
  }
  else if (DAT_ffffc9b8 != 0) {
    DAT_ffffc9b8 = DAT_ffffc9b8 + -1;
  }
  cVar4 = FUN_00002440(DAT_ffffb360,0,0x3727c5ac);
  if (cVar2 == '\x01') {
    DAT_ffffc9d5 = 0;
    DAT_ffffc9c6 = 0;
    DAT_ffffc9db = 0;
  }
  else if ((DAT_ffffc9d4 == '\0') && (cVar4 != '\0')) {
    DAT_ffffc9d5 = 1;
    DAT_ffffc9c6 = 0;
  }
  else if (DAT_ffffc9d5 == 1) {
    DAT_ffffc9c6 = FUN_00002460((int)DAT_ffffc9c6,1);
  }
  uVar3 = (uint)DAT_ffffc9bc;
  if (((uVar3 != 1) || (DAT_ffffc9b8 != 0)) ||
     ((cVar4 != '\0' &&
      ((uVar3 = (uint)DAT_ffffc9d5, uVar3 != 1 || (uVar3 = (uint)DAT_ffffb364, 1.0 <= DAT_ffffb290))
      )))) {
    DAT_ffffc9be = 0;
  }
  else {
    DAT_ffffc9be = 1;
    DAT_ffffc9db = 1;
  }
  DAT_ffffc9d6 = cVar1;
  DAT_ffffc9d4 = cVar4;
  return uVar3;
}


