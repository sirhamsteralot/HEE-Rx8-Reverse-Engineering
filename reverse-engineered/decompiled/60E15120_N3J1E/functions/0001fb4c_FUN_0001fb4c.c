/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001fb4c; body bytes: 398; decompiled */

undefined4 * FUN_0001fb4c(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  undefined4 *puVar5;
  float fVar6;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  
  cVar4 = DAT_ffffb156;
  cVar3 = DAT_ffffb155;
  cVar2 = DAT_ffffb153;
  cVar1 = engine_running_flag_ffffaa68;
  fVar6 = -43.0;
  puVar5 = (undefined4 *)(uint)ol_decay_enable_b_ffffb152;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  if (((DAT_ffffb140 == 0) || (ol_decay_enable_b_ffffb152 != 0)) &&
     ((DAT_ffffb1d5 != '\0' || (engine_running_flag_ffffaa68 != '\x01')))) {
    if (DAT_ffffb140 == 0) {
      if (puVar5 == (undefined4 *)0x0) {
        ol_decay_enable_a_ffffb142 = 1;
      }
      else if ((DAT_ffffb1d6 == '\0') && (DAT_ffffb155 == '\x01')) {
        ol_decay_enable_a_ffffb142 = rx8_lookup_2d_raw_u16(inferred_coolant_temperature_ffffa98c,&PTR_CAL_table_845_00069e44);
      }
      else if ((DAT_ffffb1d7 == '\0') && (DAT_ffffb156 == '\x01')) {
        ol_decay_enable_a_ffffb142 = rx8_lookup_2d_raw_u16(inferred_coolant_temperature_ffffa98c,&PTR_CAL_table_845_00069e50);
      }
      else if (ol_decay_enable_a_ffffb142 != 0) {
        ol_decay_enable_a_ffffb142 = ol_decay_enable_a_ffffb142 + -1;
      }
    }
    else if ((puVar5 == (undefined4 *)0x1) && (ol_decay_enable_a_ffffb142 != 0)) {
      ol_decay_enable_a_ffffb142 = ol_decay_enable_a_ffffb142 + -1;
    }
  }
  else {
    ol_decay_enable_a_ffffb142 = 0;
  }
  if (snapshot_inferred_coolant_temperature_ffffa98c < -40.0) {
    if (snapshot_inferred_coolant_temperature_ffffa98c < fVar6) {
      DAT_ffffb1cf = 0;
    }
  }
  else {
    DAT_ffffb1cf = 1;
  }
  if (((((puVar5 == (undefined4 *)0x1) && (ol_decay_enable_a_ffffb142 != 0)) || (ol_timer_expired_ffffb159 == '\0')) ||
      (puVar5 = &fuel_correction_sum_ffffc644_ffffc644, 1000.0 < fuel_correction_sum_ffffc644_ffffc644)) ||
     ((DAT_ffffb1d5 == '\0' && (puVar5 = (undefined4 *)0x1, cVar1 == '\x01')))) {
    DAT_ffffb140 = 8;
  }
  else {
    puVar5 = (undefined4 *)(int)cVar2;
    if (((puVar5 == (undefined4 *)0x0) &&
        (puVar5 = (undefined4 *)(uint)DAT_ffffb1cf, puVar5 == (undefined4 *)0x1)) &&
       (DAT_ffffb140 != 0)) {
      DAT_ffffb140 = DAT_ffffb140 + -1;
    }
  }
  DAT_ffffb1d5 = cVar1;
  DAT_ffffb1d6 = cVar3;
  DAT_ffffb1d7 = cVar4;
  return puVar5;
}


