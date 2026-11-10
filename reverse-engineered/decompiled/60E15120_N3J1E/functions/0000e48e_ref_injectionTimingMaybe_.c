/* [ADDITIONAL SOURCE REVIEW]
 * injection_angle_limit_lookup [medium]: a434/a438/a43c = max injection angle 1/2/3 vs RPM (defs 0x68ef8/0x68f0c/0x68f20 'Fuel Injector - Unknown - Max Injection Angle', x2 deg MAYBE).
 * RAM 0xffffa434 max_injection_angle_1 (float): a434 = tbl 0x68ef8(rpm) 'Max Injection Angle1???'.
 * RAM 0xffffa438 max_injection_angle_2 (float): a438 = tbl 0x68f0c(rpm) 'Max Injection Angle2???'.
 * RAM 0xffffa43c max_injection_angle_3 (float): a43c = tbl 0x68f20(rpm) 'Max Injection Angle3???'.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00068ef8: Fuel Injector - Unknown - Max Injection Angle1??? (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00068f0c: Fuel Injector - Unknown - Max Injection Angle2??? (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00068f20: Fuel Injector - Unknown - Max Injection Angle3??? (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0000e48e; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000e492 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

void injection_angle_limit_lookup(void)

{
  max_injection_angle_1_ffffa434 = lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_fuel_injector_unknown_max_injection_angle1_00068ef8);
  max_injection_angle_2_ffffa438 = lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_fuel_injector_unknown_max_injection_angle2_00068f0c);
  max_injection_angle_3_ffffa43c = lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_fuel_injector_unknown_max_injection_angle3_00068f20);
  return;
}


