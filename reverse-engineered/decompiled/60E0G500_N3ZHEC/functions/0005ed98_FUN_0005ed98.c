/* ROM address: 0x0005ed98; body bytes: 66; decompiled */

uint FUN_0005ed98(void)

{
  uint uVar1;
  float fVar2;
  
  uVar1 = (uint)DAT_ffffaaf9;
  if (uVar1 == 1) {
    uVar1 = FUN_0003ebc0(&DAT_ffff919c,0);
  }
  fVar2 = DAT_ffffad98;
  if ((0.55 <= DAT_ffffad98) && (DAT_ffffd3c8 < 0.55)) {
    uVar1 = FUN_0003ebc0(&DAT_ffff919e,0);
  }
  DAT_ffffd3c8 = fVar2;
  return uVar1;
}


