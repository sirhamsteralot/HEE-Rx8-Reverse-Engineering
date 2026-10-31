/* ROM address: 0x0000de46; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000de46 (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000de46(void)

{
  if (10.0 <= inferred_battery_voltage_ffffb590) {
    if (DAT_ffffa400 != '\0') {
      DAT_ffffa400 = DAT_ffffa400 + -1;
    }
  }
  else {
    DAT_ffffa400 = '/';
  }
  return;
}


