/* ROM address: 0x0005a652; body bytes: 198; decompiled */

undefined4 FUN_0005a652(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x10);
  if ((((DAT_ffffd29c == '\0') || (DAT_ffffd298 == '\0')) || (DAT_ffffd295 == '\x01')) ||
     ((DAT_ffffd28f == ' ' || (0x6ddd < DAT_ffffd28a)))) {
    DAT_ffffd28f = '\0';
  }
  else if ((DAT_ffffd28f == '\0') && (DAT_ffffd292 == '\x01')) {
    DAT_ffffd28f = '\x10';
  }
  else if ((DAT_ffffd28f == '\x10') && (DAT_ffffcfb5 == '\x01')) {
    DAT_ffffd28f = ' ';
  }
  if (DAT_ffffd28f == '\0') {
    DAT_ffffd2ab = 0;
  }
  DAT_ffffd292 = 0;
  DAT_ffffd295 = 0;
  uVar1 = FUN_00003934(uVar1);
  if (DAT_ffffd28f == '\0') {
    DAT_ffffd28a = 0;
  }
  else if (DAT_ffffd28a != 0xffff) {
    DAT_ffffd28a = DAT_ffffd28a + 1;
  }
  return uVar1;
}


