/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffaddc intake_air_temperature (float): Working copy of intake_air_temperature_ffff9f60 (0x1be00/0x1be4a; fault default 20.0 C at 0x1be54); Kelvin conversion 295/(x+273) at 0x1a086.
 */
/* ROM address: 0x0001a086; body bytes: 182; decompiled */

undefined1 * FUN_0001a086(void)

{
  undefined1 *puVar1;
  undefined1 *extraout_r0;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar2 = maf_scaled_latched_ffffa9e8;
  fVar4 = (float)(&DAT_ffffaa10)[DAT_ffffaa34];
  fVar5 = (float)(&DAT_ffffa9f8)[DAT_ffffaa34];
  (&DAT_ffffa9f8)[DAT_ffffaa34] = maf_scaled_latched_ffffa9e8;
  (&DAT_ffffaa10)[DAT_ffffaa34] = fVar2;
  DAT_ffffa9f4 = mass_air_flow_ffffa9ec;
  puVar1 = &DAT_ffffc590;
  if (DAT_ffffc590 == '\0') {
    fVar2 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&PTR_DAT_00069794);
    DAT_ffffaa30 = fVar2;
    fVar3 = (float)rx8_divide_with_zero_fallback(0x43928000,intake_air_temperature_ffffaddc + 273.0);
    DAT_ffffa9f0 = fVar2 * fVar3 * (inferred_barometric_pressure_ffffad14 / 101.33299);
    mass_air_flow_ffffa9ec = rx8_min_float((fVar5 + fVar4) * 0.5,DAT_ffffa9f0);
    puVar1 = extraout_r0;
  }
  else {
    mass_air_flow_ffffa9ec = DAT_ffffaa28;
  }
  if (DAT_ffffaa34 < 5) {
    DAT_ffffaa34 = DAT_ffffaa34 + 1;
  }
  else {
    puVar1 = (undefined1 *)0x0;
    DAT_ffffaa34 = '\0';
  }
  return puVar1;
}


