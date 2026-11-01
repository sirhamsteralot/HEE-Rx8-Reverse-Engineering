/* ROM address: 0x00046538; body bytes: 208; decompiled */

uint FUN_00046538(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_000671a4(0x69);
  if (((cVar2 == '\0') && (DAT_ffffcd02 == '\x01')) &&
     (cVar2 = FUN_0003eaa4(&DAT_ffff875c,0), cVar2 == '\0')) {
    if (DAT_ffffa111 == '\x01') {
      DAT_ffffcc42 = FUN_00002460((int)(short)DAT_ffffcc42,1);
      DAT_ffffcc44 = 0;
      if (0x18 < DAT_ffffcc42) {
        FUN_0003ebc0(&DAT_ffff875c,1);
      }
    }
    else {
      DAT_ffffcc44 = FUN_00002460((int)(short)DAT_ffffcc44,1);
      if (0x18 < DAT_ffffcc44) {
        DAT_ffffcc40 = 1;
        DAT_ffffcc42 = 0;
      }
    }
  }
  else {
    DAT_ffffcc44 = 0;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff875c,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_000604dc(0x69,1);
    return uVar1;
  }
  if (DAT_ffffcc40 == 1) {
    uVar1 = FUN_000604dc(0x69,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc40;
}


