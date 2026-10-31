/* ROM address: 0x000415e4; body bytes: 74; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00040e18 (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000415e4(void)

{
  char cVar1;
  
  cVar1 = ref_getFaultStatus__(3);
  if ((((cVar1 != '\0') || (cVar1 = ref_getFaultStatus__(4), cVar1 != '\0')) ||
      (inferred_battery_voltage_ffffb590 <= 10.0)) || (DAT_ffffd1c5 != '\0')) {
    DAT_ffffc910 = 0;
  }
  else {
    DAT_ffffc910 = 1;
  }
  return 0;
}


