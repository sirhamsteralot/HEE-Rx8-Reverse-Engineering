/* ROM address: 0x0004737a; body bytes: 258; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00046406 (140 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_fuelCutSomethingSomething(char param_1)

{
  char cVar1;
  char *pcVar2;
  
  if (((DAT_ffffcc9f == '\0') || (DAT_ffffcc71 == '\x01')) || (candidate_idle_learn_flag_ffffcc91 < 3)) {
    DAT_ffffcc70 = '\0';
  }
  else {
    if (((DAT_ffffcc9e == '\x01') && (DAT_ffffbcd8 == '\x01')) ||
       ((DAT_ffffcc9e == '\x01' &&
        (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8738,0), cVar1 == '\x01')))) {
      pcVar2 = "";
    }
    else {
      if (inferred_ram_ad18_ffffad18_ffffad18 != '\x01') {
        DAT_ffffcc70 = '\0';
        goto LAB_00047406;
      }
      pcVar2 = "";
    }
    DAT_ffffcc70 = *pcVar2;
  }
LAB_00047406:
  if (param_1 != '\0') {
    if (param_1 == '\f') {
      ref_setPerRotorLevel1FuelCut((int)DAT_ffffcc75);
    }
    goto LAB_000474a0;
  }
  if (DAT_ffffcc70 == '\x01') {
    DAT_ffffcc74 = '\x01';
    DAT_ffffcc75 = '\0';
  }
  else {
    if (DAT_ffffcc70 == '\x02') {
      DAT_ffffcc74 = '\x01';
    }
    else {
      if (DAT_ffffcc70 != '\x03') {
        if (DAT_ffffcc70 == '\x04') {
          DAT_ffffcc74 = '\x03';
          DAT_ffffcc75 = '\x03';
        }
        else if (DAT_ffffcc70 == '\0') {
          DAT_ffffcc74 = '\0';
          DAT_ffffcc75 = '\0';
        }
        goto LAB_0004748c;
      }
      DAT_ffffcc74 = '\x03';
    }
    DAT_ffffcc75 = '\x01';
  }
LAB_0004748c:
  ref_setPerRotorLevel1FuelCut((int)DAT_ffffcc74);
LAB_000474a0:
  FUN_0000e2d4(1);
  return;
}


