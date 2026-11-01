/* ROM address: 0x00015984; body bytes: 208; decompiled */

uint FUN_00015984(byte param_1)

{
  uint uVar1;
  uint extraout_r0;
  float extraout_fr0;
  
  uVar1 = (uint)param_1;
  if ((uVar1 == (DAT_ffffb5a4 == '\0')) || (DAT_ffffaada == '\0')) {
    DAT_ffffa7c8 = 0;
    DAT_ffffa7dc = 500.0;
    DAT_ffffa7e0 = 500.0;
  }
  else {
    uVar1 = (uint)DAT_ffffa428;
    if ((uVar1 == 1) && (DAT_ffffa83c == '\0')) {
      DAT_ffffa7c8 = 1;
      DAT_ffffa7dc = 500.0;
      uVar1 = FUN_00002068(DAT_ffffaa14,&DAT_00069aa4);
      DAT_ffffa7e0 = extraout_fr0;
    }
    else {
      DAT_ffffa7c8 = (bool)param_1 != (DAT_ffffb5a4 == '\0');
      if ((bool)DAT_ffffa7c8) {
        DAT_ffffa7dc = DAT_ffffa7e0;
      }
      else {
        DAT_ffffa7dc = 500.0;
      }
      if (DAT_ffffa82a == 0) {
        DAT_ffffa7e0 = rx8_max_float(DAT_ffffa7e0 - 1.6,500.0);
        uVar1 = extraout_r0;
      }
    }
  }
  return uVar1;
}


