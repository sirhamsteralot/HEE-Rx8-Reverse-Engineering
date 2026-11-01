/* ROM address: 0x000298b4; body bytes: 60; decompiled */

void FUN_000298b4(void)

{
  float fVar1;
  undefined4 uVar2;
  
  if (DAT_ffffc656 == '\0') {
    uVar2 = 0xc2200000;
    fVar1 = rx8_clamp_float(DAT_ffffaa18,-40.0,214.0);
    DAT_ffffbb13 = FUN_000024d0(fVar1,0x3f800000,uVar2);
  }
  else {
    DAT_ffffbb13 = 0xff;
  }
  return;
}


