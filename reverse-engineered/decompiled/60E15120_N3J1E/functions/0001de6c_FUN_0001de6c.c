/* ROM address: 0x0001de6c; body bytes: 464; decompiled */

void FUN_0001de6c(void)

{
  if (((((fuel_cut_allowed_ffffa964 == '\x01') || (DAT_ffffc99c == '\x01')) || (DAT_ffffcc71 == '\x01')) ||
      ((DAT_ffffca45 == '\x01' || (DAT_ffffcdbe == '\x01')))) ||
     ((DAT_ffffcdbf == '\x01' || ((DAT_ffffcdc0 == '\x01' || (DAT_ffffcdc1 == '\x01')))))) {
    DAT_ffffb0c8 = '\x01';
  }
  else {
    if (((fuel_cut_flag_a_ffffa444 == '\x01') ||
        ((rev_limit_state_a_ffffa4a4 == '\x01' || ((DAT_ffffbc83 != 0 && (DAT_ffffbc83 < 5)))))) ||
       ((DAT_ffffcc70 != 0 && (DAT_ffffcc70 < 5)))) {
      DAT_ffffb0c8 = '\x01';
    }
    else {
      DAT_ffffb0c8 = '\0';
    }
    if ((((fuel_cut_flag_b_ffffa445 != '\x01') && (rev_limit_state_b_ffffa4a5 != '\x01')) &&
        ((DAT_ffffbc83 < 3 || (4 < DAT_ffffbc83)))) && ((DAT_ffffcc70 < 3 || (4 < DAT_ffffcc70)))) {
      DAT_ffffb0c9 = '\0';
      goto LAB_0001dfa6;
    }
  }
  DAT_ffffb0c9 = '\x01';
LAB_0001dfa6:
  if ((DAT_ffffb0c8 == '\x01') || (DAT_ffffb0c9 == '\x01')) {
    DAT_ffffb0ca = 1;
  }
  else {
    DAT_ffffb0ca = 0;
  }
  if ((DAT_ffffb0c8 == '\x01') && (DAT_ffffb0c9 == '\x01')) {
    DAT_ffffb0cb = 1;
  }
  else {
    DAT_ffffb0cb = 0;
  }
  if ((fuel_cut_flag_a_ffffa444 == '\x01') || (fuel_cut_flag_b_ffffa445 == '\x01')) {
    DAT_ffffb0cc = 1;
  }
  else {
    DAT_ffffb0cc = 0;
  }
  if ((fuel_cut_flag_a_ffffa444 == '\x01') && (fuel_cut_flag_b_ffffa445 == '\x01')) {
    DAT_ffffb0cd = 1;
  }
  else {
    DAT_ffffb0cd = 0;
  }
  if ((rev_limit_state_a_ffffa4a4 == '\x01') || (rev_limit_state_b_ffffa4a5 == '\x01')) {
    DAT_ffffb0ce = 1;
  }
  else {
    DAT_ffffb0ce = 0;
  }
  if ((rev_limit_state_a_ffffa4a4 == '\x01') && (rev_limit_state_b_ffffa4a5 == '\x01')) {
    DAT_ffffb0cf = 1;
  }
  else {
    DAT_ffffb0cf = 0;
  }
  FUN_0000e2d4(1);
  return;
}


