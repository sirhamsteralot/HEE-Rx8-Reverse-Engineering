/* ROM address: 0x0004ab9e; body bytes: 152; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00049b5a (152 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0004ab9e(void)

{
  short sVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  
  cVar4 = DAT_ffffd1c5;
  cVar2 = DAT_ffffcdc7;
  sVar1 = DAT_ffffcdc2;
  if ((DAT_ffffcdc7 == '\x01') ||
     (((DAT_ffffcdcc != 0 && (DAT_ffffcdc2 == 0)) || (DAT_ffffd1c5 == '\x01')))) {
    DAT_ffffcdc4 = 0;
  }
  else if (DAT_ffff9fa2 == '\x01') {
    DAT_ffffcdc4 = rx8_add_u8_saturate((int)(char)DAT_ffffcdc4,1);
  }
  cVar3 = '\x01';
  if ((cVar2 == '\x01') || (cVar3 = cVar4, cVar4 == '\x01')) {
    DAT_ffffcdc0 = 0;
    cVar4 = cVar3;
  }
  else if (0x48 < DAT_ffffcdc4) {
    DAT_ffffcdc0 = 1;
  }
  DAT_ffffcdcc = sVar1;
  return cVar4;
}


