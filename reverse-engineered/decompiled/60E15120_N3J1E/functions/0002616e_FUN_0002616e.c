/* ROM address: 0x0002616e; body bytes: 392; decompiled */

void FUN_0002616e(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar4 = 2.5;
  fVar5 = -2.5;
  fVar2 = rx8_clamp_float(inferred_ram_b59c_ffffb59c_ffffb59c - DAT_ffffb65c,-2.5,2.5);
  fVar3 = fVar2 - DAT_ffffb5c8;
  DAT_ffffb5c8 = fVar2;
  DAT_ffffb5cc = rx8_clamp_float(fVar3,fVar5,fVar4);
  fVar2 = 0.0;
  if (DAT_ffffb613 == '\x01') {
    DAT_ffffb5a0 = (float)lookup_2d_descriptor_scaled(inferred_alternator_speed_ffffb598,&DAT_0006a54c);
  }
  else {
    DAT_ffffb5a0 = 0.0;
  }
  if ((automatic_transmission_ffffb534 == '\x01') && (DAT_ffffb53a == '\0')) {
    pfVar1 = (float *)&DAT_000749f0;
    DAT_ffffb600 = 406.25;
  }
  else {
    DAT_ffffb600 = 700.0;
    pfVar1 = (float *)&DAT_000749e8;
  }
  DAT_ffffb604 = *pfVar1;
  if (engine_running_timer_ffffa424 == 0) {
    DAT_ffffb5d0 = DAT_ffffb5a0 * 0.5;
  }
  else {
    fVar3 = (float)rx8_divide_with_zero_fallback
                             (engine_speed_rpm_ffffb548 - DAT_ffffb600,DAT_ffffb604 - DAT_ffffb600);
    fVar3 = rx8_clamp_float(fVar3,0.1,1.0);
    DAT_ffffb5d0 = DAT_ffffb5a0 * fVar3;
  }
  fVar4 = DAT_ffffb5c8 * 0.2;
  fVar3 = DAT_ffffb5cc * 0.0;
  if (DAT_ffffb614 == '\x01') {
    DAT_ffffb5d4 = rx8_clamp_float(DAT_ffffb5c8 * 10.0,-125.0,4.8828);
    fVar4 = rx8_clamp_float(fVar4,-0.1,0.0343);
    DAT_ffffb5d8 = rx8_clamp_float(DAT_ffffb5d8 + fVar4,fVar2,DAT_ffffb5a0);
    fVar4 = 249.02;
    fVar5 = -125.0;
  }
  else {
    fVar5 = -125.0;
    DAT_ffffb5d4 = rx8_clamp_float(DAT_ffffb5c8 * 10.0,-125.0,125.0);
    fVar4 = rx8_clamp_float(fVar4,fVar5,125.0);
    DAT_ffffb5d8 = rx8_clamp_float(DAT_ffffb5d8 + fVar4,fVar2,DAT_ffffb5a0);
    fVar4 = 125.0;
  }
  DAT_ffffb5dc = rx8_clamp_float(fVar3,fVar5,fVar4);
  DAT_ffffb5e0 = rx8_clamp_float(DAT_ffffb5d4 + DAT_ffffb5d8 + DAT_ffffb5dc,fVar2,DAT_ffffb5d0);
  return;
}


