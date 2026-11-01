/* ROM address: 0x00030a80; body bytes: 164; decompiled */

void injector_pulse_time_arbitrate(void)

{
  float fVar1;
  char cVar2;
  
  cVar2 = DAT_ffffa428;
  if (DAT_ffffa428 == '\0') {
    DAT_ffffbea8 = FUN_000020ac(DAT_ffffaa10,&DAT_0006be20);
  }
  else if (DAT_ffffbea8 != '\0') {
    DAT_ffffbea8 = DAT_ffffbea8 + -1;
  }
  if ((cVar2 == '\0') || (DAT_ffffbea8 != '\0')) {
    DAT_ffffbe9c = DAT_ffffbec8 + DAT_ffffbeb0;
    DAT_ffffbea4 = DAT_ffffbe9c;
    fVar1 = DAT_ffffbec4;
  }
  else {
    DAT_ffffbe9c = DAT_ffffbebc + DAT_ffffbeb0;
    DAT_ffffbea4 = DAT_ffffbec0 + DAT_ffffbeb0;
    fVar1 = DAT_ffffbeb8;
  }
  DAT_ffffbe94 = fVar1 + DAT_ffffbeac;
  DAT_ffffbe90 = DAT_ffffbe94;
  DAT_ffffbe98 = DAT_ffffbe9c;
  DAT_ffffbea0 = DAT_ffffbea4;
  return;
}


