/* [ADDITIONAL SOURCE REVIEW]
 * vfad_diag_override [medium]: UDS actuator-test arbitration for VFAD (d314 = 0x17c8); output d353 feeds vfad_solenoid_control (0x3493c).
 */
/* ROM address: 0x0005cdc4; body bytes: 186; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005b5b4 (186 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint candidate_vfad_diag_override(uint param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == 0x17c8) {
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd32a = '\0';
      }
      else {
        DAT_ffffd32a = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd353 = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd32a = '\0';
      }
    }
  }
  if (DAT_ffffd32a == '\0') {
    DAT_ffffd353 = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd32a == '\x05') || (DAT_ffffd32a == '\a')) &&
          (param_1 = 0, DAT_ffffd353 == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


