/* ROM address: 0x00032e8c; body bytes: 70; decompiled */

uint FUN_00032e8c(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffbd59;
  if ((((uVar1 != 1) || (uVar1 = (uint)(char)DAT_ffffc036, uVar1 != 0)) ||
      (uVar1 = (uint)DAT_ffffbca2, uVar1 != 1)) || (6.4 < DAT_ffffc00c - DAT_ffffc008)) {
    DAT_ffffc020 = 0;
  }
  else {
    DAT_ffffc020 = 1;
  }
  DAT_ffffc036 = DAT_ffffbca2;
  return uVar1;
}


