/* ROM address: 0x0002e1d8; body bytes: 84; decompiled */

void FUN_0002e1d8(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffbd59;
  if (DAT_ffffbd59 == '\x01') {
    if ((DAT_ffffbdab == '\0') || (0xf < DAT_ffffbda4)) {
      DAT_ffffbdaa = 1;
      DAT_ffffbda4 = 0;
    }
    else {
      DAT_ffffbdaa = 0;
    }
    DAT_ffffbda4 = FUN_00002460((int)(short)DAT_ffffbda4,1);
  }
  else {
    DAT_ffffbdaa = 0;
    DAT_ffffbda4 = 0;
  }
  DAT_ffffbdab = cVar1;
  return;
}


