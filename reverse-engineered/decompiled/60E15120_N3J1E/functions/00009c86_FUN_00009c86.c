/* [ADDITIONAL SOURCE REVIEW]
 * can_rx_isr_handler [high]: CAN RX IVT 0x378 -> trampoline 0x31c0 -> 0x5e78 thunk -> 0x9c86; dynamic trace: 0x9c86 calls 0x9630(1,12,0xffff7394) (grp1 rec[12] target -1 -> inline 0x11d88 CAN poll) which moved injected 0x7e0 frame into UDS buffer 0xffffddc8.
 */
/* ROM address: 0x00009c86; body bytes: 8; decompiled */

void can_rx_isr_handler(void)

{
  FUN_0000a186(0);
  return;
}


