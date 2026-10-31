/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069ca0: Table 2D - 319 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0001eae0; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0001f540 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

char FUN_0001eae0(void)

{
  if ((DAT_ffffb0fa != 0) && (DAT_ffffb0d6 == 0)) {
    if (DAT_ffffb220 < 0.015) {
      DAT_ffffb0d4 = 0x61a;
    }
    else {
      DAT_ffffb0d4 = rx8_lookup_2d_raw_u16(&tbl_table_2d_319_check_datatype_00069ca0);
    }
  }
  if ((DAT_ffffb2f6 == '\x01') && (DAT_ffffb0d4 != 0)) {
    DAT_ffffb0d4 = DAT_ffffb0d4 + -1;
  }
  DAT_ffffb0fa = DAT_ffffb0d6;
  return DAT_ffffb2f6;
}


