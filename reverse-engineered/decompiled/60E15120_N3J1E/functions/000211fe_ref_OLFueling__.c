/* [ADDITIONAL SOURCE REVIEW]
 * fueling_condition_flags_task [high]: Task 0x64f6 -> 0x11744 chain under mask 0x10: load/RPM band flags 0x1ff38, throttle/load band flags 0x1f6ae, 0x1fd48, blend_weight_update (0x200c6), off-throttle fuel-cut resume base 0xe560 (tbl 0x68f48), 0x3133c (tbl 0x6aca4), calculate_air_charge (0x314d0), secondary-air enrichment (0x31624), injector_temp_multiplier_lookup (0x2fd3e).
 */
/* ROM address: 0x000211fe; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00021b6a (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

void fueling_condition_flags_task(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0001ff38();
  FUN_0001f6ae();
  FUN_0001fd48();
  blend_weight_update();
  FUN_0000e560();
  FUN_0003133c();
  calculate_air_charge();
  ref_calculateSecondaryAirPumpEnirchment();
  injector_temp_multiplier_lookup();
  ref_setSR(uVar1);
  return;
}


