/* [CROSS-ECU / RX8DEFS REVIEW]
 * sh_delay_20_nops [assembly_verified]: 20 NOP instructions before RTS, plus one delay-slot NOP. Raw C returns immediately because timing has no C-level side effect; preserve this distinction when analyzing peripheral timing.
 */
/* ROM address: 0x00004c14; body bytes: 44; decompiled */

void sh_delay_20_nops(void)

{
  return;
}


