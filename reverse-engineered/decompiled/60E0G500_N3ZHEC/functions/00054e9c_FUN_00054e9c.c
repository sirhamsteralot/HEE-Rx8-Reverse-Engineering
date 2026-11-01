/* ROM address: 0x00054e9c; body bytes: 120; decompiled */

uint FUN_00054e9c(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_00011f34();
  if (((cVar2 == '\x01') && (DAT_ffffd1fd == '\0')) || (DAT_ffffd201 == '\x01')) {
    uVar1 = FUN_0003ebc0(&DAT_ffff900c,0);
  }
  else if (((DAT_ffffcbde == '\x01') || (DAT_ffffcc0a == '\x01')) ||
          ((uVar1 = (uint)DAT_ffffcbdd, uVar1 == 1 && (uVar1 = (uint)DAT_ffffcc09, uVar1 == 1)))) {
    uVar1 = FUN_0003ebc0(&DAT_ffff900c,1);
  }
  DAT_ffffd1fd = cVar2;
  return uVar1;
}


