/* ROM address: 0x00026bda; body bytes: 98; decompiled */

undefined4 FUN_00026bda(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  float extraout_fr0;
  
  if (DAT_ffffba5c < 0x33) {
    puVar2 = &DAT_0006a658;
  }
  else {
    puVar2 = &DAT_0006a66c;
  }
  uVar1 = lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,puVar2);
  DAT_ffffb6b0 = extraout_fr0;
  if (engine_load_delta_ffffc150 < extraout_fr0) {
    if (DAT_ffffb6b8 == 0) {
      DAT_ffffb6aa = 1;
    }
    else {
      DAT_ffffb6aa = 0;
      DAT_ffffb6b8 = DAT_ffffb6b8 + -1;
    }
  }
  else {
    DAT_ffffb6b8 = 0;
    DAT_ffffb6aa = 0;
  }
  return uVar1;
}


