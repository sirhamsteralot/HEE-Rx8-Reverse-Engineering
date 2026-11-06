/* [ADDITIONAL SOURCE REVIEW]
 * idle_trim_ramp [medium]: 0xffffa7c0 ramped down by 0.00087 (pool 0x6dabc) toward 3-D floor tbl 0x69424(coolant, baro) when 0xffffa7b4==0; counters 0xffffa814/a816 gated by a7b4/a7b5. Called from 0x167c0 via pool 0x168b4.
 */
/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069424: Table 3D - 12 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00014f6c; body bytes: 202; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00014ecc (202 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint candidate_idle_trim_ramp(void)

{
  uint uVar1;
  float fVar2;
  
  if (((DAT_ffffa8a8 == '\x01') || (engine_stopped_latch_ffffa41c == '\x01')) ||
     ((fVar2 = DAT_ffffa7c0, DAT_ffffa7b4 == 1 &&
      (((0x1e < DAT_ffffa814 && (DAT_ffffa7b5 == '\0')) && (0x1e < DAT_ffffa816)))))) {
    fVar2 = DAT_ffffa7a8;
  }
  if (DAT_ffffa7b4 == 0) {
    DAT_ffffa7fc = (float)lookup_3d_descriptor_scaled(inferred_coolant_temperature_ffffa990,inferred_barometric_pressure_ffffad14,&tbl_table_3d_12_00069424);
    if (DAT_ffffa7fc < fVar2) {
      fVar2 = rx8_max_float(fVar2 - 0.00087,DAT_ffffa7fc);
    }
  }
  uVar1 = (uint)DAT_ffffa7b4;
  DAT_ffffa7c0 = fVar2;
  if (uVar1 == 1) {
    uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffa814,1);
    DAT_ffffa814 = (ushort)uVar1;
  }
  else {
    DAT_ffffa814 = 0;
  }
  if (DAT_ffffa7b5 == '\0') {
    uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffa816,1);
    DAT_ffffa816 = (ushort)uVar1;
  }
  else {
    DAT_ffffa816 = 0;
  }
  return uVar1;
}


