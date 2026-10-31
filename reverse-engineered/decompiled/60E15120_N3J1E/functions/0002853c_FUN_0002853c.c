/* ROM address: 0x0002853c; body bytes: 194; decompiled */

uint FUN_0002853c(void)

{
  uint uVar1;
  float *pfVar2;
  undefined *puVar3;
  float fVar4;
  float extraout_fr0;
  
  DAT_ffffba78 = DAT_ffffba74;
  fVar4 = (float)lookup_3d_descriptor_scaled(engine_load_ffffc0b4,engine_speed_rpm_ffffb548,&DAT_0006a630);
  if (DAT_ffffba60 != '\0') {
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


