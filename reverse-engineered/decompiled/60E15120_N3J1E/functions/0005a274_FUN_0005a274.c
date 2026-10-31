/* ROM address: 0x0005a274; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00058a2c (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0005a274(void)

{
  float fVar1;
  float fVar2;
  
  if (DAT_ffffd1c5 == '\x01') {
    ref_updateMemoryAtAddress_float_VAL_ADDR(0,&DAT_ffff90fc);
    return;
  }
  fVar1 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff90fc);
  fVar2 = fVar1 + DAT_ffffd280;
  if (65535.0 < fVar1 + DAT_ffffd280) {
    fVar2 = 65535.0;
  }
  ref_updateMemoryAtAddress_float_VAL_ADDR(fVar2,&DAT_ffff90fc);
  return;
}


