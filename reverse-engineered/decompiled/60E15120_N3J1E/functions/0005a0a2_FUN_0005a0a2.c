/* ROM address: 0x0005a0a2; body bytes: 136; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005885a (136 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_0005a0a2(void)

{
  int iVar1;
  
  if (((DAT_ffffcd0c & 0x40) == 0) && ((DAT_ffffcd0c & 0x20) == 0)) {
    if ((((DAT_ffffcd0c & 0x10) == 0) && ((DAT_ffffcd0c & 8) == 0)) && ((DAT_ffffcd0c & 4) == 0)) {
      iVar1 = -((((int)(char)DAT_ffffcd0c & 0x80U) == 0) - 1);
      if (iVar1 == 1) {
        DAT_ffffd289 = 0x68;
      }
      else {
        DAT_ffffd289 = 0;
      }
    }
    else {
      iVar1 = 1;
      DAT_ffffd289 = 0x69;
    }
  }
  else {
    iVar1 = 1;
    DAT_ffffd289 = 0x6d;
  }
  return iVar1;
}


