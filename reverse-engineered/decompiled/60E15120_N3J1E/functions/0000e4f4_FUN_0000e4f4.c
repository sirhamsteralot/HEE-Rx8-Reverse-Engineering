/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00068f5c: Table 2D - 288 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00068f68: Table 2D - 289 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00068f74: Table 2D - 290 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00068f94: Table 3D - 103 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0000e4f4; body bytes: 108; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000e4f8 (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000e4f4(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  if (DAT_ffffb53a == '\x01') {
    DAT_ffffa460 = rx8_lookup_2d_raw_u8(&tbl_table_2d_288_check_datatype_00068f5c);
  }
  else if (DAT_ffffb534 == '\x01') {
    uVar2 = rx8_decode_u8_affine(0x3f800000,0,(int)DAT_ffffa461);
    DAT_ffffa460 = rx8_lookup_3d_raw_u8(engine_speed_rpm_ffffb548,uVar2,&tbl_table_3d_103_00068f94);
  }
  else {
    if (DAT_ffffca4c == '\x01') {
      puVar1 = &tbl_table_2d_289_check_datatype_00068f68;
    }
    else {
      puVar1 = &tbl_table_2d_290_check_datatype_00068f74;
    }
    DAT_ffffa460 = rx8_lookup_2d_raw_u8(engine_speed_rpm_ffffb548,puVar1);
  }
  return;
}


