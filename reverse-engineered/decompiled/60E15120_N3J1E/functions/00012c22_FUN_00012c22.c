/* ROM address: 0x00012c22; body bytes: 108; decompiled */

undefined1 * FUN_00012c22(void)

{
  undefined1 *puVar1;
  
  puVar1 = &cranking_active_ffffaa62_ffffaa62;
  if (cranking_active_ffffaa62_ffffaa62 == '\0') {
    DAT_ffffa686 = '\0';
  }
  else if ((((DAT_ffffa6a3 == '\x01') && (puVar1 = (undefined1 *)0x0, fuel_cut_flag_a_ffffa444 == '\0')) ||
           ((puVar1 = (undefined1 *)(uint)DAT_ffffa6a4, puVar1 == (undefined1 *)0x1 &&
            (fuel_cut_flag_b_ffffa445 == '\0')))) && (DAT_ffffb53a == '\0')) {
    puVar1 = (undefined1 *)0x0;
    DAT_ffffa686 = '\0';
  }
  else if (DAT_ffffa686 != '\0') {
    DAT_ffffa686 = DAT_ffffa686 + -1;
  }
  DAT_ffffa6a3 = fuel_cut_flag_a_ffffa444;
  DAT_ffffa6a4 = fuel_cut_flag_b_ffffa445;
  return puVar1;
}


