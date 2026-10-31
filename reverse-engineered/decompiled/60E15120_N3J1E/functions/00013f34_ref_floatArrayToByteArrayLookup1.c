/* ROM address: 0x00013f34; body bytes: 118; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00013e98 (118 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_floatArrayToByteArrayLookup1(float param_1)

{
  byte bVar1;
  byte bVar2;
  
  if (0.0 <= param_1) {
    bVar1 = 0x15;
    if (param_1 < 9.0) {
      bVar2 = 0;
      while ((bVar1 = DAT_ffffa774, bVar2 < 0x15 &&
             ((param_1 < (float)(&CAL_table_229)[bVar2] ||
              (bVar1 = bVar2, (float)(&CAL_table_229)[(byte)(bVar2 + 1)] <= param_1))))) {
        bVar2 = bVar2 + 1;
      }
    }
  }
  else {
    DAT_ffffa774 = 0;
    bVar1 = DAT_ffffa774;
  }
  DAT_ffffa774 = bVar1;
  rx8_decode_u8_affine
            (0x3f000000,0xc2480000,(int)(char)(&CAL_Table_2D___110__228)[DAT_ffffa774]);
  return;
}


