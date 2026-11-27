/* [ADDITIONAL SOURCE REVIEW]
 * immo_can_rx_main [high]: ref_CAN47RX_Main (unique_exact_bytes to 60E0FC00 0x3883c), called from can_rx_main_key_gated 0xdbf6. Copies HCAN1 mailbox 39 (CAN 0x047, descriptor ROM 0x4e26c) into buffer 0xffffc4b0 via can_rx_copy_mailbox_to_buffer, runs unpack 0x38150 + 0x3818a + 0x38194, sets c4bf=1, c4c0=1.
 * RAM 0xffffc4b0 can047_rx_raw_buffer (u8[8]): filled by can_rx_copy_mailbox_to_buffer from HCAN1 mb39 (descriptor ROM 0x4e26c); ROM descriptor bytes re-read: id 0x047, buf 0xffffc4b0
 * RAM 0xffffc4bf immo_rx_command_pending (u8): pool word 0x356b6=0xc4bf at 0x355f2
 */
/* ROM address: 0x0003811c; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003883c (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint immo_can_rx_main(void)

{
  uint uVar1;
  
  uVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004e26c);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 0) {
    FUN_0000e050();
    immo_can_rx_unpack();
    FUN_0003818a();
    uVar1 = FUN_00038194();
    immo_rx_command_pending_ffffc4bf = 1;
    DAT_ffffc4c0 = 1;
  }
  return uVar1;
}


