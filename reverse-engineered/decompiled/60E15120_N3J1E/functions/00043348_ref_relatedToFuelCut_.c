/* ROM address: 0x00043348; body bytes: 122; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00042b7c (122 bytes). Names prefixed ref_
   are inherited hypotheses. */

char ref_relatedToFuelCut_(void)

{
  char cVar1;
  float fVar2;
  
  fVar2 = 0.0;
  if (DAT_ffffca44 == '\x01') {
    DAT_ffffc9d0 = (DAT_ffffc9d4 + DAT_ffffc9f0) - DAT_ffffca14;
    DAT_ffffc9cc = DAT_ffffc9d0 - 0.01;
    DAT_ffffc9c8 = rx8_clamp_float(DAT_ffffc9cc,0.0,1.0);
    DAT_ffffc9c4 = DAT_ffffc9c8 - DAT_ffffc9bc;
    cVar1 = '\x01';
    if (1 < DAT_ffffca3f) {
      fVar2 = DAT_ffffc9c0 + DAT_ffffc9c4;
    }
  }
  else {
    cVar1 = DAT_ffffca44;
    fVar2 = DAT_ffffc9c0;
    if (DAT_ffffca3d == '\0') {
      DAT_ffffc9cc = 0.0;
    }
  }
  DAT_ffffc9c0 = fVar2;
  return cVar1;
}


