/* [ADDITIONAL SOURCE REVIEW]
 * can212_rx_main [high]: CAN 0x212 RX handler: can_rx_copy_mailbox_to_buffer(&DAT_0004e21c) (mailbox descriptor at ROM 0x4e21c: bytes 00000212 01210700 ffffbbc0 01000000 = ID 0x212, ctrl 0x07 = DLC 7, buffer 0xffffbbc0); on success calls 0xe038, 0x2b7e2 (unpack), 0x2b816 (0xffffbbc8 = 0xffffbbf2), 0x2b8f4 and resets 0xffffbbee/0xffffbbf0; on failure counts 0xffffbbee (every 4th -> 0xffffbbf0) and 0xffffbbc7. 8 calls total.
 * RAM 0xffffbbf0 can212_timeout_counter (uint16): 0x212 RX failure counter incremented in 0x2b29c on mailbox-copy failure (every 4th failure); 0xffffbbd0 = (0x1e < bbf0) timeout flag by 0x2b7c4.
 */
/* ROM address: 0x0002b29c; body bytes: 104; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002b9f0 (104 bytes). Names prefixed ref_
   are inherited hypotheses. */

void can212_rx_main(void)

{
  char cVar1;
  
  cVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004e21c);
  if (cVar1 == '\0') {
    FUN_0000e038();
    can212_rx_unpack();
    candidate_can212_torque_extract();
    FUN_0002b8f4();
    DAT_ffffbbee = 0;
    can212_timeout_counter_ffffbbf0 = 0;
  }
  else {
    DAT_ffffbbee = rx8_add_u16_saturate((int)(short)DAT_ffffbbee,1);
    if ((DAT_ffffbbee & 3) == 0) {
      can212_timeout_counter_ffffbbf0 = rx8_add_u16_saturate((int)can212_timeout_counter_ffffbbf0,1);
    }
    DAT_ffffbbc7 = rx8_add_u8_saturate((int)DAT_ffffbbc7,1);
  }
  return;
}


