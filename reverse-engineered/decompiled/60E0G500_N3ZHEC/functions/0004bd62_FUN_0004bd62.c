/* ROM address: 0x0004bd62; body bytes: 178; decompiled */

uint FUN_0004bd62(void)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_ffffc724 == '\0') {
    DAT_ffffce70 = (float)FUN_0003eb72(DAT_ffff9f70,&DAT_ffff8088);
  }
  else {
    DAT_ffffce70 = rx8_max_float(DAT_ffffaa10,5.0);
  }
  FUN_00038cc0(0x7a,2);
  FUN_00038ed8(0x7a,&DAT_ffffce6c,2);
  DAT_ffffce82 = DAT_ffffce6c;
  DAT_ffffce74 = 0;
  uVar2 = ((int)DAT_ffffce6c & (uint)&PTR_FUN_0000ff00) >> 8;
  uVar1 = 0x32;
  if (((uVar2 < 0x32) && (uVar1 = 0xcd, 0xcd < ((int)DAT_ffffce6c & 0xffU))) &&
     (uVar1 = 0xff, (uVar2 + (int)DAT_ffffce6c & 0xff) == 0xff)) {
    DAT_ffffce6f = 1;
    uVar1 = FUN_00002460((int)DAT_ffffce6c,0xff);
    if ((uVar1 & 0xffff) < (int)&PTR_FUN_0000ff00 + 1U) {
      DAT_ffffce6c = (short)uVar1;
      return uVar1;
    }
  }
  else {
    DAT_ffffce6f = 0;
  }
  DAT_ffffce6c = 0xff00;
  return uVar1;
}


