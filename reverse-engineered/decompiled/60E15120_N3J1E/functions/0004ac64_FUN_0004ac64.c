/* ROM address: 0x0004ac64; body bytes: 150; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00049c20 (150 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0004ac64(void)

{
  short sVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  
  cVar4 = DAT_ffffd1c5;
  cVar2 = DAT_ffffcdc7;
  sVar1 = DAT_ffffcdc2;
  if ((DAT_ffffcdc7 == '\x01') ||
     (((DAT_ffffcdce != 0 && (DAT_ffffcdc2 == 0)) || (DAT_ffffd1c5 == '\x01')))) {
    DAT_ffffcdc5 = 0;
  }
  else if (DAT_ffffcdd1 == '\0') {
    DAT_ffffcdc5 = rx8_add_u8_saturate((int)(char)DAT_ffffcdc5,1);
  }
  cVar3 = '\x01';
  if ((cVar2 == '\x01') || (cVar3 = cVar4, cVar4 == '\x01')) {
    DAT_ffffcdc1 = 0;
    cVar4 = cVar3;
  }
  else if (0xc < DAT_ffffcdc5) {
    DAT_ffffcdc1 = 1;
  }
  DAT_ffffcdce = sVar1;
  return cVar4;
}


