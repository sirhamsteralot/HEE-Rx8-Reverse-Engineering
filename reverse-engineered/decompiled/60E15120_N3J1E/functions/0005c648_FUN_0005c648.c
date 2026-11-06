/* [ADDITIONAL SOURCE REVIEW]
 * fan2_diag_override [medium]: UDS actuator-test arbitration for fan 2: DID 0x17c4; result feeds 0x2f1dc's PE4 write.
 */
/* ROM address: 0x0005c648; body bytes: 186; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005ae38 (186 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint candidate_fan2_diag_override(uint param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == 0x17c4) {
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd322 = '\0';
      }
      else {
        DAT_ffffd322 = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd343 = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd322 = '\0';
      }
    }
  }
  if (DAT_ffffd322 == '\0') {
    DAT_ffffd343 = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd322 == '\x05') || (DAT_ffffd322 == '\a')) &&
          (param_1 = 0, DAT_ffffd343 == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


