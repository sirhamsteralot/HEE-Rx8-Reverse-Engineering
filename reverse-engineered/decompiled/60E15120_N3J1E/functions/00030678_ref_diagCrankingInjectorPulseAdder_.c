/* [ADDITIONAL SOURCE REVIEW]
 * cranking_pulse_adder [high]: When cranking && injectors off (a42c) && ce32: be94 += be58 (cranking pulse adder accumulated into pulse arbitration).
 * RAM 0xffffbe58 injector_pulse_crank (float): Cranking pulse base; added into be94 by cranking_pulse_adder (0x30678) and into be28 by 0x2fea8.
 * RAM 0xffffbe94 cranking_pulse_adder (float): be94 += be58 when cranking && injectors off && ce32 (diag cranking pulse adder).
 */
/* ROM address: 0x00030678; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00030b14 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

void cranking_pulse_adder(void)

{
  if (((engine_running_ffffa428 == '\0') && (engine_injectors_off_ffffa42c == '\x01')) && (inferred_ram_ce32_ffffce32_ffffce32 == '\x01')) {
    cranking_pulse_adder_ffffbe94 = injector_pulse_crank_ffffbe58 + cranking_pulse_adder_ffffbe94;
  }
  return;
}


