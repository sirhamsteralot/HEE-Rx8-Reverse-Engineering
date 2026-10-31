/* ROM address: 0x00027390; body bytes: 68; decompiled */

int FUN_00027390(void)

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


