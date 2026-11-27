/* [ADDITIONAL SOURCE REVIEW]
 * immo_can_rx_unpack [high]: ref_can47RXunpack (unique_exact_bytes to 60E0FC00 0x38870). c4b9=c4b0 (command), c4ba..c4be=c4b1..c4b5, c4c4=BE16(c4b6,c4b7) checksum. Frame layout: [cmd][d0][d1][d2][d3][d4][chkH][chkL].
 * RAM 0xffffc4b9 immo_rx_command (u8): commands 0/6/8/0x90/0xc9 verified in emulator
 * RAM 0xffffc4ba immo_rx_data (u8[4] c4ba-c4bd): c4bb is the cmd-6 sub-status (0xff check, pool 0x356c2=0x00ff)
 */
/* ROM address: 0x00038150; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00038870 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

void immo_can_rx_unpack(void)

{
  immo_rx_command_ffffc4b9 = can047_rx_raw_buffer_ffffc4b0;
  immo_rx_data_ffffc4ba = DAT_ffffc4b1;
  DAT_ffffc4bb = DAT_ffffc4b2;
  DAT_ffffc4bc = DAT_ffffc4b3;
  DAT_ffffc4bd = DAT_ffffc4b4;
  DAT_ffffc4be = DAT_ffffc4b5;
  DAT_ffffc4c4 = (ushort)DAT_ffffc4b6 * 0x100 + (ushort)DAT_ffffc4b7;
  return;
}


