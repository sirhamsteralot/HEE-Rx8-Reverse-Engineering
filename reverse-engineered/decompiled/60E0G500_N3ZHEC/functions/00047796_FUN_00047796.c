/* ROM address: 0x00047796; body bytes: 150; decompiled */

uint FUN_00047796(void)

{
  char cVar2;
  uint uVar1;
  
  if (DAT_ffffccac == '\0') {
    FUN_0000b5fa();
  }
  if (DAT_ffffccac == '\x01') {
    if (DAT_ffffa229 == '\x01') {
      FUN_0003ebc0(&DAT_ffff8780,1);
      DAT_ffffccae = 0;
    }
    else {
      if (0xf9 < DAT_ffffccae) {
        DAT_ffffccad = 1;
      }
      DAT_ffffccae = FUN_00002460((int)(short)DAT_ffffccae,1);
    }
  }
  else {
    DAT_ffffccae = 0;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff8780,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_000604dc(0x5e,1);
    return uVar1;
  }
  if (DAT_ffffccad == 1) {
    uVar1 = FUN_000604dc(0x5e,2);
    return uVar1;
  }
  return (uint)DAT_ffffccad;
}


