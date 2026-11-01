/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x00069b0c: Table 2D - 70 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069b20: Table 2D - 71 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069b34: Table 2D - 72 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069bcc: Table 2D - 79 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069be0: Table 2D - 80 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069c1c: Table 2D - 313 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069c28: Table 2D - 314 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x00069c34: Table 2D - 315 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0001d8dc; body bytes: 760; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001dc08) */
/* WARNING: Removing unreachable block (ram,0x0001dc22) */

undefined4 * FUN_0001d8dc(void)

{
  char cVar1;
  undefined4 *puVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float arg3;
  float fVar8;
  
  fVar8 = 0.0;
  fVar4 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff80ec);
  cVar1 = DAT_ffffcac8;
  arg3 = 1e-05;
  if (DAT_ffffb07d == '\x01') {
    fVar4 = (float)engine_running_timer_ffffa424 * 8.0;
    if (DAT_ffffcac8 == DAT_ffffb0c3) {
      if (DAT_ffffcac8 == '\0') {
        fVar8 = DAT_ffffb0a0;
        fVar5 = (float)lookup_2d_descriptor_scaled(&tbl_table_2d_79_00069bcc);
        fVar6 = (float)lookup_2d_descriptor_scaled(fVar4,&tbl_table_2d_70_00069b0c);
        fVar7 = (float)lookup_2d_descriptor_scaled(fVar4,&tbl_table_2d_313_check_datatype_00069c1c);
        fVar4 = (float)lookup_2d_descriptor_scaled(fVar4,&tbl_table_2d_314_check_datatype_00069c28);
        DAT_ffffb084 = fVar6 * -0.8 * fVar5;
        if (DAT_ffffb07c == '\x01') {
          fVar5 = (DAT_ffffb0bc - DAT_ffffb078) * 0.993;
          DAT_ffffb0a8 = 0.003;
        }
        else {
          fVar5 = (DAT_ffffb0bc - DAT_ffffb078) * 0.9899999;
          DAT_ffffb0a8 = -0.003;
        }
        DAT_ffffb094 = (DAT_ffffb078 + fVar5) - DAT_ffffb080;
        DAT_ffffb098 = rx8_first_order_filter(DAT_ffffb094,DAT_ffffb098,0.75,arg3);
        DAT_ffffb09c = rx8_clamp_float(DAT_ffffb084 * DAT_ffffb098,fVar7,fVar4);
        DAT_ffffb088 = -0.008;
        fVar8 = DAT_ffffb098 + fVar8;
      }
      else {
        fVar8 = DAT_ffffb0a0;
        fVar5 = (float)lookup_2d_descriptor_scaled(mass_air_flow_ffffa9ec,&tbl_table_2d_80_00069be0);
        fVar6 = (float)lookup_2d_descriptor_scaled(fVar4,&tbl_table_2d_71_00069b20);
        fVar7 = (float)lookup_2d_descriptor_scaled(fVar4,&tbl_table_2d_315_check_datatype_00069c34);
        fVar4 = (float)lookup_2d_descriptor_scaled(fVar4,&tbl_table_2d_72_00069b34);
        DAT_ffffb084 = fVar6 * -1.5 * fVar5;
        if (DAT_ffffb07c == '\x01') {
          fVar5 = (DAT_ffffb0bc - DAT_ffffb078) * 0.993;
          DAT_ffffb0a8 = 0.001;
        }
        else {
          fVar5 = (DAT_ffffb0bc - DAT_ffffb078) * 0.9899999;
          DAT_ffffb0a8 = -0.001;
        }
        DAT_ffffb094 = (DAT_ffffb078 + fVar5) - DAT_ffffb080;
        DAT_ffffb098 = rx8_first_order_filter(DAT_ffffb094,DAT_ffffb098,0.75,arg3);
        DAT_ffffb09c = rx8_clamp_float(DAT_ffffb084 * DAT_ffffb098,fVar7,fVar4);
        DAT_ffffb088 = -0.005;
        fVar8 = DAT_ffffb098 + fVar8;
      }
      DAT_ffffb0ac = DAT_ffffb09c + DAT_ffffb0a8 + DAT_ffffb088 * fVar8;
      puVar2 = (undefined4 *)ref_calculateRearO2SomethingIntegrator__(DAT_ffffb088 * fVar8,fVar8);
    }
    else {
      if (DAT_ffffb07c == '\x01') {
        pfVar3 = (float *)&DAT_00070bf4;
      }
      else {
        pfVar3 = (float *)&DAT_00070bf8;
      }
      DAT_ffffb094 = (DAT_ffffb078 + (DAT_ffffb0bc - DAT_ffffb078) * *pfVar3) - DAT_ffffb080;
      DAT_ffffb098 = DAT_ffffb094;
      if (DAT_ffffcac8 == '\x01') {
        puVar2 = (undefined4 *)0x1;
        inferred_trim_b074_ffffb074_ffffb074 = fVar8;
        DAT_ffffb0a0 = fVar8;
        DAT_ffffb0a4 = fVar8;
      }
      else {
        fVar4 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(fVar8,&DAT_ffff80f4);
        puVar2 = (undefined4 *)rx8_is_outside_tolerance_band(0xbc03126f,fVar8,arg3);
        inferred_trim_b074_ffffb074_ffffb074 = fVar4;
        DAT_ffffb0a0 = fVar8;
        DAT_ffffb0a4 = fVar4;
        if (((uint)puVar2 & 0xff) != 0) {
          DAT_ffffb0a0 = fVar4 / -0.008;
        }
      }
    }
  }
  else {
    if (DAT_ffffb07c == '\x01') {
      pfVar3 = (float *)&DAT_00070bf4;
    }
    else {
      pfVar3 = (float *)&DAT_00070bf8;
    }
    DAT_ffffb094 = (DAT_ffffb078 + (DAT_ffffb0bc - DAT_ffffb078) * *pfVar3) - DAT_ffffb080;
    if (DAT_ffffb0c2 == '\0') {
      DAT_ffffb0c2 = '\x01';
      DAT_ffffb0a0 = fVar8;
      DAT_ffffb0a4 = fVar8;
    }
    puVar2 = &inferred_coolant_temperature_ffffa98c;
    if (80.0 <= inferred_coolant_temperature_ffffa98c) {
      pfVar3 = (float *)&DAT_00070c10;
    }
    else {
      pfVar3 = (float *)&DAT_00070c0c;
    }
    inferred_trim_b074_ffffb074_ffffb074 = *pfVar3 * fVar4;
    DAT_ffffb098 = DAT_ffffb094;
  }
  DAT_ffffb0bc = DAT_ffffb080;
  DAT_ffffb0c3 = cVar1;
  return puVar2;
}


