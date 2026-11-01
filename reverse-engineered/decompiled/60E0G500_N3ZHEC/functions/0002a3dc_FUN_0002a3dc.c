/* ROM address: 0x0002a3dc; body bytes: 128; decompiled */

int FUN_0002a3dc(void)

{
  char cVar2;
  int iVar1;
  float fVar3;
  float arg1;
  
  arg1 = 0.0;
  cVar2 = FUN_00002440(DAT_ffffbb88,0,0x3727c5ac);
  if (DAT_ffffbb8c == '\x01') {
    DAT_ffffbb83 = 0xff;
    iVar1 = 1;
  }
  else {
    iVar1 = (int)DAT_ffffa428;
    if (iVar1 == 0) {
      DAT_ffffbb83 = 0;
    }
    else if (cVar2 == '\0') {
      DAT_ffffbb83 = 0xfe;
    }
    else {
      fVar3 = rx8_clamp_float((DAT_ffffbd20 / DAT_ffffbb88) * 100.0,arg1,100.0);
      iVar1 = FUN_000024d0(fVar3,0x3ec99326,arg1);
      DAT_ffffbb83 = (undefined1)iVar1;
    }
  }
  return iVar1;
}


