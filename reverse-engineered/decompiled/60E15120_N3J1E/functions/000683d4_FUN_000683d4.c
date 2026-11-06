/* [ADDITIONAL SOURCE REVIEW]
 * isotp_pci_type_extract [high]: reads RX buffer byte0, and 0xf0 -> frame type 0x00/0x10/0x20/0x30, clamp 0x40
 */
/* ROM address: 0x000683d4; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066cc4 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint isotp_pci_type_extract(void)

{
  uint uVar1;
  
  uVar1 = (int)uds_rx_buffer_ffffddc8 & 0xf0;
  if (0x3f < uVar1) {
    uVar1 = 0x40;
  }
  return uVar1;
}


