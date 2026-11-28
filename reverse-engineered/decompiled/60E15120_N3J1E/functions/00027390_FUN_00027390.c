/* [ADDITIONAL SOURCE REVIEW]
 * misfire_ol_fuel_gate [medium]: DAT_ffffba0c = lookup_2d(open_loop_fuel_target 0xffffb120, tbl 0x6a6ac [5 cells, axis 0..0.5, data 1.25]); DAT_ffffba08 = 0 when DAT_ffffaa70 < ba0c || DAT_ffffb0ca != 0 || DAT_ffffba18 == 0, else 1. Called from 0x287aa.
 */
/* ROM address: 0x00027390; body bytes: 68; decompiled */

int candidate_misfire_ol_fuel_gate(void)

{
  int iVar1;
  float extraout_fr0;
  
  iVar1 = lookup_2d_descriptor_scaled(open_loop_fuel_target_ffffb120,&PTR_PTR_0006a6ac);
  DAT_ffffba0c = extraout_fr0;
  if (((DAT_ffffaa70 < extraout_fr0) || (iVar1 = (int)DAT_ffffb0ca, iVar1 != 0)) ||
     (iVar1 = 1, DAT_ffffba18 == '\0')) {
    DAT_ffffba08 = 0;
  }
  else {
    DAT_ffffba08 = 1;
  }
  return iVar1;
}


