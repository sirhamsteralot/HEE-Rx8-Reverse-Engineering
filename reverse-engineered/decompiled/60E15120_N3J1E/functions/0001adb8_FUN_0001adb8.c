/* ROM address: 0x0001adb8; body bytes: 114; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001b868 (114 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0001adb8(undefined1 param_1)

{
  char cVar1;
  
  if (DAT_ffffbd48 == '\x01') {
    param_1 = (vehicle_inputs_pfdr_latch_ffff9ec8 & 0x20) != 0;
    if (param_1 != DAT_ffffad1a) {
      DAT_ffffad19 = '\x04';
    }
    cVar1 = param_1;
    if (DAT_ffffad19 == '\0') {
      if ((bool)param_1) {
        inferred_ram_ad18_ffffad18_ffffad18 = 1;
      }
      else if (!(bool)param_1) {
        inferred_ram_ad18_ffffad18_ffffad18 = 0;
      }
    }
    else {
      DAT_ffffad19 = DAT_ffffad19 + -1;
    }
  }
  else {
    inferred_ram_ad18_ffffad18_ffffad18 = DAT_ffffbbcf;
    cVar1 = DAT_ffffbd48;
  }
  DAT_ffffad1a = param_1;
  return cVar1;
}


