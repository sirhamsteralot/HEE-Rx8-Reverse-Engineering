/* [ADDITIONAL SOURCE REVIEW]
 * injector_latency_cal_lookup [high]: be40 = 3D tbl 0x6aa64 'Injector Latency Secondary'(MRP be04/be08, battery V b590); be44 = 3D tbl 0x6aa80 'Injector Latency Primary'; quantized /0.25 to int -> set_fuel_injector_latency(0, secondary), (1, primary), (2, primary).
 * RAM 0xffffbe40 injector_latency_secondary (float): be40 = 3D tbl 0x6aa64 'Injector Latency Secondary'(MRP, battery V), quantized /0.25; added to pulse times in 0x2fea8.
 * RAM 0xffffbe44 injector_latency_primary (float): be44 = 3D tbl 0x6aa80 'Injector Latency Primary'(MRP, battery V), quantized /0.25.
 */
/* ROM address: 0x0002ff78; body bytes: 146; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00030414 (146 bytes). Names prefixed ref_
   are inherited hypotheses. */

void injector_latency_cal_lookup(void)

{
  int iVar1;
  int iVar2;
  
  injector_latency_secondary_ffffbe40 = (float)lookup_3d_descriptor_scaled(inferred_manifold_relative_pressure_ffffbe04,inferred_battery_voltage_ffffb590,&tbl_injector_latency_secondary_0006aa64);
  injector_latency_primary_ffffbe44 = (float)lookup_3d_descriptor_scaled(inferred_manifold_relative_pressure_ffffbe08,inferred_battery_voltage_ffffb590,&tbl_injector_latency_primary_0006aa80);
  iVar2 = 0x7fffffff;
  iVar1 = iVar2;
  if (injector_latency_secondary_ffffbe40 < 5.3687088e+08) {
    if (0.0 < injector_latency_secondary_ffffbe40) {
      iVar1 = (int)(injector_latency_secondary_ffffbe40 / 0.25);
    }
    else {
      iVar1 = 0;
    }
  }
  if (injector_latency_primary_ffffbe44 < 5.3687088e+08) {
    if (0.0 < injector_latency_primary_ffffbe44) {
      iVar2 = (int)(injector_latency_primary_ffffbe44 / 0.25);
    }
    else {
      iVar2 = 0;
    }
  }
  set_fuel_injector_latency(0,iVar1);
  set_fuel_injector_latency(1,iVar2);
  set_fuel_injector_latency(2,iVar2);
  return;
}


