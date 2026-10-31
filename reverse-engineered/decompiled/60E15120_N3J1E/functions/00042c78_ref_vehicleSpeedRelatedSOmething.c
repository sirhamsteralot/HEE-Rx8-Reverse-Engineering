/* ROM address: 0x00042c78; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000424ac (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * ref_vehicleSpeedRelatedSOmething(void)

{
  undefined4 *puVar1;
  
  if (DAT_ffffbfa0 < 400.0) {
    puVar1 = &DAT_00042cf0;
    if (DAT_ffffbfa0 <= 0.0) {
      DAT_ffffca30 = 1.0;
    }
    else {
      DAT_ffffca30 = DAT_ffffbfa0 * 34.7416;
    }
  }
  else {
    puVar1 = &DAT_00042cf4;
    DAT_ffffca30 = 10000.0;
  }
  return puVar1;
}


