/* ROM address: 0x00030f78; body bytes: 94; decompiled */

void FUN_00030f78(void)

{
  if (DAT_ffffa428 == '\0') {
    if (DAT_ffffaa40 < 80.0) {
      if (((DAT_ffffaa10 < 150.0) || (DAT_ffffc656 != '\0')) || (DAT_ffffb493 != '\0')) {
        DAT_ffffbed4 = FUN_00002068(DAT_ffffadbc,&PTR_DAT_0006afac);
      }
      else {
        DAT_ffffbed4 = 0x3f800000;
      }
    }
    else {
      DAT_ffffbed4 = 0;
    }
  }
  return;
}


