/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b9e0: Table 3D - 127 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0004499c; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000441b8 (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004499c(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcb84 = 1000;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffb69c;
    if ((uVar1 == 1) &&
       (uVar1 = rx8_lookup_3d_raw_u16(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&tbl_table_3d_127_0006b9e0),
       (uVar1 & 0xffff) < (uint)DAT_ffffcb84)) {
      DAT_ffffcb84 = (ushort)uVar1;
    }
  }
  return uVar1;
}


