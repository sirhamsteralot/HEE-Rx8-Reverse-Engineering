/* ROM address: 0x0003f2b4; body bytes: 58; decompiled */

void FUN_0003f2b4(void)

{
  char cVar1;
  
  cVar1 = DAT_ffffc530;
  if (((DAT_ffffc719 == '\0') && (DAT_ffffc530 == '\x01')) && (DAT_ffffc718 == '\0')) {
    FUN_0003f164();
    FUN_0003f1c0();
    DAT_ffffc718 = '\x01';
  }
  DAT_ffffc719 = cVar1;
  return;
}


