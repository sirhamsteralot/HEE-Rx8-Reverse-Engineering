/* ROM address: 0x0002f2ac; body bytes: 504; decompiled */

uint FUN_0002f2ac(void)

{
  char cVar1;
  uint uVar2;
  undefined4 local_18 [2];
  
  cVar1 = DAT_ffffaa68;
  if (intake_air_temperature_ffffaddc < 40.0) {
    if (intake_air_temperature_ffffaddc < 37.0) {
      DAT_ffffbdad = '\0';
    }
  }
  else {
    DAT_ffffbdad = '\x01';
  }
  if (DAT_ffffccf4 < 32.0) {
    if (DAT_ffffccf4 < 29.0) {
      DAT_ffffbdae = '\0';
    }
  }
  else {
    DAT_ffffbdae = '\x01';
  }
  if (inferred_coolant_temperature_ffffa98c < 85.0) {
    if (inferred_coolant_temperature_ffffa98c < 79.0) {
      DAT_ffffbdaf = '\0';
    }
  }
  else {
    DAT_ffffbdaf = '\x01';
  }
  if (fuel_correction_sum_ffffc644_ffffc644 < 750.0) {
    if (fuel_correction_sum_ffffc644_ffffc644 < 700.0) {
      DAT_ffffbdb0 = '\0';
    }
  }
  else {
    DAT_ffffbdb0 = '\x01';
  }
  if (inferred_coolant_temperature_ffffa98c < 105.0) {
    if (inferred_coolant_temperature_ffffa98c < 99.0) {
      DAT_ffffbdb1 = '\0';
    }
  }
  else {
    DAT_ffffbdb1 = '\x01';
  }
  if (DAT_ffffaa68 == '\x01') {
    DAT_ffffbda4 = 0x493e;
  }
  else if (DAT_ffffbda4 != 0) {
    DAT_ffffbda4 = DAT_ffffbda4 + -1;
  }
  if ((((((DAT_ffffbdad == '\x01') && (DAT_ffffbdae == '\x01')) && (DAT_ffffbdaf == '\x01')) &&
       ((DAT_ffffbdb0 == '\x01' && (DAT_ffffbda4 != 0)))) && (0x24a < DAT_ffffa422)) ||
     (((DAT_ffffbdb1 == '\x01' && (DAT_ffffbda4 != 0)) ||
      ((DAT_ffffa965 == '\x01' && (DAT_ffffbda4 != 0)))))) {
    DAT_ffffbda6 = '\x01';
  }
  else {
    DAT_ffffbda6 = '\0';
  }
  if ((DAT_ffffaa68 == '\x01') || (DAT_ffffbda6 == '\0')) {
    DAT_ffffbda0 = '\0';
  }
  else if (DAT_ffffbdb6 == '\x01') {
    if (DAT_ffffbda6 == '\x01') {
      DAT_ffffbda0 = '\x01';
    }
    else {
      DAT_ffffbda0 = '\0';
    }
  }
  if ((DAT_ffffbdb5 == 0) && (DAT_ffffbda0 == '\x01')) {
    local_18[0] = 0;
    ref_osTaskScheduler(0,2,local_18);
  }
  uVar2 = (uint)DAT_ffffbdb5;
  if ((uVar2 == 1) && (DAT_ffffbda0 == '\0')) {
    local_18[0] = 0;
    uVar2 = ref_osTaskScheduler(0,3,local_18);
  }
  DAT_ffffbdb5 = DAT_ffffbda0;
  DAT_ffffbdb6 = cVar1;
  return uVar2;
}


