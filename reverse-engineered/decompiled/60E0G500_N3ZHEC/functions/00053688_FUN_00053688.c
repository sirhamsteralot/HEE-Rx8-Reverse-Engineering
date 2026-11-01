/* ROM address: 0x00053688; body bytes: 54; decompiled */

uint FUN_00053688(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00011f34();
  uVar2 = uVar1;
  if ((DAT_ffffd172 == '\0') && (uVar2 = uVar1 & 0xff, uVar2 == 1)) {
    FUN_0003ebc0(&DAT_ffff8706,0);
    uVar2 = FUN_0003ebc0(&DAT_ffff8708,0);
  }
  DAT_ffffd172 = (char)uVar1;
  return uVar2;
}


