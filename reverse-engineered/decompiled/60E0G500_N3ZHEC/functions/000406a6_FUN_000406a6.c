/* ROM address: 0x000406a6; body bytes: 136; decompiled */

uint FUN_000406a6(void)

{
  uint uVar1;
  float fVar2;
  
  fVar2 = DAT_ffffaae8;
  if (DAT_ffffc750 == 1) {
    if ((1.15 <= DAT_ffffaae8) && (DAT_ffffc74c < 0xc3)) {
      DAT_ffffc74c = FUN_00002460((int)(short)DAT_ffffc74c,1);
    }
  }
  else {
    DAT_ffffc74c = 0;
  }
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc747 = 0;
    DAT_ffffc746 = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffc750;
    if (uVar1 == 1) {
      if (fVar2 < 1.15) {
        DAT_ffffc746 = 1;
      }
      else {
        uVar1 = (uint)(short)DAT_ffffc74c;
        if (0xc2 < uVar1) {
          DAT_ffffc747 = 1;
        }
      }
    }
  }
  return uVar1;
}


