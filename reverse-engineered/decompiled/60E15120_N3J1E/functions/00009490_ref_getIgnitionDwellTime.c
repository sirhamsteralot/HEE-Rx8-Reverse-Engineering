/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006bbcc: Ignition Dwell Time (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00009490; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009490 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_getIgnitionDwellTime_00009490(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = rx8_lookup_3d_raw_u16(engine_speed_rpm_raw_ffff9f80,DAT_ffff9f68,&tbl_ignition_dwell_time_0006bbcc);
  uVar2 = (uVar1 & 0xffff) + (uint)DAT_ffffa0d6;
  if (uVar2 < 0x10000) {
    DAT_ffffa0d4 = (undefined2)uVar2;
  }
  else {
    DAT_ffffa0d4 = 0xffff;
  }
  return uVar1 & 0xffff;
}


