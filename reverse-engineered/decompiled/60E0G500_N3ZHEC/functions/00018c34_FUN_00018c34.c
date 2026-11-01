/* ROM address: 0x00018c34; body bytes: 162; decompiled */

uint FUN_00018c34(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  
  cVar2 = DAT_ffffa991;
  cVar1 = DAT_ffffa990;
  if (0.0 <= DAT_ffffb600) {
    if ((DAT_ffffa990 == '\x01') && (DAT_ffffa99c == '\0')) {
      FUN_0003ebc0(&DAT_ffff8082,1);
    }
    if ((cVar2 == '\x01') && (DAT_ffffa99d == '\0')) {
      FUN_0003ebc0(&DAT_ffff8084,1);
    }
  }
  else if (((DAT_ffffa990 == '\x01') && (DAT_ffffa99c == '\0')) ||
          ((DAT_ffffa991 == '\x01' && (DAT_ffffa99d == '\0')))) {
    FUN_0003ebc0(&DAT_ffff8080,1);
  }
  uVar3 = (uint)DAT_ffffa975;
  if (uVar3 == 4) {
    uVar3 = FUN_0003ebc0(&DAT_ffff8086,1);
  }
  DAT_ffffa99c = cVar1;
  DAT_ffffa99d = cVar2;
  return uVar3;
}


