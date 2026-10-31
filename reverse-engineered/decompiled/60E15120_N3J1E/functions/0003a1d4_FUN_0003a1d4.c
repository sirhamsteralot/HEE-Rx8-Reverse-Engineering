/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b5cc: Table 2D - 254 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0003a1d4; body bytes: 174; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003a608 (174 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0003a1d4(void)

{
  char cVar1;
  
  DAT_ffffc554 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&tbl_table_2d_254_0006b5cc);
  DAT_ffffc546 = engine_load_ffffc0b4 < DAT_ffffc554;
  DAT_ffffc547 = '\x01';
  if (DAT_ffffb0ca == '\x01') {
    DAT_ffffc53c = 0x20;
  }
  else if (DAT_ffffc53c != 0) {
    DAT_ffffc53c = DAT_ffffc53c + -1;
  }
  if ((((((bool)DAT_ffffc546) &&
        (cVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fc2,0), cVar1 == '\0')) &&
       (DAT_ffffaa81 == '\x01')) && ((DAT_ffffc547 == '\x01' && (cVar1 = '\0', DAT_ffffc53c == 0))))
     || (cVar1 = DAT_ffffd26d, DAT_ffffd26d == '\x01')) {
    DAT_ffffc548 = 1;
  }
  else {
    DAT_ffffc548 = 0;
  }
  return cVar1;
}


