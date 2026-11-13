/* [ADDITIONAL SOURCE REVIEW]
 * sci0_exchange_byte_wait_rdrf [high]: Renesas SH7055 app note section 2.20 confirms SSR mask 0x40 is receive-data-full (RDRF), the condition polled here; no timeout inside the loop. This idiom also occurs in vendor sample code and is not itself evidence of a bug.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * sci0_exchange_byte_blocking [assembly_verified]: SCI0 transmit/receive with GPIO select at 0xfffff764 bit0. At 0x721e..0x7226 waits for SCI_SSR0 bit0x40 with no software timeout or watchdog service inside the loop. Clock-synchronous configuration comes from caller 0x7188. Not proof of the reported reset; missing external response alone need not prevent internally clocked receive completion.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000071ea; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000071ea (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

int sci0_exchange_byte_wait_rdrf(uint8_t transmit_byte)

{
  byte serial_status;
  char received_byte;
  
  sh_delay_20_nops();
  ref_setRegister_REG_BIT_VAL(0xfffff764,1,0);
  sh_delay_20_nops();
  serial_status = SCI_SSR0_B;
  SCI_SSR0_B = serial_status & 0x87 | 0x80;
  SCI_TDR0_B = transmit_byte;
  serial_status = SCI_SSR0_B;
  SCI_SSR0_B = serial_status & 0x7f | 0x78;
  do {
    serial_status = SCI_SSR0_B;
  } while ((serial_status & RX8_SCI_RDRF) == 0);
  received_byte = SCI_RDR0_B;
  serial_status = SCI_SSR0_B;
  SCI_SSR0_B = serial_status & 0xbf | 0xb8;
  sh_delay_20_nops();
  ref_setRegister_REG_BIT_VAL(0xfffff764,1);
  return (int)received_byte;
}


