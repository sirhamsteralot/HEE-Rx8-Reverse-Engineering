/* ROM address: 0x0003811c; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003883c (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_CAN47RX_Main(void)

{
  uint uVar1;
  
  uVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004e26c);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 0) {
    FUN_0000e050();
    ref_can47RXunpack();
    FUN_0003818a();
    uVar1 = FUN_00038194();
    DAT_ffffc4bf = 1;
    DAT_ffffc4c0 = 1;
  }
  return uVar1;
}


