/* ROM address: 0x0004f2d2; body bytes: 334; decompiled */

uint FUN_0004f2d2(void)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  char cVar4;
  
  cVar2 = DAT_ffffd002;
  uVar3 = (uint)(char)DAT_ffffcff1;
  bVar1 = (uVar3 & 0x80) != 0;
  if (DAT_ffffd201 == '\0') {
    if ((DAT_ffffd00c == '\0') && (DAT_ffffd002 == '\x01')) {
      DAT_ffffcfff = '\0';
      DAT_ffffcffd = 0;
      DAT_ffffcffe = 0;
      uVar3 = 1;
    }
    else {
      cVar4 = FUN_0003eaa4(&DAT_ffff86cc,0);
      if (((((cVar4 == '\x01') ||
            ((((cVar4 = FUN_0003eaa4(&DAT_ffff86c8,0), cVar4 == '\x01' || (DAT_ffffd006 == '\x01'))
              || (cVar4 = FUN_0003eaa4(&DAT_ffff870a,0), cVar4 == '\x01')) ||
             (DAT_ffffd001 == '\x01')))) && (bVar1)) ||
          ((((DAT_ffffcff1 & 0x20) != 0 && (DAT_ffffd16d == '\x01')) || (DAT_ffffcfed == '\0')))) ||
         (((DAT_ffffd020 < DAT_ffffd01c && (0x1f < DAT_ffffcfe6)) &&
          ((DAT_ffffd12e == '\x01' && (DAT_ffffd034 == '\0')))))) {
        DAT_ffffcfff = '\x01';
      }
      if (((DAT_ffffcfff == '\x01') || (DAT_ffffd14a == '\x01')) ||
         ((DAT_ffffd183 == '\x01' && (bVar1)))) {
        DAT_ffffcffd = 1;
      }
      uVar3 = 1;
      if ((DAT_ffffcfff == '\x01') || (uVar3 = (uint)DAT_ffffd004, uVar3 == 1)) {
        DAT_ffffcffe = 1;
      }
    }
  }
  DAT_ffffd00c = cVar2;
  return uVar3;
}


