/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a038: Table 2D - 105 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000129c0; body bytes: 472; decompiled */

void FUN_000129c0(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  float *pfVar4;
  undefined *puVar5;
  undefined4 uVar6;
  float arg1;
  float arg0;
  float arg0_00;
  
  cVar3 = DAT_ffffb53c;
  uVar6 = DAT_ffffa678;
  cVar2 = fuel_cut_flag_b_ffffa445;
  cVar1 = fuel_cut_flag_a_ffffa444;
  if ((DAT_ffffa69e == '\0') && (DAT_ffffb53c == '\x01')) {
    DAT_ffffa69c = 0xfa;
  }
  else if (DAT_ffffa69c != 0) {
    DAT_ffffa69c = DAT_ffffa69c + -1;
  }
  arg1 = 0.0;
  if ((((DAT_ffffb53a == '\x01') || (DAT_ffffa69c != 0)) || (DAT_ffffa689 == '\x01')) ||
     (engine_speed_rpm_ffffb548 <= inferred_ram_a7ac_ffffa7ac_ffffa7ac + 10.0)) {
    arg0 = 0.0;
    arg0_00 = 0.0;
  }
  else if ((fuel_cut_flag_a_ffffa444 == '\x01') && (fuel_cut_flag_b_ffffa445 == '\x01')) {
    arg0 = 0.0;
    arg0_00 = 0.0;
  }
  else if ((((DAT_ffffa6a1 == '\x01') && (fuel_cut_flag_a_ffffa444 == '\0')) ||
           ((DAT_ffffa6a2 == '\x01' && (fuel_cut_flag_b_ffffa445 == '\0')))) && (cranking_active_ffffaa62_ffffaa62 == '\x01')) {
    uVar6 = inferred_coolant_temperature_ffffa98c;
    if (DAT_ffffbd68 == '\0') {
      arg0 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&DAT_00069fac);
      puVar5 = &DAT_00069fc0;
    }
    else {
      arg0 = (float)lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,&DAT_00069fd4);
      puVar5 = &DAT_00069fe8;
    }
    arg0_00 = (float)lookup_2d_descriptor_scaled(uVar6,puVar5);
  }
  else if ((DAT_ffffa687 == '\0') || (cranking_active_ffffaa62_ffffaa62 != '\0')) {
    if (DAT_ffffa686 == '\0') {
      if (cranking_active_ffffaa62_ffffaa62 == '\x01') {
        if (DAT_ffffbd68 == '\0') {
          pfVar4 = (float *)&DAT_00072328;
        }
        else {
          pfVar4 = (float *)&DAT_00072330;
        }
        arg0 = DAT_ffffa67c - 0.16;
        arg0_00 = DAT_ffffa680 - *pfVar4;
      }
      else {
        DAT_ffffa690 = (float)lookup_2d_descriptor_scaled(DAT_ffffa678,&DAT_0006a024);
        DAT_ffffa694 = (float)lookup_2d_descriptor_scaled(uVar6,&tbl_table_2d_105_0006a038);
        arg0 = DAT_ffffa67c - DAT_ffffa690;
        arg0_00 = DAT_ffffa680 - DAT_ffffa694;
      }
    }
    else {
      arg0 = 0.0;
      arg0_00 = 0.0;
    }
  }
  else {
    arg0 = (float)lookup_2d_descriptor_scaled(DAT_ffffa678,&DAT_00069ffc);
    arg0_00 = (float)lookup_2d_descriptor_scaled(uVar6,&DAT_0006a010);
  }
  DAT_ffffa67c = rx8_max_float(arg0,arg1);
  DAT_ffffa680 = rx8_max_float(arg0_00,arg1);
  DAT_ffffa69e = cVar3;
  DAT_ffffa6a1 = cVar1;
  DAT_ffffa6a2 = cVar2;
  return;
}


