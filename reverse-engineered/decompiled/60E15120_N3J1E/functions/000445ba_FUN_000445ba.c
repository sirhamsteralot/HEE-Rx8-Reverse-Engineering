/* [ADDITIONAL SOURCE REVIEW]
 * misfire_dtc_evaluate [high]: Misfire DTC evaluation on the 2000-tick (DAT_ffffba9e): compares DAT_ffffb692 and a scaled rpm-lookup product (tbl 0x6b9c0, 23 cells) against DAT_ffffcb72/DAT_ffffcb62 -> DAT_ffffcb6d/cb6e; rotor bits from DAT_ffffb68c/0xffffb68e -> DAT_ffffcb6c; then bsr 0x44724 (asm 0x446ea). Called from 0x287aa.
 * RAM 0xffffcb6c misfire_dtc_rotor_bits (uint8): Rotor bits assembled in 0x445ba from cb70<<1 | cb6f (bank0/bank1) for the 2000-tick DTC set 0x44724 (code 1 -> P0301/P0302 selection via prefix table 0x7e55a).
 * RAM 0xffffcb6d misfire_dtc_pending (uint8): Set by 0x445ba when the 2000-tick count (b692) or the rpm-scaled product falls below the window thresholds (cb72/cb62); 0x44724 then sets slot 1 with code 4 (or 2 on drive cycle).
 * RAM 0xffffcb6e misfire_dtc_confirmed (uint8): Set by 0x445ba when the 2000-tick evaluation passes; 0x44724 then sets slot 1 with code 1 and the rotor bits cb6c.
 */
/* ROM address: 0x000445ba; body bytes: 296; decompiled */

undefined4 misfire_dtc_evaluate(void)

{
  undefined4 uVar1;
  ushort uVar2;
  ushort uVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  
  uVar3 = misfire_event_count_2000_ffffb692;
  if (DAT_ffffd1c5 == '\x01') {
    misfire_dtc_pending_ffffcb6d = 0;
    misfire_dtc_confirmed_ffffcb6e = 0;
    misfire_dtc_rotor_bits_ffffcb6c = 0;
    DAT_ffffcb6f = 0;
    DAT_ffffcb70 = '\0';
    uVar1 = 1;
  }
  else {
    uVar1 = 2000;
    if (misfire_window_2000_ffffba9e == 2000) {
      uVar1 = 0x3f800000;
      uVar6 = 0;
      fVar4 = (float)rx8_decode_u16_affine(0x3f800000,0,(int)(short)misfire_event_count_2000_ffffb692)
      ;
      DAT_ffffcb74 = rx8_lookup_2d_raw_u16(engine_speed_rpm_ffffb548,&DAT_0006b9c0);
      fVar5 = (float)rx8_decode_u16_affine(0x3e800000,uVar6,(int)DAT_ffffcb74);
      uVar2 = rx8_encode_u16_affine_saturate(fVar4 * fVar5,uVar1,uVar6);
      if ((uVar3 < misfire_threshold_2000_ffffcb72) || (uVar2 < misfire_sustained_counter_b_ffffcb62)) {
        misfire_dtc_pending_ffffcb6d = 1;
        misfire_dtc_confirmed_ffffcb6e = 0;
      }
      else {
        misfire_dtc_pending_ffffcb6d = 0;
        misfire_dtc_confirmed_ffffcb6e = 1;
        uVar3 = rx8_encode_u16_affine_saturate(fVar4 * 0.9,uVar1,uVar6);
        if (uVar3 < misfire_counter_bank1_b_ffffb68c) {
          DAT_ffffcb6f = 1;
        }
        if (uVar3 < misfire_counter_bank0_b_ffffb68e) {
          DAT_ffffcb70 = '\x01';
        }
        misfire_dtc_rotor_bits_ffffcb6c = DAT_ffffcb70 << 1 | DAT_ffffcb6f;
      }
      uVar1 = misfire_dtc_set();
      misfire_dtc_rotor_bits_ffffcb6c = 0;
      misfire_counter_bank1_b_ffffb68c = 0;
      misfire_counter_bank0_b_ffffb68e = 0;
      misfire_rpm_counter_b_ffffcb7a = 0;
      misfire_load_counter_b_ffffcb7e = 0;
      misfire_sustained_counter_b_ffffcb62 = 0;
      DAT_ffffbaa0 = 0;
      DAT_ffffcb6f = 0;
      DAT_ffffcb70 = '\0';
    }
  }
  return uVar1;
}


