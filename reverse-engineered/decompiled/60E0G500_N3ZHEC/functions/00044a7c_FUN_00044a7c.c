/* ROM address: 0x00044a7c; body bytes: 122; decompiled */

uint FUN_00044a7c(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = DAT_ffffb0ec;
  if (DAT_ffffb13a == '\x01') {
    DAT_ffffcbab = '\x01';
    DAT_ffffcbaa = 0;
  }
  if ((DAT_ffffcbab == '\x01') &&
     (((DAT_ffffcbce == '\0' && (DAT_ffffb0ec == 1)) ||
      ((DAT_ffffb0ec == 1 && (0x138 < DAT_ffffcbc4)))))) {
    DAT_ffffcbaa = 1;
    DAT_ffffcbab = '\0';
  }
  uVar2 = (uint)DAT_ffffb0ec;
  if (uVar2 == 1) {
    uVar2 = FUN_00002460((int)(short)DAT_ffffcbc4,1);
    DAT_ffffcbc4 = (ushort)uVar2;
  }
  else {
    DAT_ffffcbc4 = 0;
  }
  DAT_ffffcbce = bVar1;
  return uVar2;
}


