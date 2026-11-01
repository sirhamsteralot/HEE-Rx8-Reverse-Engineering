/* ROM address: 0x000185c8; body bytes: 340; decompiled */

uint FUN_000185c8(char param_1)

{
  char cVar2;
  uint uVar1;
  byte *pbVar3;
  byte bVar4;
  
  if (param_1 == '\0') {
    DAT_ffffa981 = 0;
    DAT_ffffa982 = 0;
  }
  if (DAT_ffffa981 == 1) {
    cVar2 = '\0';
    bVar4 = 0;
    if (DAT_ffffa968 == '\x01') {
      cVar2 = FUN_0003eaa4(&DAT_ffff8078,0);
      if (((cVar2 == '\0') || (cVar2 = FUN_0003eaa4(&DAT_ffff807c,0), cVar2 != '\x01')) ||
         (DAT_ffffaa10 < -40.0)) {
        pbVar3 = &DAT_00078e33;
        bVar4 = 1;
        cVar2 = '\0';
      }
      else {
        pbVar3 = &DAT_00078e34;
        cVar2 = '\x01';
        bVar4 = 0;
      }
      DAT_ffffa97e = *pbVar3;
    }
    DAT_ffffa981 = 2;
    DAT_ffffa977 = cVar2;
    DAT_ffffa978 = bVar4;
  }
  if (DAT_ffffa981 == 0) {
    if (DAT_ffffa97c == 5) {
      DAT_ffffa97b = -0x80;
      DAT_ffffa981 = 1;
    }
    else if (DAT_ffffa97c == 4) {
      DAT_ffffa97b = '0';
      FUN_000182ba(0);
      if (DAT_ffffa974 < 0x3c) {
        DAT_ffffa97f = DAT_ffffa974 + 1;
      }
    }
    else {
      DAT_ffffa97b = '\x10';
      FUN_000182ba(2);
    }
  }
  uVar1 = (uint)DAT_ffffa981;
  if ((uVar1 == 2) && ((DAT_ffffa977 == '\x01' || (uVar1 = (uint)DAT_ffffa978, uVar1 == 1)))) {
    if ((DAT_ffffa97c & 1) == 0) {
      DAT_ffffa97b = '0';
      FUN_000182ba(1);
      uVar1 = (uint)DAT_ffffa97c;
      if ((uVar1 == 5) && (DAT_ffffa97e < 2)) {
        DAT_ffffa982 = 1;
        DAT_ffffa97f = '\0';
        DAT_ffffa97e = 0;
        uVar1 = FUN_00002478((int)DAT_ffffa97b,0x30);
        DAT_ffffa97b = (char)uVar1;
      }
    }
    else {
      DAT_ffffa97b = '\b';
      uVar1 = FUN_000182ba(1);
      if (DAT_ffffa97e != 0) {
        DAT_ffffa97e = DAT_ffffa97e - 1;
      }
    }
  }
  return uVar1;
}


