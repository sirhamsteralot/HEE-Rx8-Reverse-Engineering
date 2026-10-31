/* ROM address: 0x0003c806; body bytes: 208; decompiled */

char FUN_0003c806(void)

{
  char cVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc5e1 = 0;
    DAT_ffffc5e2 = 0;
    DAT_ffffc5da = 'u';
    cVar1 = '\x01';
  }
  else {
    if ((((intake_air_temperature_ffffaddc - inferred_coolant_temperature_ffffa98c <= 1000.0) || (DAT_ffffc5db == '\x01')) ||
        (DAT_ffffc5e6 == '\x01')) || (DAT_ffffd1ad == '\x01')) {
      DAT_ffffc5da = 'u';
      cVar1 = '\0';
    }
    else {
      cVar1 = '\x01';
    }
    if ((cVar1 == '\x01') && (DAT_ffffc5da == '\0')) {
      cVar1 = ref_getFaultStatus__(0xe);
      if (cVar1 == '\0') {
        DAT_ffffc5e1 = 1;
        DAT_ffffc5e2 = 0;
      }
    }
    else if ((20.0 < inferred_coolant_temperature_ffffa98c - intake_air_temperature_ffffaddc) &&
            ((DAT_ffffc5db == '\0' && (DAT_ffffc5e6 == '\0')))) {
      cVar1 = ref_getFaultStatus__(0xe);
      if (cVar1 == '\0') {
        DAT_ffffc5e2 = 1;
        DAT_ffffc5e1 = 0;
      }
    }
  }
  return cVar1;
}


