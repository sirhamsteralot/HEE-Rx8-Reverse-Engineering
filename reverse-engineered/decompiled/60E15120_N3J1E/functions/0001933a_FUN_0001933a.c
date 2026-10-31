/* ROM address: 0x0001933a; body bytes: 76; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00019f36 (76 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0001933a(void)

{
  float fVar1;
  float fVar2;
  float arg0;
  
  fVar1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x412db22d,&DAT_ffff8068);
  fVar1 = DAT_ffffa99c - fVar1;
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x412db22d,&DAT_ffff8070);
  arg0 = 0.0;
  fVar2 = DAT_ffffa9a4 - fVar2;
  DAT_ffffa9ac = rx8_max_float(0.0,fVar1);
  DAT_ffffa9b0 = rx8_max_float(arg0,fVar2);
  return;
}


