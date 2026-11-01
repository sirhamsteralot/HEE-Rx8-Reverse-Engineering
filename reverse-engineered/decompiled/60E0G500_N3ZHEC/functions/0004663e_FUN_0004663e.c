/* ROM address: 0x0004663e; body bytes: 208; decompiled */

uint FUN_0004663e(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_000671a4(0x68);
  if (((cVar2 == '\0') && (DAT_ffffcd02 == '\x01')) &&
     (cVar2 = FUN_0003eaa4(&DAT_ffff875e,0), cVar2 == '\0')) {
    if (DAT_ffffa111 == '\x02') {
      DAT_ffffcc46 = FUN_00002460((int)(short)DAT_ffffcc46,1);
      DAT_ffffcc48 = 0;
      if (0x18 < DAT_ffffcc46) {
        FUN_0003ebc0(&DAT_ffff875e,1);
      }
    }
    else {
      DAT_ffffcc48 = FUN_00002460((int)(short)DAT_ffffcc48,1);
      if (0x18 < DAT_ffffcc48) {
        DAT_ffffcc41 = 1;
        DAT_ffffcc46 = 0;
      }
    }
  }
  else {
    DAT_ffffcc48 = 0;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff875e,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_000604dc(0x68,1);
    return uVar1;
  }
  if (DAT_ffffcc41 == 1) {
    uVar1 = FUN_000604dc(0x68,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc41;
}


