/* ROM address: 0x00030030; body bytes: 130; decompiled */

void FUN_00030030(void)

{
  float arg2;
  float arg0;
  float arg0_00;
  
  arg2 = (float)lookup_2d_descriptor_scaled(engine_speed_rpm_ffffb548,&DAT_0006aa9c);
  arg0 = DAT_ffffbde8 * DAT_ffffbe10 * DAT_ffffbec0;
  arg0_00 = DAT_ffffbdec * DAT_ffffbe14 * DAT_ffffbec4;
  DAT_ffffbe4c = rx8_clamp_float(DAT_ffffbde4 * DAT_ffffbe0c * DAT_ffffbebc,1024.0,arg2);
  DAT_ffffbe50 = rx8_clamp_float(arg0,0.0,arg2);
  DAT_ffffbe54 = rx8_clamp_float(arg0_00,0.0,arg2);
  return;
}


