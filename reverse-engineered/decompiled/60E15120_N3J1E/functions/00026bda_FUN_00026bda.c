/* [ADDITIONAL SOURCE REVIEW]
 * misfire_load_delta_gate [medium]: DAT_ffffb6b0 = lookup_2d(rpm, tbl 0x6a658 when DAT_ffffba5c < 0x33 else 0x6a66c [18 cells, 500..9000 rpm, raw 26 = x0.203]); if engine_load_delta 0xffffc150 < b6b0: b6aa pulse (set 1 when b6b8==0, else b6b8-- and clear), else b6b8=0, b6aa=0. Called from 0x287aa.
 */
/* ROM address: 0x00026bda; body bytes: 98; decompiled */

undefined4 candidate_misfire_load_delta_gate(void)

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


