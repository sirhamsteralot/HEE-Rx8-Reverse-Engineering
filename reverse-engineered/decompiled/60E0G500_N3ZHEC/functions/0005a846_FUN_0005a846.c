/* ROM address: 0x0005a846; body bytes: 136; decompiled */

int FUN_0005a846(void)

{
  int iVar1;
  
  if (((DAT_ffffcd4c & 0x40) == 0) && ((DAT_ffffcd4c & 0x20) == 0)) {
    if ((((DAT_ffffcd4c & 0x10) == 0) && ((DAT_ffffcd4c & 8) == 0)) && ((DAT_ffffcd4c & 4) == 0)) {
      iVar1 = -((((int)(char)DAT_ffffcd4c & 0x80U) == 0) - 1);
      if (iVar1 == 1) {
        DAT_ffffd2c5 = 0x68;
      }
      else {
        DAT_ffffd2c5 = 0;
      }
    }
    else {
      iVar1 = 1;
      DAT_ffffd2c5 = 0x69;
    }
  }
  else {
    iVar1 = 1;
    DAT_ffffd2c5 = 0x6d;
  }
  return iVar1;
}


