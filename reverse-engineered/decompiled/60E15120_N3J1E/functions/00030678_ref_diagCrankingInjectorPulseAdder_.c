/* [ADDITIONAL SOURCE REVIEW]
 * cranking_pulse_adder [high]: Adds the cranking pulse into an accumulator only while the engine is not running: byte 0xffffa428 == 0 (pool 0x306b2, tst at 0x3067c), byte 0xffffa42c == 1 (pool 0x306b4, cmp/eq at 0x30688) and byte 0xffffce32 == 1 (pool 0x306b6, cmp/eq at 0x30694); then float 0xffffbe94 (pool 0x306ac) = 0xffffbe94 + 0xffffbe58 (pool 0x306b8) at 0x3069e-0x306a4. The accumulated value is read only by the 1e7 threshold test in 0x30468 (pool 0x306d8 = f32 0x77f70, fcmp/gt at 0x305fe).
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


