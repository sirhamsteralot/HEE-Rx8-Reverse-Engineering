/* [ADDITIONAL SOURCE REVIEW]
 * secondary_air_diag_override [medium]: UDS actuator-test arbitration for the secondary-air solenoid; output feeds secondary_air_solenoid_control (0x187b8).
 */
/* ROM address: 0x0005cf7c; body bytes: 186; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005b76c (186 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint candidate_secondary_air_diag_override(uint param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == -0x16fe) {
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd32c = '\0';
      }
      else {
        DAT_ffffd32c = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd357 = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd32c = '\0';
      }
    }
  }
  if (DAT_ffffd32c == '\0') {
    DAT_ffffd357 = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd32c == '\x05') || (DAT_ffffd32c == '\a')) &&
          (param_1 = 0, DAT_ffffd357 == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


