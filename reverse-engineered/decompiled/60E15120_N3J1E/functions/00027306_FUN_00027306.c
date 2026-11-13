/* ROM address: 0x00027306; body bytes: 34; decompiled */

short FUN_00027306(void)

{
  if (sector_parity_bank_ffffb660 == 1) {
    if (DAT_ffffba04 != 0) {
      DAT_ffffba04 = DAT_ffffba04 + -1;
    }
  }
  return sector_parity_bank_ffffb660;
}


