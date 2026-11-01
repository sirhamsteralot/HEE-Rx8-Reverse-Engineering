/* ROM address: 0x000463ea; body bytes: 208; decompiled */

uint FUN_000463ea(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_000671a4(0x66);
  if (((cVar2 == '\0') && (DAT_ffffcd02 == '\x01')) &&
     (cVar2 = FUN_0003eaa4(&DAT_ffff875a,0), cVar2 == '\0')) {
    if (DAT_ffffa110 == '\x02') {
      DAT_ffffcc3a = FUN_00002460((int)(short)DAT_ffffcc3a,1);
      DAT_ffffcc3c = 0;
      if (0x18 < DAT_ffffcc3a) {
        FUN_0003ebc0(&DAT_ffff875a,1);
      }
    }
    else {
      DAT_ffffcc3c = FUN_00002460((int)(short)DAT_ffffcc3c,1);
      if (0x18 < DAT_ffffcc3c) {
        DAT_ffffcc35 = 1;
        DAT_ffffcc3a = 0;
      }
    }
  }
  else {
    DAT_ffffcc3c = 0;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff875a,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_000604dc(0x66,1);
    return uVar1;
  }
  if (DAT_ffffcc35 == 1) {
    uVar1 = FUN_000604dc(0x66,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc35;
}


