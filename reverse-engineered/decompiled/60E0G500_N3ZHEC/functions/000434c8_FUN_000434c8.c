/* ROM address: 0x000434c8; body bytes: 206; decompiled */

uint FUN_000434c8(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_ffffb3c8;
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc9ef = 0;
    DAT_ffffc9f0 = 0;
    DAT_ffffc9fe = 0;
    DAT_ffffca00 = 0;
    DAT_ffffca02 = 0;
    return 1;
  }
  if ((((DAT_ffffc9e8 != '\x01') || (DAT_ffffb3c8 != 1)) || (DAT_ffffc9fe < 0x9d)) ||
     (DAT_ffffc9e4 < 17000.0)) {
    DAT_ffffca00 = 0;
  }
  else {
    if (DAT_ffffaaf0 < 500.0) {
      if (3 < DAT_ffffca02) {
        DAT_ffffc9f0 = 1;
      }
      DAT_ffffca02 = FUN_00002460((int)(short)DAT_ffffca02,1);
      DAT_ffffca00 = 0;
      goto LAB_000435be;
    }
    if (0xf < DAT_ffffca00) {
      DAT_ffffc9ef = 1;
    }
    DAT_ffffca00 = FUN_00002460((int)(short)DAT_ffffca00,1);
  }
  DAT_ffffca02 = 0;
LAB_000435be:
  uVar2 = (uint)bVar1;
  if (uVar2 == 1) {
    uVar2 = FUN_00002460((int)(short)DAT_ffffc9fe,1);
    DAT_ffffc9fe = (ushort)uVar2;
  }
  else {
    DAT_ffffc9fe = 0;
  }
  return uVar2;
}


