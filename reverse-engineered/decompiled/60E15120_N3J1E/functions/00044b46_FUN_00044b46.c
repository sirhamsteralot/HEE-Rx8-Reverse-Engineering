/* [ADDITIONAL SOURCE REVIEW]
 * misfire_dtc_evaluate_400 [high]: 400-tick DTC evaluation (DAT_ffffba9c==400): uVar3 = encode(decode(1.0,0,b690) * decode(0.5,0,lookup_2d_raw_u16(rpm, tbl 0x6ba24 [23 cells, 400..9200])), 1.0, 0); if b690 < cba2 || uVar3 < cb60: cb9d=1 (and cb9e=0) unless cb87==1 (rpm>=5000 latch); else cb9e=1, rotor bits cb9f/cba0 from uVar3*0.9 vs counters b688/b68a -> cb9c; calls 0x44cec; then resets cb9c, b688, b68a, cb78, cb7c, cb60, cb84=1000, cb87, cb9f, cba0. Called from 0x287aa.
 */
/* ROM address: 0x00044b46; body bytes: 326; decompiled */

undefined2 * misfire_dtc_evaluate_400(void)

{
  bool bVar1;
  undefined2 *puVar2;
  ushort uVar3;
  ushort uVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  uVar4 = misfire_event_count_400_ffffb690;
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcb9d = 0;
    DAT_ffffcb9e = 0;
    DAT_ffffcb9c = 0;
    DAT_ffffcb9f = 0;
    DAT_ffffcba0 = '\0';
    puVar2 = (undefined2 *)0x1;
  }
  else {
    puVar2 = (undefined2 *)0x190;
    if (misfire_window_400_ffffba9c == 400) {
      uVar7 = 0x3f800000;
      uVar8 = 0;
      fVar5 = (float)rx8_decode_u16_affine(0x3f800000,0,(int)(short)misfire_event_count_400_ffffb690)
      ;
      DAT_ffffcba4 = rx8_lookup_2d_raw_u16(engine_speed_rpm_ffffb548,&DAT_0006ba24);
      fVar6 = (float)rx8_decode_u16_affine(0x3e800000,uVar8,(int)DAT_ffffcba4);
      uVar3 = rx8_encode_u16_affine_saturate(fVar5 * fVar6,uVar7,uVar8);
      bVar1 = false;
      if ((uVar4 < DAT_ffffcba2) || (uVar3 < misfire_sustained_counter_a_ffffcb60)) {
        if (DAT_ffffcb87 == '\0') {
          DAT_ffffcb9d = 1;
          DAT_ffffcb9e = 0;
        }
        else {
          bVar1 = true;
        }
      }
      else {
        DAT_ffffcb9d = 0;
        DAT_ffffcb9e = 1;
        uVar4 = rx8_encode_u16_affine_saturate(fVar5 * 0.9,uVar7,uVar8);
        if (uVar4 < misfire_counter_bank1_a_ffffb688) {
          DAT_ffffcb9f = 1;
        }
        if (uVar4 < misfire_counter_bank0_a_ffffb68a) {
          DAT_ffffcba0 = '\x01';
        }
        DAT_ffffcb9c = DAT_ffffcba0 << 1 | DAT_ffffcb9f;
      }
      if (!bVar1) {
        misfire_dtc_set_400();
      }
      DAT_ffffcb9c = 0;
      misfire_counter_bank1_a_ffffb688 = 0;
      misfire_counter_bank0_a_ffffb68a = 0;
      misfire_rpm_counter_a_ffffcb78 = 0;
      misfire_load_counter_a_ffffcb7c = 0;
      misfire_sustained_counter_a_ffffcb60 = 0;
      puVar2 = &DAT_ffffcb84;
      DAT_ffffcb84 = 1000;
      DAT_ffffcb87 = '\0';
      DAT_ffffcb9f = 0;
      DAT_ffffcba0 = '\0';
    }
  }
  return puVar2;
}


