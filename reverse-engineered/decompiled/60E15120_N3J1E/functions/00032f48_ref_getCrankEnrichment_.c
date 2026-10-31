/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ae90: Table 2D - 200 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006aea4: Table 2D - 201 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00032f48; body bytes: 170; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00033264 (170 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_getCrankEnrichment_(void)

{
  char cVar2;
  undefined4 extraout_r0;
  undefined4 uVar1;
  float fVar3;
  float fVar4;
  float arg0;
  
  arg0 = 0.0;
  uVar1 = inferred_coolant_temperature_ffffa98c;
  cVar2 = rx8_is_outside_tolerance_band(DAT_ffffc01c,0,0x3727c5ac);
  if ((cVar2 == '\0') && (engine_running_ffffa428 == '\x01')) {
    uVar1 = 1;
    DAT_ffffc01c = arg0;
    DAT_ffffc020 = arg0;
    DAT_ffffc024 = arg0;
  }
  else {
    if (DAT_ffffb0cb == '\0') {
      fVar3 = (float)lookup_2d_descriptor_scaled(uVar1,&tbl_table_2d_200_0006ae90);
      fVar4 = (float)lookup_2d_descriptor_scaled(uVar1,&tbl_table_2d_201_0006aea4);
      fVar4 = DAT_ffffc024 - fVar4;
      DAT_ffffc020 = rx8_max_float(arg0,DAT_ffffc020 - fVar3);
      DAT_ffffc024 = rx8_max_float(arg0,fVar4);
    }
    fVar3 = rx8_max_float(DAT_ffffc020,DAT_ffffc024);
    DAT_ffffc01c = rx8_max_float(arg0,fVar3);
    uVar1 = extraout_r0;
  }
  return uVar1;
}


