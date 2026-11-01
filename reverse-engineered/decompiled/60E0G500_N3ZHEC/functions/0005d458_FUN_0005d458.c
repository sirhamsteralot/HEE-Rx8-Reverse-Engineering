/* ROM address: 0x0005d458; body bytes: 226; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0005d458(undefined4 param_1)

{
  uint uVar1;
  
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == 0x91a) {
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd365 = 0;
      }
      else {
        DAT_ffffd365 = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == 7) {
          _DAT_ffffd38d = DAT_ffffd352;
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd365 = 0;
      }
    }
  }
  uVar1 = (uint)DAT_ffffd365;
  if (uVar1 == 0) {
    uVar1 = FUN_00002490(param_1,0x3b000000,0);
    _DAT_ffffd38d = (undefined2)uVar1;
  }
  else if ((uVar1 == 5) || (uVar1 == 7)) {
    uVar1 = FUN_000024c0(0x3b000000,0,_DAT_ffffd38d);
  }
  return uVar1;
}


