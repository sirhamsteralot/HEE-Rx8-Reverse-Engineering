/* [ADDITIONAL SOURCE REVIEW]
 * can212_torque_extract [medium]: 0xffffbbc8 = 0xffffbbf2 (torque-related signal from the 0x212 payload); called from 0x2b29c.
 * RAM 0xffffbbc8 can212_torque_signal (uint8): Torque-related signal from CAN 0x212 (0x2b816: bbc8 = bbf2); decoded with affine step 0x3ec99326 in 0x2b3b8/0x2b496 for the max-torque-allowed calc.
 */
/* ROM address: 0x0002b816; body bytes: 170; decompiled */

uint candidate_can212_torque_extract(void)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = DAT_ffffbbf2 == -1;
  if (!bVar2) {
    can212_torque_signal_ffffbbc8 = DAT_ffffbbf2;
  }
  if (DAT_ffffbbf3 == -1) {
    bVar2 = true;
  }
  else if (engine_running_ffffa428 == '\x01') {
    DAT_ffffbbc9 = DAT_ffffbbf3;
  }
  if (DAT_ffffbbf4 == -1) {
    bVar2 = true;
  }
  else if ((((DAT_ffffbb24 == '\0') && (engine_running_ffffa428 == '\x01')) && (can_error_latch_ffffa40a == '\0')) &&
          (DAT_ffffa401 == '\0')) {
    DAT_ffffbbca = DAT_ffffbbf4;
  }
  uVar1 = (uint)bVar2;
  if (uVar1 == 1) {
    uVar1 = rx8_add_u8_saturate((int)DAT_ffffbbc7,1);
    DAT_ffffbbc7 = (char)uVar1;
  }
  else {
    DAT_ffffbbc7 = 0;
  }
  return uVar1;
}


