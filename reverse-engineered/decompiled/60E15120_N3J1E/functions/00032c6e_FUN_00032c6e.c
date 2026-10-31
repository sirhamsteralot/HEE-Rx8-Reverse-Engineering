/* ROM address: 0x00032c6e; body bytes: 142; decompiled */

int FUN_00032c6e(void)

{
  int iVar1;
  
  if (((int)(char)DAT_ffffcd0c & 0x80U) == 0) {
    if ((DAT_ffffcd0c & 0x10) == 0) {
      if ((DAT_ffffcd0c & 0x20) == 0) {
        if ((DAT_ffffcd0c & 8) == 0) {
          if ((DAT_ffffcd0c & 2) == 0) {
            iVar1 = -(((DAT_ffffcd0c & 4) == 0) - 1);
            if (iVar1 == 1) {
              DAT_ffffbff3 = 6;
            }
            else {
              DAT_ffffbff3 = 7;
            }
          }
          else {
            DAT_ffffbff3 = 5;
            iVar1 = 1;
          }
        }
        else {
          DAT_ffffbff3 = 4;
          iVar1 = 1;
        }
      }
      else {
        DAT_ffffbff3 = 3;
        iVar1 = 1;
      }
    }
    else {
      DAT_ffffbff3 = 2;
      iVar1 = 1;
    }
  }
  else {
    DAT_ffffbff3 = 1;
    iVar1 = 1;
  }
  return iVar1;
}


