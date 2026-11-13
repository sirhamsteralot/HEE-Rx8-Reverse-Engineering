/* [ADDITIONAL SOURCE REVIEW]
 * can_rx_poll_move_to_uds_buffer [high]: Emulator dynamic: after can.inject(0x7e0, 02 10 03 ...) raises IVT 0x378, a plain emu.run executes 0x11d88 which calls 0x9c8e/0xce24 (pending = byteswap(~MBIMR & RXPR)), ref_placeCANRX(0x4dffc) copies MD14 into 0xffffddc8 (observed 02100300), clears RXPR; with latch vehicle_inputs_pfdr_latch_ffff9ec8 bit0 set it tail-calls 0x680a0(0x7e0).
 * RAM 0xffffddc8 uds_rx_buffer (uint8[8]): CAN RX buffer; descriptors 0x4dfec (id 0x7df, mb 13) and 0x4dffc (id 0x7e0, mb 14) hold buf=0xffffddc8 at ROM 0x4dff4/0x4e004; descriptor table base 0x4df1c pool-loaded at 0x11da0 in 0x11d88; also mov.l pools 0x68428/0x68660/0x688c8 in the ISO-TP RX path 0x683d4-0x6872c.
 */
/* ROM address: 0x00011d88; body bytes: 256; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00011e00 (256 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint can_rx_poll_move_to_uds_buffer(void)

{
  uint uVar1;
  char cVar3;
  uint uVar2;
  
  if ((vehicle_inputs_pfdr_latch_ffff9ec8 & 1) == 0) {
    uVar1 = can_rx_pending_check(0);
    if (uVar1 != 0) {
      if ((uVar1 & 0x2000) == 0) {
        if ((uVar1 & 0x4000) != 0) {
          uVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004dffc);
        }
      }
      else {
        uVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004dfec);
      }
    }
  }
  else {
    uVar1 = can_rx_pending_check(0);
    if (uVar1 != 0) {
      if ((uVar1 & 0x2000) == 0) {
        if ((uVar1 & 0x4000) != 0) {
          cVar3 = can_rx_copy_mailbox_to_buffer();
          uVar2 = FUN_00009c34(&DAT_0004dffc);
          uVar1 = (uint)cVar3;
          if ((uVar1 == 0) && (uVar1 = uVar2 & 0xff, uVar1 == 8)) {
            uVar1 = uds_service_entry(0x7e0);
            return uVar1;
          }
        }
      }
      else {
        cVar3 = can_rx_copy_mailbox_to_buffer();
        uVar2 = FUN_00009c34(&DAT_0004dfec);
        uVar1 = (uint)cVar3;
        if ((uVar1 == 0) && (uVar1 = uVar2 & 0xff, uVar1 == 8)) {
          uVar1 = uds_service_entry(0x7df);
          return uVar1;
        }
      }
    }
  }
  return uVar1;
}


