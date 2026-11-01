/* ROM address: 0x00052354; body bytes: 80; decompiled */

uint FUN_00052354(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_0003eaa4(&DAT_ffff86c4,0);
  if ((((DAT_ffffd13f == '\0') && (cVar2 == '\x01')) ||
      ((DAT_ffffd13f == '\x02' && (cVar2 == '\x03')))) || (uVar1 = (uint)DAT_ffffd201, uVar1 == 1))
  {
    uVar1 = FUN_0003ebc0(&DAT_ffff86ec,0x17);
  }
  DAT_ffffd13f = cVar2;
  return uVar1;
}


