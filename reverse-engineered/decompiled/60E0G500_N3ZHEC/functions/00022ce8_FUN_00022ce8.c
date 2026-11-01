/* ROM address: 0x00022ce8; body bytes: 200; decompiled */

uint evap_open_loop_condition(void)

{
  char cVar1;
  uint uVar2;
  uint extraout_r0;
  
  cVar1 = DAT_ffffae97;
  if ((((DAT_ffffb388 != '\x01') || (DAT_ffffb19c != '\x01')) || (DAT_ffffbe6c < 66.5)) ||
     (((DAT_ffffae97 != '\0' || (DAT_ffffb366 != '\0')) ||
      ((DAT_ffffb138 != '\0' || (DAT_ffffb139 != '\0')))))) {
    DAT_ffffb389 = 0;
  }
  else {
    DAT_ffffb389 = 1;
  }
  uVar2 = (uint)DAT_ffffb389;
  if (uVar2 == 1) {
    DAT_ffffb378 = rx8_min_float(DAT_ffffb378 + 0.0,0.0);
    uVar2 = extraout_r0;
  }
  else {
    DAT_ffffb378 = 0.0;
  }
  if (cVar1 == '\0') {
    uVar2 = FUN_00002460((int)DAT_ffffb39a,1);
    DAT_ffffb39a = (short)uVar2;
  }
  else {
    DAT_ffffb39a = 0;
  }
  return uVar2;
}


