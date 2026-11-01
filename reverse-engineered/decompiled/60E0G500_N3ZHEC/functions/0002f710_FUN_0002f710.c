/* ROM address: 0x0002f710; body bytes: 126; decompiled */

void FUN_0002f710(void)

{
  float fVar1;
  
  if (((DAT_ffffbdd8 < 0x9d) || (60.06 <= DAT_ffffbde4)) || (DAT_ffffadbc < 60.06)) {
    if (((0x9c < DAT_ffffbdd8) || (DAT_ffffadbc <= 45.045)) ||
       ((0x5e < DAT_ffffbdd8 && (DAT_ffffbe24 == '\x01')))) {
      DAT_ffffbdde = 0;
    }
  }
  else {
    DAT_ffffbdde = 1;
    DAT_ffffbdd8 = 0;
  }
  fVar1 = DAT_ffffadbc;
  DAT_ffffbdd8 = FUN_00002460((int)(short)DAT_ffffbdd8,1);
  DAT_ffffbde4 = fVar1;
  return;
}


