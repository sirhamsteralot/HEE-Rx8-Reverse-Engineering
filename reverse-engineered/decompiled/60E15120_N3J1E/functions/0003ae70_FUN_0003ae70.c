/* ROM address: 0x0003ae70; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003b2a4 (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_0003ae70(void)

{
  ushort uVar1;
  
  uVar1 = PADR_W;
  DAT_ffffd18c = (uVar1 & 0x800) != 0;
  if ((DAT_ffffd18d == '\0') && (DAT_ffffd18c)) {
    DAT_ffffc583 = 1;
  }
  else {
    DAT_ffffc583 = 0;
  }
  DAT_ffffd18d = DAT_ffffd18c;
  return DAT_ffffd18c;
}


