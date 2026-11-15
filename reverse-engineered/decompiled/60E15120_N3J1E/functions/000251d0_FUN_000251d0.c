/* [ADDITIONAL SOURCE REVIEW]
 * relay_hold_output_pd11 [high]: Relay-hold output: 0xffffb574 = (0xffffccc1 != 1) (pools 0x25278=0xffffb574, 0x2526c=0xccc1); under SR mask 0xe0 (pool 0x2526e=0xe0, jsr 0x2054 pool 0x2527c=0x2054) drives PDDR_W 0xfffff746 (pool 0x25272=0xf746) bit 0x800 (pool 0x25270=0x800) to (b574 == 1) via 0x4bbc (pool 0x25280=0x4bbc); PD11 high while shutdown is not allowed. Callers 0x22f54 (init fan-out 0x1102a) and 0x22f86 (slow task). Chip-pin -> connector-terminal routing is board-level unresolved (D2): candidates main relay control 4E / DBW relay control 4C per pinout v3.
 * RAM 0xffffb574 relay_hold_flag (uint8): = (0xffffccc1 != 1); drives PDDR_W 0xfffff746 bit 0x800 (PD11 relay-hold output) via 0x251d0 (pool 0x25278=0xffffb574).
 */
/* ROM address: 0x000251d0; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025a58 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

void relay_hold_output_pd11(void)

{
  undefined4 local_c [2];
  
  relay_hold_flag_ffffb574 = shutdown_allowed_ffffccc1 != '\x01';
  ref_setSR_PARAM(local_c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff746,0x800,relay_hold_flag_ffffb574 == '\x01');
  FUN_00002064(local_c[0]);
  return;
}


