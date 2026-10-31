/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00048558; body bytes: 220; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000475e4 (220 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00048558(void)

{
  byte snapshot_DAT_ffffcc92;
  char cVar2;
  float fVar3;
  float arg0;
  
  cVar2 = DAT_ffffcca2;
  snapshot_DAT_ffffcc92 = DAT_ffffcc92;
  fVar3 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&DAT_ffff807c);
  arg0 = fVar3 + 5.0;
  if ((snapshot_DAT_ffffcc92 < 3) && (cVar2 == '\x01')) {
    DAT_ffffccac = 1;
  }
  else {
    DAT_ffffccac = 0;
  }
  if ((((snapshot_DAT_ffffcc92 < 3) || (DAT_ffffccb1 != '\0')) || (cVar2 != '\x01')) &&
     (((2 < DAT_ffffccb0 || (snapshot_DAT_ffffcc92 < 3)) || (cVar2 != '\x01')))) {
    if (DAT_ffffccae < 0x40) {
      DAT_ffffcca8 = rx8_min_float(arg0,DAT_ffffb2a4 + fVar3);
      DAT_ffffccae = rx8_add_u16_saturate((int)(short)DAT_ffffccae,1);
    }
    else {
      DAT_ffffcca8 = rx8_min_float(arg0,DAT_ffffcca8 + 0.007999999);
    }
  }
  else {
    DAT_ffffcca8 = rx8_min_float(arg0,DAT_ffffb2a4 + fVar3);
    DAT_ffffccae = 0;
  }
  DAT_ffffccb1 = cVar2;
  DAT_ffffccb0 = snapshot_DAT_ffffcc92;
  return;
}


