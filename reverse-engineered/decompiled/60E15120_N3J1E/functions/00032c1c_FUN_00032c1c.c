/* ROM address: 0x00032c1c; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00032f38 (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00032c1c(void)

{
  int iVar1;
  char cVar2;
  
  if ((DAT_ffffcd0e & 0x40) == 0) {
    if ((DAT_ffffcd0e & 0x20) == 0) {
      iVar1 = -((((int)(char)DAT_ffffcd0e & 0x80U) == 0) - 1);
      if (iVar1 == 1) {
        cVar2 = '\x02';
      }
      else {
        cVar2 = '\x03';
      }
    }
    else {
      cVar2 = '\x01';
      iVar1 = 1;
    }
  }
  else {
    cVar2 = '\0';
    iVar1 = 1;
  }
  DAT_ffffbff4 = cVar2 << 4;
  return iVar1;
}


