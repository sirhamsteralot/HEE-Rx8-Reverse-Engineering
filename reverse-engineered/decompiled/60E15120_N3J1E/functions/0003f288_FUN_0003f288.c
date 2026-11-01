/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003f288; body bytes: 510; decompiled */

undefined ** FUN_0003f288(void)

{
  float snapshot_DAT_ffffaa78;
  float snapshot_engine_speed_rpm_ffffb548;
  char cVar5;
  uint uVar3;
  undefined **ppuVar4;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float snapshot_inferred_coolant_temperature_ffffa98c;
  float snapshot_mass_air_flow_ffffa9ec;
  float snapshot_DAT_ffffb074;
  float snapshot_DAT_ffffad20;
  
  snapshot_engine_speed_rpm_ffffb548 = engine_speed_rpm_ffffb548;
  snapshot_DAT_ffffaa78 = DAT_ffffaa78;
  fVar9 = DAT_ffffb078 - 0.2;
  fVar8 = DAT_ffffb078 + 0.1;
  snapshot_inferred_coolant_temperature_ffffa98c = inferred_coolant_temperature_ffffa98c;
  snapshot_mass_air_flow_ffffa9ec = mass_air_flow_ffffa9ec;
  snapshot_DAT_ffffb074 = inferred_trim_b074_ffffb074_ffffb074;
  snapshot_DAT_ffffad20 = DAT_ffffad20;
  fVar6 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff8720);
  fVar7 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff8718);
  cVar5 = rx8_is_outside_tolerance_band(inferred_ram_b2f0_ffffb2f0_ffffb2f0,0,0x3727c5ac);
  uVar3 = ref_getFaultStatus__(0x6e);
  ppuVar4 = (undefined **)(uVar3 & 0xff);
  if (ppuVar4 == (undefined **)0x0) {
    uVar3 = ref_getFaultStatus__(0x6d);
    ppuVar4 = (undefined **)(uVar3 & 0xff);
    if ((((((ppuVar4 == (undefined **)0x0) &&
           (ppuVar4 = (undefined **)(uint)closed_loop_active_ffffae1f,
           ppuVar4 == (undefined **)((int)&vector_Poweron_Reset + 1))) &&
          (ppuVar4 = (undefined **)(uint)DAT_ffffb07d,
          ppuVar4 == (undefined **)((int)&vector_Poweron_Reset + 1))) &&
         ((1000.0 <= snapshot_engine_speed_rpm_ffffb548 && (snapshot_engine_speed_rpm_ffffb548 < 3200.0)))) &&
        ((ppuVar4 = (undefined **)&DAT_0007ddd0, 6.0 <= snapshot_mass_air_flow_ffffa9ec &&
         ((snapshot_mass_air_flow_ffffa9ec < 80.0 && (ppuVar4 = (undefined **)&DAT_0007ddd8, 70.0 <= snapshot_inferred_coolant_temperature_ffffa98c)))))) &&
       ((snapshot_inferred_coolant_temperature_ffffa98c < 150.0 && (ppuVar4 = (undefined **)&DAT_0007dde0, engine_load_delta_ffffc150 < 0.05)))) {
      if (0.0 <= snapshot_DAT_ffffaa78) {
        ppuVar4 = (undefined **)&UNK_00000004;
        if (((((snapshot_DAT_ffffaa78 < 52.0) && (ppuVar4 = (undefined **)&DAT_ffffae18, DAT_ffffae18 == 0)) &&
             (ppuVar4 = (undefined **)&DAT_ffffd1c5, DAT_ffffd1c5 == '\0')) &&
            ((((fVar9 <= snapshot_DAT_ffffad20 && (snapshot_DAT_ffffad20 < fVar8)) ||
              ((snapshot_DAT_ffffb074 <= fVar7 + 0.0003 || ((fVar6 - 0.0003 <= snapshot_DAT_ffffb074 || (snapshot_DAT_ffffad20 < 0.2)))))) ||
             (ppuVar4 = (undefined **)&UNK_00000014, 0.7 <= snapshot_DAT_ffffad20)))) &&
           ((cVar5 == '\0' ||
            ((ppuVar4 = &vector_Illegal_instr, DAT_ffffb220 < 0.2 &&
             (ppuVar4 = (undefined **)(int)DAT_ffffb2f4, (undefined **)0x270 < ppuVar4)))))) {
          DAT_ffffc6de = 1;
          if (0x1e < DAT_ffffc6d8) {
            DAT_ffffc6de = 1;
            return (undefined **)&DAT_0007ddc2;
          }
          ppuVar4 = (undefined **)rx8_add_u16_saturate((int)(short)DAT_ffffc6d8,1);
          DAT_ffffc6d8 = (short)ppuVar4;
          return ppuVar4;
        }
      }
      else {
        ppuVar4 = (undefined **)&UNK_00000004;
      }
    }
  }
  DAT_ffffc6de = 0;
  DAT_ffffc6d8 = 0;
  return ppuVar4;
}


