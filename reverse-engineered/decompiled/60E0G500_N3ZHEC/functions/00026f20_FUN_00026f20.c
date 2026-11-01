/* ROM address: 0x00026f20; body bytes: 264; decompiled */

void FUN_00026f20(void)

{
  float fVar1;
  
  if (DAT_ffffb600 < 10.0) {
    if (DAT_ffffb600 < 9.0) {
      DAT_ffffb6b7 = '\0';
    }
  }
  else {
    DAT_ffffb6b7 = '\x01';
  }
  if (((((8.486699 <= DAT_ffffb6c4) || (DAT_ffffb650 <= 19.531)) || (DAT_ffffa428 == '\0')) ||
      ((DAT_ffffa428 == '\x01' && (DAT_ffffb6b0 < 0x3f)))) ||
     ((DAT_ffffb6b7 == '\0' || ((DAT_ffffb6b7 == '\x01' && (DAT_ffffb6b2 < 0x3f)))))) {
    DAT_ffffb67e = 0x138;
  }
  else if (DAT_ffffb67e != 0) {
    DAT_ffffb67e = DAT_ffffb67e + -1;
  }
  fVar1 = DAT_ffffb6c4;
  if (DAT_ffffa428 == '\0') {
    DAT_ffffb6b0 = 0;
  }
  else {
    DAT_ffffb6b0 = FUN_00002460((int)(short)DAT_ffffb6b0,1);
  }
  if (DAT_ffffb6b7 == '\0') {
    DAT_ffffb6b2 = 0;
  }
  else {
    DAT_ffffb6b2 = FUN_00002460((int)(short)DAT_ffffb6b2,1);
  }
  if (DAT_ffffb67e == 0) {
    DAT_ffffb622 = 1;
  }
  else if (8.486699 <= fVar1) {
    DAT_ffffb622 = 0;
  }
  return;
}


