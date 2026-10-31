/* ROM address: 0x00032d24; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00033040 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_CAN430RX_Main(void)

{
  uint uVar1;
  
  uVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004e23c);
  if ((uVar1 & 0xff) == 0) {
    FUN_0000e048();
    ref_can430rx_unpack();
    FUN_00032d7c();
    uVar1 = FUN_00032d96();
    return uVar1;
  }
  return uVar1 & 0xff;
}


