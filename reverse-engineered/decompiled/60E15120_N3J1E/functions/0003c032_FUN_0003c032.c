/* ROM address: 0x0003c032; body bytes: 124; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003c466 (124 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0003c032(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc5c5 = 0;
    DAT_ffffc5c6 = 0;
  }
  else {
    uVar1 = ref_getFromGPIO_(2);
    if ((uVar1 & 0x80) == 0) {
      DAT_ffffc5c4 = 0xf;
      DAT_ffffc5c5 = 0;
      DAT_ffffc5c6 = 1;
      return '\x01';
    }
    if (DAT_ffffd1ad != '\x01') {
      if (DAT_ffffc5c4 != '\0') {
        DAT_ffffc5c4 = DAT_ffffc5c4 + -1;
        return DAT_ffffd1ad;
      }
      DAT_ffffc5c5 = 1;
      DAT_ffffc5c6 = 0;
      return DAT_ffffd1ad;
    }
  }
  DAT_ffffc5c4 = 0xf;
  return '\x01';
}


