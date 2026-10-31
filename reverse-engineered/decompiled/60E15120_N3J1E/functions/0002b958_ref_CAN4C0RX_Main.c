/* ROM address: 0x0002b958; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002c0ac (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_CAN4C0RX_Main(void)

{
  uint uVar1;
  
  uVar1 = can_rx_copy_mailbox_to_buffer(&DAT_0004e25c);
  if ((uVar1 & 0xff) == 0) {
    FUN_0000e038();
    FUN_0002b97e();
    uVar1 = FUN_0002b988();
    return uVar1;
  }
  return uVar1 & 0xff;
}


