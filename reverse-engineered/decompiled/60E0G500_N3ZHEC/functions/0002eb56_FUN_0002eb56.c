/* ROM address: 0x0002eb56; body bytes: 116; decompiled */

void FUN_0002eb56(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = 0.0;
  fVar2 = fVar3;
  if ((((DAT_ffffbd59 != '\0') && (fVar2 = DAT_ffffbd64, DAT_ffffbdaa == '\x01')) &&
      (fVar2 = fVar3, DAT_ffffbd57 != '\x01')) &&
     (((DAT_ffffb5aa != '\x01' &&
       (cVar1 = FUN_0003eaa4(&DAT_ffff868c,0), fVar2 = fVar3, cVar1 != '\0')) &&
      (DAT_ffffaae0 != '\0')))) {
    fVar2 = rx8_clamp_float(DAT_ffffbd6c + DAT_ffffbd74,0.0,100.0);
  }
  DAT_ffffbd64 = fVar2;
  return;
}


