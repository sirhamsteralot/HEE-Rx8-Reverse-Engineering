/* ROM address: 0x00062e78; body bytes: 116; decompiled */

undefined4 FUN_00062e78(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (DAT_ffff87d4._0_1_ == '\x02') {
    DAT_ffff87c8 = FUN_00002430(param_1);
    DAT_ffff87d4 = FUN_00002420(1);
    cVar1 = FUN_0006822c(param_1);
    if (cVar1 == '\0') {
      FUN_000682cc(param_1);
    }
    else if (cVar1 == '\x01') {
      FUN_00068466(param_1);
    }
  }
  else if (DAT_ffff87d4._0_1_ == '\x01') {
    uVar2 = 0;
  }
  else {
    DAT_ffff87d4 = FUN_00002420(1);
  }
  return uVar2;
}


