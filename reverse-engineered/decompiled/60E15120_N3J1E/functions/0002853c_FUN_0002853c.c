/* [ADDITIONAL SOURCE REVIEW]
 * misfire_threshold_a_calc [high]: DAT_ffffba78 = DAT_ffffba74 (one-tick delay); fVar4 = lookup_3d(load 0xffffc0b4, rpm 0xffffb548, tbl 0x6a630 [10x17, x 0.16..1.1, y 780..8500, data 3.75..45.86]); coolant correction lookup_2d(coolant 0xffffa98c, tbl 0x6a5e0 when 0xffffb53a==1 else 0x6a5f4 [9 cells, -40..120 C, raw 128 = x1.0]) selected when DAT_ffffba60!=0: ba74 = corr * fVar4 (ba88 = corr), else ba74 = ba94 + ba84 * fVar4 with ba84 = same coolant table and ba94 = 40.0 (pool 0x74d38) when 0xffffa6b7, 40.0 (0x74d3c) when 0xffffa6b8, else 0.0 (0x74d40). Pools verified: 0x2861c=0x6a630, 0x2862c=0x6a5e0, 0x28630=0x6a5f4, 0x28638=0x74d38. Called from 0x287aa.
 * RAM 0xffffba78 misfire_threshold_a (float): Primary per-tick misfire threshold (one-tick delayed ba74): 3D tbl 0x6a630 (load x rpm) times a coolant correction (tbl 0x6a5e0/0x6a5f4) when ba60, else +40.0/ba94 form; computed by 0x2853c. Arm comparison ba40 > ba78 in 0x27fb4.
 */
/* ROM address: 0x0002853c; body bytes: 194; decompiled */

uint misfire_threshold_a_calc(void)

{
  uint uVar1;
  float *pfVar2;
  undefined *puVar3;
  float fVar4;
  float extraout_fr0;
  
  misfire_threshold_a_ffffba78 = DAT_ffffba74;
  fVar4 = (float)lookup_3d_descriptor_scaled(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&DAT_0006a630);
  if (misfire_high_rpm_active_ffffba60 != '\0') {
    if (DAT_ffffb53a == '\x01') {
      puVar3 = &DAT_0006a5e0;
    }
    else {
      puVar3 = &DAT_0006a5f4;
    }
    uVar1 = lookup_2d_descriptor_scaled(inferred_coolant_temperature_ffffa98c,puVar3);
    DAT_ffffba74 = extraout_fr0 * fVar4;
    DAT_ffffba88 = extraout_fr0;
    return uVar1;
  }
  if (DAT_ffffb53a == '\x01') {
    puVar3 = &DAT_0006a5e0;
  }
  else {
    puVar3 = &DAT_0006a5f4;
  }
  DAT_ffffba84 = (float)lookup_2d_descriptor_scaled(puVar3);
  if (DAT_ffffa6b7 == '\x01') {
    pfVar2 = (float *)&DAT_00074d38;
  }
  else {
    if (DAT_ffffa6b8 != '\x01') {
      uVar1 = (uint)DAT_ffffa6b9;
      DAT_ffffba94 = 0.0;
      goto LAB_000285c8;
    }
    pfVar2 = (float *)&DAT_00074d3c;
  }
  uVar1 = 1;
  DAT_ffffba94 = *pfVar2;
LAB_000285c8:
  DAT_ffffba74 = DAT_ffffba94 + DAT_ffffba84 * fVar4;
  return uVar1;
}


