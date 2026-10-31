/* [ADDITIONAL SOURCE REVIEW]
 * ssv_diag_override [medium]: UDS actuator-test arbitration for SSV (d314 = -0x16da, d319/d326 state machine, d34b output); feeds ssv_solenoid_control (0x2178c).
 */
/* ROM address: 0x0005c9ac; body bytes: 186; decompiled */

uint candidate_ssv_diag_override(uint param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == -0x16da) {
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd326 = '\0';
      }
      else {
        DAT_ffffd326 = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          DAT_ffffd34b = (char)((ushort)DAT_ffffd316 >> 8);
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd326 = '\0';
      }
    }
  }
  if (DAT_ffffd326 == '\0') {
    DAT_ffffd34b = (param_1 & 0xff) == 1;
  }
  else if (((DAT_ffffd326 == '\x05') || (DAT_ffffd326 == '\a')) &&
          (param_1 = 0, DAT_ffffd34b == '\x01')) {
    param_1 = 1;
  }
  return param_1;
}


