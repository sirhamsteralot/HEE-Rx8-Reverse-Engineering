/* ROM address: 0x0000e2d4; body bytes: 324; decompiled */

int FUN_0000e2d4(void)

{
  int iVar1;
  
  DAT_ffffa430 = 0;
  if ((((fuel_cut_flag_a_ffffa444 == '\x01') || (rev_limit_state_a_ffffa4a4 == '\x01')) || (fuel_cut_allowed_ffffa964 == '\x01')) ||
     ((((DAT_ffffc99c == '\x01' || (DAT_ffffcc71 == '\x01')) ||
       ((DAT_ffffbc86 == '\x01' || ((DAT_ffffcc72 == '\x01' || (DAT_ffffca45 == '\x01')))))) ||
      ((DAT_ffffcdbe == '\x01' ||
       ((((DAT_ffffcdbf == '\x01' || (DAT_ffffcdc0 == '\x01')) || (DAT_ffffcdc1 == '\x01')) ||
        (inferred_ram_c1d0_ffffc1d0_ffffc1d0 == '\0')))))))) {
    DAT_ffffa430 = 1;
  }
  iVar1 = 1;
  if (((fuel_cut_flag_b_ffffa445 == '\x01') || (iVar1 = 1, rev_limit_state_b_ffffa4a5 == '\x01')) ||
     ((((iVar1 = 1, fuel_cut_allowed_ffffa964 == '\x01' ||
        ((iVar1 = 1, DAT_ffffc99c == '\x01' || (iVar1 = 1, DAT_ffffcc71 == '\x01')))) ||
       (iVar1 = 1, DAT_ffffbc87 == '\x01')) ||
      ((((iVar1 = 1, DAT_ffffcc73 == '\x01' || (iVar1 = 1, DAT_ffffca45 == '\x01')) ||
        (iVar1 = 1, DAT_ffffcdbe == '\x01')) ||
       (((iVar1 = 1, DAT_ffffcdbf == '\x01' || (iVar1 = 1, DAT_ffffcdc0 == '\x01')) ||
        ((iVar1 = 1, DAT_ffffcdc1 == '\x01' || (iVar1 = (int)inferred_ram_c1d0_ffffc1d0_ffffc1d0, iVar1 == 0)))))))))) {
    DAT_ffffa430 = DAT_ffffa430 | 2;
  }
  return iVar1;
}


