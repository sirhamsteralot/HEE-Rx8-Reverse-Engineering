/* ROM address: 0x0005a7c4; body bytes: 130; decompiled */

int FUN_0005a7c4(void)

{
  int iVar1;
  
  if (((((DAT_ffffcd4c & 0x40) == 0) && ((DAT_ffffcd4c & 0x20) == 0)) &&
      ((DAT_ffffcd4c & 0x10) == 0)) && (((DAT_ffffcd4c & 8) == 0 && ((DAT_ffffcd4c & 4) == 0)))) {
    iVar1 = -((((int)(char)DAT_ffffcd4c & 0x80U) == 0) - 1);
    if (iVar1 == 1) {
      DAT_ffffd2c4 = 6;
    }
    else {
      DAT_ffffd2c4 = 0;
    }
  }
  else {
    iVar1 = 1;
    DAT_ffffd2c4 = 7;
  }
  return iVar1;
}


