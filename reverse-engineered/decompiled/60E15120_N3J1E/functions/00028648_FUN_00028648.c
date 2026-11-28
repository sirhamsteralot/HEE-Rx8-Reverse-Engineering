/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006a608: Table 2D - 156 (RX8Defs data pointer, axes and dimensions match).
 */
/* [ADDITIONAL SOURCE REVIEW]
 * misfire_threshold_b_calc [high]: Same shape as 0x2853c for the secondary threshold: DAT_ffffba80 = DAT_ffffba7c (delay); 3D tbl 0x6a644 (10x17, data 6..125) x coolant tbl 0x6a608/0x6a61c -> ba7c (ba90 = corr) when ba60, else ba98 + ba8c*fVar4 with 40.0 constants (pools 0x2873c=0x74d44, 0x28740=0x74d48). Pools verified: 0x28720=0x6a644, 0x28730=0x6a608, 0x28734=0x6a61c. Called from 0x287aa.
 * RAM 0xffffba80 misfire_threshold_b (float): Secondary threshold (delayed ba7c): 3D tbl 0x6a644 x coolant tbl 0x6a608/0x6a61c when ba60, computed by 0x28648; compared against ba50 in 0x28022.
 */
/* ROM address: 0x00028648; body bytes: 194; decompiled */

uint misfire_threshold_b_calc(void)

{
  uint uVar1;
  float *pfVar2;
  undefined *puVar3;
  float fVar4;
  float extraout_fr0;
  
  misfire_threshold_b_ffffba80 = DAT_ffffba7c;
  fVar4 = (float)lookup_3d_descriptor_scaled(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&DAT_0006a644);
  if (misfire_high_rpm_active_ffffba60 != '\0') {
    if (DAT_ffffb53a == '\x01') {
      puVar3 = &tbl_table_2d_156_0006a608;
    }
    else {
      puVar3 = &DAT_0006a61c;
    }
    uVar1 = lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,puVar3);
    DAT_ffffba7c = extraout_fr0 * fVar4;
    DAT_ffffba90 = extraout_fr0;
    return uVar1;
  }
  if (DAT_ffffb53a == '\x01') {
    puVar3 = &tbl_table_2d_156_0006a608;
  }
  else {
    puVar3 = &DAT_0006a61c;
  }
  DAT_ffffba8c = (float)lookup_2d_descriptor_scaled(puVar3);
  if (DAT_ffffa6b7 == '\x01') {
    pfVar2 = (float *)&DAT_00074d44;
  }
  else {
    if (DAT_ffffa6b8 != '\x01') {
      uVar1 = (uint)DAT_ffffa6b9;
      DAT_ffffba98 = 0.0;
      goto LAB_000286d4;
    }
    pfVar2 = (float *)&DAT_00074d48;
  }
  uVar1 = 1;
  DAT_ffffba98 = *pfVar2;
LAB_000286d4:
  DAT_ffffba7c = DAT_ffffba98 + DAT_ffffba8c * fVar4;
  return uVar1;
}


