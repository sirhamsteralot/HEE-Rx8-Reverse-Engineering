/* ROM address: 0x0001eaa8; body bytes: 82; decompiled */

undefined4 * cold_start_enrichment(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_r0;
  
  if (DAT_ffffa428 == '\0') {
    puVar1 = &DAT_ffffaa10;
    if ((DAT_ffffaa10 < 0.0) || (DAT_ffffae54 < 0.0)) {
      DAT_ffffb134 = 0.0;
    }
    else {
      DAT_ffffb134 = 0.0;
    }
  }
  else {
    DAT_ffffb134 = rx8_max_float(DAT_ffffb134 - 0.0,0.0);
    puVar1 = extraout_r0;
  }
  return puVar1;
}


