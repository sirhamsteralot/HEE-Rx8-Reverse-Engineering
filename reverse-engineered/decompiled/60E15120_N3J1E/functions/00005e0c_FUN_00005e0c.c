/* [ADDITIONAL SOURCE REVIEW]
 * wdt_iti_fatal_trap [high]: WDT overflow ITI (IVT 0x358 -> trampoline 0x30b8): calls 0x5348(0xd6) - deliberate halt; WDT is serviced by polling (0x31c), OVF is flag-only (E3).
 */
/* ROM address: 0x00005e0c; body bytes: 6; decompiled */

void wdt_iti_fatal_trap(void)

{
  fatal_interrupt_trap(0xd6);
  return;
}


