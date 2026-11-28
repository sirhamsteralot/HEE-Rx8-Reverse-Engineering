/* [ADDITIONAL SOURCE REVIEW]
 * misfire_supply_gate [high]: DAT_ffffb69c = 0 when inferred_battery_voltage 0xffffb590 < 11.0 (float pool 0x75474 = 11.0) or (DAT_ffffb6a4 != 0 && DAT_ffffb6a6 != 0), else 1. Pools verified: 0x27020=0x75474, 0x26ff8=0xb590, 0x2700c=0xffffb6a4, 0x27008=0xffffb6a6. Gates the 400/2000-tick counters and both event arms. Called from 0x287aa.
 * RAM 0xffffb69c misfire_supply_enable (uint8): 0 when battery 0xffffb590 < 11.0 (pool 0x75474) or fault persistence b6a4/b6a6 set, else 1 (0x26fc0). Gates the 400/2000-tick counters 0x28b10/0x28b50, both event arms 0x27fb4/0x28022 and the count-floor lookup 0x4499c.
 */
/* ROM address: 0x00026fc0; body bytes: 50; decompiled */

void misfire_supply_gate(void)

{
  if ((inferred_battery_voltage_ffffb590 < 11.0) || ((DAT_ffffb6a4 != 0 && (DAT_ffffb6a6 != 0)))) {
    misfire_supply_enable_ffffb69c = 0;
  }
  else {
    misfire_supply_enable_ffffb69c = 1;
  }
  return;
}


