/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a458: Throttle Pedal to Throttle Plate Request - Gear 1/2 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a474: Throttle Pedal to Throttle Plate Request - Gear Neutral (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a490: Throttle Pedal to Throttle Plate Request - Gear 5/6 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006a4ac: Throttle Pedal to Throttle Plate Request - Gear 3/4 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000228dc; body bytes: 236; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00022950) */
/* WARNING: Removing unreachable block (ram,0x00022970) */
/* WARNING: Removing unreachable block (ram,0x00022972) */
/* WARNING: Removing unreachable block (ram,0x00022982) */
/* WARNING: Removing unreachable block (ram,0x00022984) */
/* WARNING: Heritage AFTER dead removal. Example location: r0xffffb398 : 0x0002299c */
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* Unique exact-byte match to related 60E0FC00 function at 0002326c (236 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_calculateThrottlePedalPositionMapBased(void)

{
  undefined *puVar1;
  uint uVar2;
  char cVar3;
  float *pfVar4;
  float fVar5;
  
  if (DAT_ffffb2cc == '\x01') {
    puVar1 = &tbl_throttle_pedal_to_throttle_plate_request_gear_1_2_0006a458;
  }
  else {
    if (DAT_ffffb2cd != '\x01') {
      if (DAT_ffffb2ce == '\x01') {
        puVar1 = &tbl_throttle_pedal_to_throttle_plate_request_gear_5_6_0006a490;
      }
      else {
        puVar1 = &tbl_throttle_pedal_to_throttle_plate_request_gear_3_4_0006a4ac;
      }
      fVar5 = (float)lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,inferred_ram_a9bc_ffffa9bc_ffffa9bc,puVar1);
      goto LAB_00022932;
    }
    puVar1 = &tbl_throttle_pedal_to_throttle_plate_request_gear_neutral_0006a474;
  }
  fVar5 = (float)lookup_3d_descriptor_scaled(engine_speed_rpm_ffffb548,inferred_ram_a9bc_ffffa9bc_ffffa9bc,puVar1);
LAB_00022932:
  fVar5 = rx8_clamp_float(fVar5,0.0,84.0);
  DAT_ffffb3ec = 0;
  cVar3 = '\f';
  uVar2 = 0xb;
  DAT_ffffb3cc = DAT_ffffb398;
  pfVar4 = &DAT_ffffb3cc;
  DAT_ffffb398 = fVar5;
  do {
    cVar3 = cVar3 + -1;
    pfVar4 = pfVar4 + -1;
    *pfVar4 = (&DAT_ffffb398)[uVar2 & 0xff];
    uVar2 = uVar2 + 0xff;
  } while (cVar3 != '\0');
  return;
}


