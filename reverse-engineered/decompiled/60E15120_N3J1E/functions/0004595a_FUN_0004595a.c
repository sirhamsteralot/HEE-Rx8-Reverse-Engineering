/* [ADDITIONAL SOURCE REVIEW]
 * tp_correlation_fault_check [high]: APP1/APP2 (pedal) zeroed-volts correlation |a9ac - a9b0|: limit 3.5f on every rung of the pedal-2 ladder (breakpoints 0x7c76c/0x7c770/0x7c774/0x7c778 = 0.6/1.2/2.0/4.0, limits 0x7c77c-0x7c78c) when learned-valid 0xffff8078==1, else 9.536f (ROM 0x7c790=0x41189375); monitor gated by 0xffffcbf0==1; good counter cbf2 >= 25 (u16 0x7c794) -> cbec=1; bad counter cbee >= 29 (u16 0x7c796) -> 0xffff872c=1 and DTC 0x6c via 0x5fd38. The tp_ prefix in the alias names is a carry-over: the operands are the pedal channels. Pools 0x459f8=0xffffcbf2, 0x459f0=0xffffcbf0, 0x45ad0=0xffffcbee, 0x45ac4=0x872c/0xcbec, 0x459dc=0xa9ac/0x8078. Called from 0x38e12.
 * RAM 0xffff872c tp_correlation_fault_latch (uint8): Set by 0x4595a when the pedal bad-correlation counter cbee >= 29 (u16 0x7c796) -> DTC 0x6c (P0122/23-family TP correlation; dtc_set_fault 0x5fd38(0x6c)).
 * RAM 0xffffcbec tp_correlation_ok (uint8): Set by 0x4595a when the pedal good-correlation counter cbf2 >= 25 (u16 0x7c794).
 * RAM 0xffffcbf2 tp_correlation_good_counter (uint16): Good-correlation counter in tp_correlation_fault_check 0x4595a (pool 0x459f8=0xffffcbf2); >= 25 (u16 0x7c794) -> 0xffffcbec=1.
 * RAM 0xffffcbee tp_correlation_bad_counter (uint16): Bad-correlation counter in 0x4595a (pool 0x45ad0=0xffffcbee); >= 29 (u16 0x7c796) -> 0xffff872c=1 and DTC 0x6c via 0x5fd38 (pools 0x45ac4=0x872c/0xcbee).
 */
/* ROM address: 0x0004595a; body bytes: 290; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000449e6 (118 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint tp_correlation_fault_check(void)

{
  char cVar2;
  uint uVar1;
  float *pfVar3;
  float fVar4;
  float fVar5;
  
  fVar5 = DAT_ffffa9b0;
  fVar4 = rx8_absolute_difference(pedal_1_volts_zeroed_ffffa9ac,DAT_ffffa9b0);
  if (DAT_ffffcbf0 != '\x01') {
    tp_correlation_good_counter_ffffcbf2 = 0;
    goto LAB_00045a72;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&learned_pedal_zero_valid_ffff8078,0);
  if (cVar2 == '\x01') {
    if (fVar5 < 0.6) {
      pfVar3 = (float *)&DAT_0007c77c;
      goto LAB_00045a24;
    }
    if (1.2 <= fVar5) {
      if (fVar5 < 2.0) {
        pfVar3 = (float *)&DAT_0007c784;
        goto LAB_000459d0;
      }
      if (fVar5 < 4.0) {
        pfVar3 = (float *)&DAT_0007c788;
        goto LAB_000459d0;
      }
      fVar5 = 3.5;
    }
    else {
      pfVar3 = (float *)&DAT_0007c780;
LAB_000459d0:
      fVar5 = *pfVar3;
    }
  }
  else {
    pfVar3 = (float *)&DAT_0007c790;
LAB_00045a24:
    fVar5 = *pfVar3;
  }
  if (fVar4 < fVar5) {
    if (0x18 < tp_correlation_good_counter_ffffcbf2) {
      tp_correlation_bad_counter_ffffcbee = 0;
      tp_correlation_ok_ffffcbec = 1;
    }
    tp_correlation_good_counter_ffffcbf2 = rx8_add_u16_saturate((int)(short)tp_correlation_good_counter_ffffcbf2,1);
  }
  else {
    tp_correlation_good_counter_ffffcbf2 = 0;
    tp_correlation_bad_counter_ffffcbee = rx8_add_u16_saturate((int)(short)tp_correlation_bad_counter_ffffcbee,1);
    if (0x1c < tp_correlation_bad_counter_ffffcbee) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&tp_correlation_fault_latch_ffff872c,1);
    }
  }
LAB_00045a72:
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&tp_correlation_fault_latch_ffff872c,0);
  if (cVar2 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x6c,1);
    return uVar1;
  }
  if (tp_correlation_ok_ffffcbec == 1) {
    uVar1 = dtc_set_fault_x0(0x6c,2);
    return uVar1;
  }
  return (uint)tp_correlation_ok_ffffcbec;
}


