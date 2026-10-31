/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006990c: Table 2D - 304 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0003cd06; body bytes: 484; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003cf26) */
/* WARNING: Removing unreachable block (ram,0x0003cf2e) */

undefined ** FUN_0003cd06(void)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar5;
  undefined **ppuVar4;
  float fVar6;
  float fVar7;
  float extraout_fr0;
  undefined4 uVar8;
  undefined4 uVar9;
  
  cVar3 = DAT_ffffd1c5;
  cVar2 = DAT_ffffc5e6;
  fVar6 = inferred_coolant_temperature_ffffa98c;
  DAT_ffffc604 = rx8_lookup_2d_raw_u16(inferred_coolant_temperature_catalyst_temp_model_ffffa998,&tbl_closed_loop_warmup_time_0006990c);
  DAT_ffffc600 = engine_running_timer_ffffa424 < DAT_ffffc604;
  candidate_o2_monitor_integrator();
  uVar9 = 0;
  if (cVar3 == '\x01') {
    DAT_ffffc5fc = '\0';
    DAT_ffffc5fd = '\0';
    DAT_ffffc5fe = '\0';
    DAT_ffffc5ff = '\0';
  }
  else {
    bVar1 = false;
    if (-100.0 <= inferred_coolant_temperature_ffffa98c) {
      DAT_ffffc5ff = '\x01';
    }
    if (-10.0 <= intake_air_temperature_ffffaddc) {
      if ((((DAT_ffffc5fe == '\0') && (cVar2 == '\0')) && (DAT_ffffc5db == '\0')) &&
         (cVar5 = ref_getFaultStatus__(0x15), cVar5 == '\0')) {
        if ((DAT_ffffc5ff == '\x01') && (DAT_ffffc5fc == '\0')) {
          DAT_ffffc5fd = '\x01';
        }
        bVar1 = true;
      }
    }
    else {
      DAT_ffffc5fe = '\x01';
    }
    if (DAT_ffffc5fd == '\x01') {
      DAT_ffffc5fc = '\0';
    }
    else {
      cVar5 = rx8_is_outside_tolerance_band(DAT_ffffc5ec,uVar9,0x3727c5ac);
      if (((bVar1) && (DAT_ffffc5f8 == 0)) && ((cVar5 == '\0' && (DAT_ffffc5ff == '\0')))) {
        DAT_ffffc5fc = '\x01';
      }
    }
  }
  if (cVar3 == '\x01') {
    DAT_ffffc602 = '\0';
  }
  else {
    if ((((5.625 <= DAT_ffffc5f0 - DAT_ffffc5f4) || (fVar6 < 200.0)) && (DAT_ffffd1ad == '\0')) &&
       (cVar2 == '\0')) {
      DAT_ffffc602 = '\x01';
    }
    if (DAT_ffffc602 != '\x01') {
      uVar8 = 0x44800000;
      fVar6 = (float)rx8_decode_u16_affine(0x44800000,uVar9,0xffffffff);
      fVar7 = (float)rx8_decode_u16_affine(0x42800000,uVar9,(int)DAT_ffffc168);
      ppuVar4 = (undefined **)
                rx8_decode_u16_affine(uVar8,uVar9,(int)engine_on_time_counter_ffffa426);
      if (extraout_fr0 <= fVar6 + fVar7) {
        return ppuVar4;
      }
      return &PTR_0007aac8;
    }
  }
  DAT_ffffc601 = 0;
  return (undefined **)((int)&vector_Poweron_Reset + 1);
}


