/* ROM address: 0x00032b30; body bytes: 76; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00032e4c (76 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00032b30(void)

{
  int iVar1;
  
  if (((DAT_ffffcd0e & 0x40) == 0) && ((DAT_ffffcd0e & 0x20) == 0)) {
    iVar1 = -((((int)(char)DAT_ffffcd0e & 0x80U) == 0) - 1);
    if (iVar1 == 1) {
      DAT_ffffbfe5 = 2;
    }
    else {
      DAT_ffffbfe5 = 0;
    }
  }
  else {
    iVar1 = 1;
    DAT_ffffbfe5 = 8;
  }
  return iVar1;
}


