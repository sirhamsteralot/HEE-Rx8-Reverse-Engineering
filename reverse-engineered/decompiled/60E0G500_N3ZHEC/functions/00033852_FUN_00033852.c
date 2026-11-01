/* ROM address: 0x00033852; body bytes: 142; decompiled */

int FUN_00033852(void)

{
  int iVar1;
  
  if (((int)(char)DAT_ffffcd4c & 0x80U) == 0) {
    if ((DAT_ffffcd4c & 0x10) == 0) {
      if ((DAT_ffffcd4c & 0x20) == 0) {
        if ((DAT_ffffcd4c & 8) == 0) {
          if ((DAT_ffffcd4c & 2) == 0) {
            iVar1 = -(((DAT_ffffcd4c & 4) == 0) - 1);
            if (iVar1 == 1) {
              DAT_ffffc05b = 6;
            }
            else {
              DAT_ffffc05b = 7;
            }
          }
          else {
            DAT_ffffc05b = 5;
            iVar1 = 1;
          }
        }
        else {
          DAT_ffffc05b = 4;
          iVar1 = 1;
        }
      }
      else {
        DAT_ffffc05b = 3;
        iVar1 = 1;
      }
    }
    else {
      DAT_ffffc05b = 2;
      iVar1 = 1;
    }
  }
  else {
    DAT_ffffc05b = 1;
    iVar1 = 1;
  }
  return iVar1;
}


