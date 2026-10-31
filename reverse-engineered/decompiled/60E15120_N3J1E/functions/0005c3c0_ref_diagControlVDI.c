/* [ADDITIONAL SOURCE REVIEW]
 * vdi_diag_override [medium]: UDS actuator-test arbitration for VDI (d314 = -0x16db); output d33d feeds vdi_solenoid_control (0x34844).
 */
/* ROM address: 0x0005c3c0; body bytes: 186; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005abb0 (186 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint candidate_vdi_diag_override(uint param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == -0x16db) {
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd31f = '\0';
      }
      else {
        DAT_ffffd31f = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd33d = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd31f = '\0';
      }
    }
  }
  if (DAT_ffffd31f == '\0') {
    DAT_ffffd33d = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd31f == '\x05') || (DAT_ffffd31f == '\a')) &&
          (param_1 = 0, DAT_ffffd33d == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


