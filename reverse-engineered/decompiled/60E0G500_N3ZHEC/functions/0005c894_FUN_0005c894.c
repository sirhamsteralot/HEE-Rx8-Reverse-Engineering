/* ROM address: 0x0005c894; body bytes: 224; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0005c894(undefined4 param_1)

{
  uint uVar1;
  
  if (DAT_ffffd355 == '\0') {
    if (DAT_ffffd350 == -0x16f7) {
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd355 = '\x02';
        DAT_ffffd358 = 0;
      }
      else {
        DAT_ffffd358 = DAT_ffffd354;
        DAT_ffffd355 = '\x01';
        if (DAT_ffffd354 == 7) {
          _DAT_ffffd373 = DAT_ffffd352;
        }
      }
    }
    else {
      DAT_ffffd355 = '\0';
      if ((DAT_ffffd3a8 & 0xc0) == 0) {
        DAT_ffffd358 = 0;
      }
    }
  }
  uVar1 = (uint)DAT_ffffd358;
  if (uVar1 == 0) {
    uVar1 = FUN_00002490(param_1,0x3b480000,0);
    _DAT_ffffd373 = (undefined2)uVar1;
  }
  else if ((uVar1 == 5) || (uVar1 == 7)) {
    uVar1 = FUN_000024c0(0x3b480000,0,_DAT_ffffd373);
  }
  return uVar1;
}


