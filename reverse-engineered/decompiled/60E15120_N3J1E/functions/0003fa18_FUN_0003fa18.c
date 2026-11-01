/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b658: Table 3D - 122 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0003fa18; body bytes: 294; decompiled */

undefined2 * FUN_0003fa18(void)

{
  char cVar2;
  char cVar3;
  undefined2 *puVar1;
  float fVar4;
  float fVar5;
  float fVar6;
  
  DAT_ffffc7dc = rx8_lookup_3d_raw_u8(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&tbl_table_3d_122_0006b658);
  fVar6 = 0.0;
  cVar2 = rx8_is_outside_tolerance_band(inferred_ram_b2f0_ffffb2f0_ffffb2f0,0,0x3727c5ac);
  fVar4 = rx8_absolute_difference(DAT_ffffcab8,fVar6);
  fVar5 = rx8_absolute_difference(DAT_ffffcabc,fVar6);
  fVar6 = rx8_absolute_difference(DAT_ffffad50,fVar6);
  cVar3 = ref_getFaultStatus__(0x1c);
  if (((((((cVar3 != '\0') || (DAT_ffffaa81 != '\x01')) || (closed_loop_active_ffffae1f != '\x01')) ||
        ((DAT_ffffc91c != '\x01' || (DAT_ffffc7dc == '\0')))) ||
       ((50.0 <= fVar4 || ((0.05 <= fVar5 || (0.42 <= fVar6)))))) || (0x31 < DAT_ffffc7b8)) ||
     ((DAT_ffffd1c5 != '\0' ||
      ((puVar1 = (undefined2 *)0x0, cVar2 != '\0' &&
       ((0.15 <= DAT_ffffb220 || (puVar1 = &DAT_ffffb2f4, DAT_ffffb2f4 < 0x271)))))))) {
    puVar1 = &DAT_0007ac70;
    DAT_ffffc700 = 0;
    DAT_ffffc7b0 = 0x20;
  }
  else {
    DAT_ffffc700 = 1;
    if (DAT_ffffc7b0 != 0) {
      DAT_ffffc7b0 = DAT_ffffc7b0 + -1;
    }
  }
  return puVar1;
}


