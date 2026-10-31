/* ROM address: 0x0004bd48; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004af00 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_CAN4B1RX_Main(void)

{
  uint uVar1;
  
  uVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004dfdc);
  if ((uVar1 & 0xff) == 0) {
    FUN_0000e038();
    ref_can4B1RXUnpack();
    uVar1 = FUN_0004bda2();
    return uVar1;
  }
  return uVar1 & 0xff;
}


