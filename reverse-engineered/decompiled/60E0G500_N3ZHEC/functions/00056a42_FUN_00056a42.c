/* ROM address: 0x00056a42; body bytes: 110; decompiled */

undefined4 FUN_00056a42(void)

{
  char cVar1;
  
  if (((0.64 <= DAT_ffffaa80) || (DAT_ffffaa08 <= 4.8)) || ((DAT_ffff9ec8 & 0x20) == 0)) {
    DAT_ffffd209 = 0;
  }
  else {
    DAT_ffffd209 = 1;
  }
  cVar1 = FUN_000565e2(4);
  if ((cVar1 == '\0') && (cVar1 = FUN_00056678(1), cVar1 == '\0')) {
    DAT_ffffd20a = 1;
  }
  else {
    DAT_ffffd20a = 0;
  }
  return 0;
}


