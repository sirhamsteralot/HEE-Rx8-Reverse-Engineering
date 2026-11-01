/* ROM address: 0x000522c4; body bytes: 144; decompiled */

uint FUN_000522c4(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  sVar1 = DAT_ffffcfe6;
  uVar2 = FUN_0003eaa4(&DAT_ffff86ec,0x17);
  uVar3 = uVar2;
  if (DAT_ffffd201 == '\0') {
    if ((DAT_ffffd130 == '\x01') || (uVar3 = (uint)DAT_ffffd131, uVar3 == 1)) {
      uVar3 = FUN_0003ebc0(&DAT_ffff86ec,0);
    }
    else if ((((DAT_ffffd13c == 0x1e) && (sVar1 == 0x1f)) &&
             (uVar3 = (uint)DAT_ffffd12e, uVar3 == 1)) && ((uVar2 & 0xff) != 0)) {
      uVar3 = FUN_0003ebc0(&DAT_ffff86ec,uVar2 + 0xff);
    }
  }
  DAT_ffffd13c = sVar1;
  return uVar3;
}


