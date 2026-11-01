/* ROM address: 0x0003c7a4; body bytes: 178; decompiled */

uint FUN_0003c7a4(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if ((((DAT_ffffd201 == '\x01') || (uVar1 = 1, DAT_ffffd1e9 == '\x01')) ||
      (uVar1 = 1, DAT_ffffc621 == '\x01')) || (uVar1 = (uint)DAT_ffffc62d, uVar1 == 1)) {
    DAT_ffffc614 = '\x1b';
    DAT_ffffc615 = '\x06';
  }
  else if (200.0 < DAT_ffffc610 - DAT_ffffc60c) {
    if ((0.0 < DAT_ffffbc1c) || (uVar1 = (uint)(short)DAT_ffffa424, uVar1 < 0x321)) {
      DAT_ffffc614 = '\x1b';
    }
    else if (DAT_ffffc614 != '\0') {
      DAT_ffffc614 = DAT_ffffc614 + -1;
    }
    DAT_ffffc615 = '\x06';
  }
  else {
    DAT_ffffc614 = '\x1b';
    if (DAT_ffffa424 < 0x321) {
      uVar1 = 6;
      DAT_ffffc615 = '\x06';
    }
    else {
      uVar1 = 0;
      if (DAT_ffffc615 != '\0') {
        uVar1 = 0xff;
        DAT_ffffc615 = DAT_ffffc615 + -1;
      }
    }
  }
  return uVar1;
}


