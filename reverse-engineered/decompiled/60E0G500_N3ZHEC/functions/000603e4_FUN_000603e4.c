/* ROM address: 0x000603e4; body bytes: 44; decompiled */

void FUN_000603e4(void)

{
  undefined **ppuVar1;
  float fVar2;
  
  if (DAT_ffffb5a4 == '\0') {
    ppuVar1 = &PTR_DAT_00069acc;
  }
  else {
    ppuVar1 = &PTR_DAT_00069a54;
  }
  fVar2 = (float)FUN_00002068(0x42a00000,ppuVar1);
  DAT_ffffd3f4 = fVar2 + -150.0;
  return;
}


