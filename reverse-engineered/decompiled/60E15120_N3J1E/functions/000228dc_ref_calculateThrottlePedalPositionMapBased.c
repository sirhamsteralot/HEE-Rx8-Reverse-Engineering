/* [ADDITIONAL SOURCE REVIEW]
 * throttle_pedal_to_plate_request_map [high]: 3D lookup lookup_3d_descriptor_scaled(rpm 0xffffb548, demand 0xffffa9bc, tbl) with gear flags b2cc/b2cd/b2ce selecting descriptors 0x6a458 (1/2), 0x6a474 (neutral), 0x6a490 (5/6), 0x6a4ac (3/4) (pools 0x229ca=0xa9bc, 0x229cc=0xb548/0xb2cc, 0x229d0=0xb2cd/0xb2ce, 0x229dc=0x6a458, 0x229e0=0x6a474, 0x229e4=0x6a490, 0x229e8=0x6a4ac); result clamped [0, 84.0f @0x7372c via pool 0x229f0] by 0x2404 (pool 0x229f4) into 0xffffb398 (pool 0x229ec) with 12-deep history shift (b3ec..b3c4, pool 0x229f8=0xffffb3ec). Called from batch 0x22f86.
 * RAM 0xffffb398 throttle_plate_request (float): Pedal-to-plate request: lookup_3d(rpm, a9bc, gear tbl 0x6a458/0x6a474/0x6a490/0x6a4ac) clamp [0, 84.0f @0x7372c] -> b398 (pools 0x229ec=0xffffb398, 0x229f0=0x7372c, 0x229f4=0x2404), 12-deep history b3c4..b398. Written by 0x228dc.
 */
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

void throttle_pedal_to_plate_request_map(void)

{
  undefined *puVar1;
  uint uVar2;
  char cVar3;
  float *pfVar4;
  float fVar5;
  
  if (throttle_gear_mode_1_2_ffffb2cc == '\x01') {
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
  DAT_ffffb3cc = throttle_plate_request_ffffb398;
  pfVar4 = &DAT_ffffb3cc;
  throttle_plate_request_ffffb398 = fVar5;
  do {
    cVar3 = cVar3 + -1;
    pfVar4 = pfVar4 + -1;
    *pfVar4 = (&throttle_plate_request_ffffb398)[uVar2 & 0xff];
    uVar2 = uVar2 + 0xff;
  } while (cVar3 != '\0');
  return;
}


