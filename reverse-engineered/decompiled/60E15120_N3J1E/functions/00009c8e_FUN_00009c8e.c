/* [ADDITIONAL SOURCE REVIEW]
 * can_rx_pending_check [high]: Wrapper: r0 = 0xce24(0); called at 0x11dba/0x11e4c in the CAN RX poll.
 */
/* ROM address: 0x00009c8e; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009c8e (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 can_rx_pending_check(void)

{
  undefined4 uVar1;
  
  uVar1 = can_rx_pending_bits();
  return uVar1;
}


