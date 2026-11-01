/* ROM address: 0x00043bc8; body bytes: 48; decompiled */

undefined4 * FUN_00043bc8(void)

{
  undefined4 *puVar1;
  
  if (DAT_ffffc008 < 400.0) {
    puVar1 = &DAT_00043c40;
    if (DAT_ffffc008 <= 0.0) {
      DAT_ffffcaa0 = 1.0;
    }
    else {
      DAT_ffffcaa0 = DAT_ffffc008 * 34.7416;
    }
  }
  else {
    puVar1 = &DAT_00043c44;
    DAT_ffffcaa0 = 10000.0;
  }
  return puVar1;
}


