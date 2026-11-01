/* ROM address: 0x00044312; body bytes: 190; decompiled */

uint FUN_00044312(void)

{
  uint uVar1;
  
  if ((DAT_ffffcabb == '\x01') || (DAT_ffffcab9 == '\x01')) {
    uVar1 = 1;
    DAT_ffffcab5 = 0;
  }
  else {
    uVar1 = (uint)DAT_ffffcab4;
    if (((uVar1 != 1) || (DAT_ffffca38 < 0.01)) ||
       ((((DAT_ffffca30 < DAT_ffffca88 || (uVar1 = (uint)DAT_ffffcaac, uVar1 != 0)) &&
         ((DAT_ffffca30 < 50.0 || (DAT_ffffcaac == '\0')))) ||
        (uVar1 = (uint)DAT_ffffcab8, uVar1 != 1)))) {
      DAT_ffffcab5 = 0;
    }
    else {
      DAT_ffffcab5 = 1;
    }
  }
  if (DAT_ffffcab6 == '\0') {
    DAT_ffffcaac = '\0';
  }
  else {
    uVar1 = (uint)DAT_ffffcab5;
    if (uVar1 == 1) {
      uVar1 = FUN_00002478((int)DAT_ffffcaac,1);
      DAT_ffffcaac = (char)uVar1;
    }
  }
  return uVar1;
}


