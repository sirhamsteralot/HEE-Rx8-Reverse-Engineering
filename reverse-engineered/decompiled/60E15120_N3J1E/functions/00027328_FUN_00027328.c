/* ROM address: 0x00027328; body bytes: 62; decompiled */

int FUN_00027328(void)

{
  int iVar1;
  float extraout_fr0;
  
  iVar1 = lookup_2d_descriptor_scaled(open_loop_fuel_target_ffffb120,&PTR_PTR_0006a6ac);
  DAT_ffffba0c = extraout_fr0;
  if ((DAT_ffffaa70 < extraout_fr0) || (iVar1 = (int)DAT_ffffb0ca, iVar1 != 0)) {
    DAT_ffffba18 = 0;
  }
  else {
    iVar1 = rx8_add_u8_saturate((int)DAT_ffffba18,1);
    DAT_ffffba18 = (char)iVar1;
  }
  return iVar1;
}


