/* [ADDITIONAL SOURCE REVIEW]
 * alternator_warning_light_flag [medium]: 0xffffb5b4 = 1 when (b613==0 || b5b0==1 || b5b1==1 || b5b2==1 || 0xffffc5db==1). Flag is exported, not GPIO-driven from here: read by 0x28c78 (packed into CAN status word 0xffffbab2 bit 0x40 via pool 0x28d70 at 0x28cfe) and by Mode 22 PID 0x0968 handler 0x57138 (pool 0x5717e). Called from 0x2680e via pool 0x268c8.
 */
/* ROM address: 0x00026760; body bytes: 74; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00027084 (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_alternator_warning_light_flag(void)

{
  if ((((DAT_ffffb613 == '\0') || (DAT_ffffb5b0 == '\x01')) || (charging_ok_latch_ffffb5b1 == '\x01')) ||
     ((low_voltage_latch_ffffb5b2 == '\x01' || (DAT_ffffc5db == '\x01')))) {
    inferred_ram_b5b4_ffffb5b4_ffffb5b4 = 1;
  }
  else {
    inferred_ram_b5b4_ffffb5b4_ffffb5b4 = 0;
  }
  return;
}


