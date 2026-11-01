/* ROM address: 0x000462e4; body bytes: 208; decompiled */

uint FUN_000462e4(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_000671a4(0x67);
  if (((cVar2 == '\0') && (DAT_ffffcd02 == '\x01')) &&
     (cVar2 = FUN_0003eaa4(&DAT_ffff8758,0), cVar2 == '\0')) {
    if (DAT_ffffa110 == '\x01') {
      DAT_ffffcc36 = FUN_00002460((int)(short)DAT_ffffcc36,1);
      DAT_ffffcc38 = 0;
      if (0x18 < DAT_ffffcc36) {
        FUN_0003ebc0(&DAT_ffff8758,1);
      }
    }
    else {
      DAT_ffffcc38 = FUN_00002460((int)(short)DAT_ffffcc38,1);
      if (0x18 < DAT_ffffcc38) {
        DAT_ffffcc34 = 1;
        DAT_ffffcc36 = 0;
      }
    }
  }
  else {
    DAT_ffffcc38 = 0;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff8758,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_000604dc(0x67,1);
    return uVar1;
  }
  if (DAT_ffffcc34 == 1) {
    uVar1 = FUN_000604dc(0x67,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc34;
}


