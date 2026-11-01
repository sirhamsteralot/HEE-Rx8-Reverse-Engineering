/* ROM address: 0x00033714; body bytes: 76; decompiled */

int FUN_00033714(void)

{
  int iVar1;
  
  if (((DAT_ffffcd4e & 0x40) == 0) && ((DAT_ffffcd4e & 0x20) == 0)) {
    iVar1 = -((((int)(char)DAT_ffffcd4e & 0x80U) == 0) - 1);
    if (iVar1 == 1) {
      DAT_ffffc04d = 2;
    }
    else {
      DAT_ffffc04d = 0;
    }
  }
  else {
    iVar1 = 1;
    DAT_ffffc04d = 8;
  }
  return iVar1;
}


