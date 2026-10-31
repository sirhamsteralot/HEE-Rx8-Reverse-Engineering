/* ROM address: 0x0002df62; body bytes: 116; decompiled */

void FUN_0002df62(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = 0.0;
  fVar2 = fVar3;
  if ((((DAT_ffffbced != '\0') && (fVar2 = DAT_ffffbcf8, DAT_ffffbd3e == '\x01')) &&
      (fVar2 = fVar3, DAT_ffffbceb != '\x01')) &&
     (((DAT_ffffb53a != '\x01' &&
       (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8664,0), fVar2 = fVar3, cVar1 != '\0')) &&
      (DAT_ffffaa68 != '\0')))) {
    fVar2 = rx8_clamp_float(DAT_ffffbd00 + DAT_ffffbd08,0.0,100.0);
  }
  DAT_ffffbcf8 = fVar2;
  return;
}


