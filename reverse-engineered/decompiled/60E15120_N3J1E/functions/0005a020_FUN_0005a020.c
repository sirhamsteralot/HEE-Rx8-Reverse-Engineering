/* ROM address: 0x0005a020; body bytes: 130; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000587d8 (130 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_0005a020(void)

{
  int iVar1;
  
  if (((((DAT_ffffcd0c & 0x40) == 0) && ((DAT_ffffcd0c & 0x20) == 0)) &&
      ((DAT_ffffcd0c & 0x10) == 0)) && (((DAT_ffffcd0c & 8) == 0 && ((DAT_ffffcd0c & 4) == 0)))) {
    iVar1 = -((((int)(char)DAT_ffffcd0c & 0x80U) == 0) - 1);
    if (iVar1 == 1) {
      DAT_ffffd288 = 6;
    }
    else {
      DAT_ffffd288 = 0;
    }
  }
  else {
    iVar1 = 1;
    DAT_ffffd288 = 7;
  }
  return iVar1;
}


