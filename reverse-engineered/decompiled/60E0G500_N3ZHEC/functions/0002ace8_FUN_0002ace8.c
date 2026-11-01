/* ROM address: 0x0002ace8; body bytes: 58; decompiled */

byte FUN_0002ace8(void)

{
  byte bVar1;
  
  if ((((DAT_ffffbb7f & 0x80) == 0x80) || (bVar1 = DAT_ffffbb7f & 0x40, bVar1 == 0x40)) ||
     (DAT_ffffaa10 <= 0.0)) {
    bVar1 = 0;
    DAT_ffffbbb2 = 0;
  }
  else {
    DAT_ffffbbb2 = 1;
  }
  return bVar1;
}


