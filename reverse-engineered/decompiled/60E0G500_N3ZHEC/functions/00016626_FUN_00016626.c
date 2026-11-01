/* ROM address: 0x00016626; body bytes: 120; decompiled */

void FUN_00016626(void)

{
  if ((DAT_ffffbdd5 == '\0') && (DAT_ffffa8cf == '\x01')) {
    DAT_ffffa8cc = 0;
  }
  else if (((DAT_ffffa424 < 0x80) ||
           (((DAT_ffffbc20 != '\x01' || (DAT_ffffa7c6 != '\0')) || (DAT_ffffc656 != '\0')))) ||
          (((DAT_ffffc64b != '\0' || (DAT_ffffc647 != '\0')) || (DAT_ffffc68e != '\0')))) {
    DAT_ffffa8cc = 0;
  }
  else {
    DAT_ffffa8cc = 1;
  }
  DAT_ffffa8cf = DAT_ffffbdd5;
  return;
}


