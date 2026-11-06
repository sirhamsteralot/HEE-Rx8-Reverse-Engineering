/* [ADDITIONAL SOURCE REVIEW]
 * fan1_diag_override [medium]: UDS actuator-test arbitration for fan 1: DID 0x17c3 (mask 0xc0 on 0xffffd36c, state 0xffffd319/0xffffd323, output cell 0xffffd345); result feeds 0x2f1dc's PE11 write.
 */
/* ROM address: 0x0005c724; body bytes: 186; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005af14 (186 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint candidate_fan1_diag_override(uint param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == 0x17c3) {
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd323 = '\0';
      }
      else {
        DAT_ffffd323 = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd345 = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd323 = '\0';
      }
    }
  }
  if (DAT_ffffd323 == '\0') {
    DAT_ffffd345 = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd323 == '\x05') || (DAT_ffffd323 == '\a')) &&
          (param_1 = 0, DAT_ffffd345 == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


