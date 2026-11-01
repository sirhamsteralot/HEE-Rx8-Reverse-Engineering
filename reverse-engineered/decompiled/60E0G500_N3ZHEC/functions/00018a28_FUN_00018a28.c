/* ROM address: 0x00018a28; body bytes: 252; decompiled */

uint FUN_00018a28(void)

{
  byte bVar1;
  byte bVar3;
  uint uVar2;
  byte bVar4;
  char cVar5;
  
  bVar1 = DAT_ffffa974;
  bVar3 = FUN_0003eaa4(&DAT_ffff807a,0x37);
  cVar5 = '\0';
  bVar4 = 0;
  if ((DAT_ffffa969 == '\x01') && (DAT_ffffa975 == '\0')) {
    if (DAT_ffffa976 == '\0') {
      bVar3 = FUN_00002478();
      if (bVar3 < bVar1) {
        cVar5 = '\x01';
      }
    }
    else {
      if (bVar3 < 2) {
        bVar3 = 0;
      }
      else {
        bVar3 = bVar3 - 1;
      }
      if (bVar1 < bVar3) {
        bVar4 = 1;
      }
    }
  }
  if ((cVar5 == '\x01') && (0x3d < DAT_ffffa994)) {
    DAT_ffffa990 = 1;
  }
  if ((bVar4 == 1) && (0x7c < DAT_ffffa995)) {
    DAT_ffffa991 = 1;
  }
  DAT_ffffa992 = cVar5;
  DAT_ffffa993 = bVar4;
  if (cVar5 == '\x01') {
    DAT_ffffa994 = FUN_00002478((int)(char)DAT_ffffa994,1);
  }
  else {
    DAT_ffffa994 = 0;
  }
  uVar2 = (uint)DAT_ffffa993;
  if (uVar2 == 1) {
    uVar2 = FUN_00002478((int)(char)DAT_ffffa995,1);
    DAT_ffffa995 = (byte)uVar2;
  }
  else {
    DAT_ffffa995 = 0;
  }
  return uVar2;
}


