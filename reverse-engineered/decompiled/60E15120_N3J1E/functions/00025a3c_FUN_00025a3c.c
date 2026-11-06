/* [ADDITIONAL SOURCE REVIEW]
 * overvoltage_flags [medium]: 0xffffb612 = 1 when 0xffffb654 >= 18.471 (pool 0x74978/0x74988) or 0xffffb658 >= 15.938 (pool 0x7497c/0x7498c). Called from 0x267c6 via pool 0x26890.
 */
/* ROM address: 0x00025a3c; body bytes: 44; decompiled */

void candidate_overvoltage_flags(void)

{
  if ((18.471 <= inferred_ram_b654_ffffb654_ffffb654) || (15.938 <= system_voltage_alt_ffffb658)) {
    DAT_ffffb612 = 1;
  }
  else {
    DAT_ffffb612 = 0;
  }
  return;
}


