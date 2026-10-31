/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffa748 knock_seen_counter (uint16): Incremented by 0x1391c on knock-seen events (called from 0x145c8).
 * RAM 0xffffc150 engine_load_delta (float): |load - c188| (engine load delta) from 0x34364; c154 holds the signed delta.
 */
/* ROM address: 0x0001391c; body bytes: 168; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00013760 (168 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_calcKnockRAMUpdate_(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(uint)knock_active_ffffa73c;
  if ((((((puVar1 != (undefined4 *)0x1) || (inferred_coolant_temperature_ffffa98c < 140.0)) || (150.0 <= inferred_coolant_temperature_ffffa98c)) ||
       ((intake_air_temperature_ffffaddc < 40.0 || (100.0 <= intake_air_temperature_ffffaddc)))) ||
      ((engine_speed_rpm_ffffb548 < 500.0 || ((4600.0 <= engine_speed_rpm_ffffb548 || (engine_load_ffffc0b4 < 0.5)))))) ||
     ((1.125 <= engine_load_ffffc0b4 || (puVar1 = &engine_load_delta_ffffc150, 0.065 < engine_load_delta_ffffc150)))) {
    knock_seen_learn_trigger_ffffa73f = 0;
    knock_seen_counter_ffffa748 = 0;
  }
  else {
    if (0xf9 < knock_seen_counter_ffffa748) {
      knock_seen_learn_trigger_ffffa73f = 1;
    }
    puVar1 = (undefined4 *)rx8_add_u16_saturate((int)(short)knock_seen_counter_ffffa748,1);
    knock_seen_counter_ffffa748 = (ushort)puVar1;
  }
  return puVar1;
}


