/* ROM address: 0x0006822c; body bytes: 142; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0006822c(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (((&DAT_ffff8fc8)[uVar1 * 5] == param_1) && (uVar1 != DAT_ffff8fdc)) {
      _DAT_ffff8fe0 = FUN_00002430(uVar1);
      return 0;
    }
    if (((&DAT_ffff8fc8)[uVar1 * 5] == -1) && (uVar1 != DAT_ffff8fdc)) break;
    uVar1 = uVar1 + 1;
    if (1 < (int)uVar1) {
      return 3;
    }
  }
  _DAT_ffff8fe0 = FUN_00002430(uVar1);
  return 1;
}


