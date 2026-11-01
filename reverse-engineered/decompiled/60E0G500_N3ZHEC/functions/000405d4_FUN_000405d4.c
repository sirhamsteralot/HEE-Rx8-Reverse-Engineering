/* ROM address: 0x000405d4; body bytes: 136; decompiled */

uint FUN_000405d4(void)

{
  uint uVar1;
  float fVar2;
  
  fVar2 = DAT_ffffaae8;
  if (DAT_ffffc74f == 1) {
    if ((DAT_ffffaae8 < 0.85) && (DAT_ffffc74a < 0xc3)) {
      DAT_ffffc74a = FUN_00002460((int)(short)DAT_ffffc74a,1);
    }
  }
  else {
    DAT_ffffc74a = 0;
  }
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc745 = 0;
    DAT_ffffc744 = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffc74f;
    if (uVar1 == 1) {
      if (0.85 <= fVar2) {
        DAT_ffffc744 = 1;
      }
      else {
        uVar1 = (uint)(short)DAT_ffffc74a;
        if (0xc2 < uVar1) {
          DAT_ffffc745 = 1;
        }
      }
    }
  }
  return uVar1;
}


