/* ROM address: 0x000313b8; body bytes: 192; decompiled */

char FUN_000313b8(void)

{
  float fVar1;
  float fVar2;
  
  fVar2 = 0.0;
  if (DAT_ffffae97 == '\0') {
    DAT_ffffbf20 = 0.0;
  }
  else {
    fVar2 = rx8_max_float(DAT_ffffbfa8,DAT_ffffc084 + DAT_ffffb134);
    DAT_ffffbf8c = (float)FUN_00002068(DAT_ffffaa10,&DAT_0006b074);
    fVar1 = rx8_min_float(DAT_ffffbf8c,DAT_ffffb190);
    DAT_ffffbf20 = rx8_clamp_float((fVar2 + fVar1 + 1.0) * DAT_ffffae64 + -1.0,-1.0,2.0);
    fVar2 = rx8_first_order_filter(DAT_ffffbf20,DAT_ffffbf24,0.0625,1e-05);
  }
  if (DAT_ffffb298 == '\x01') {
    fVar2 = fVar2 - 0.0;
  }
  else if (DAT_ffffb298 == '\x02') {
    fVar2 = fVar2 + 0.0;
  }
  DAT_ffffbf24 = fVar2;
  return DAT_ffffb298;
}


