/* ROM address: 0x00067cbc; body bytes: 152; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00067cbc(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (((&DAT_ffff8ec8)[uVar1 * 0x14] == param_1) && (uVar1 != DAT_ffff8fc0)) {
      _DAT_ffff8fc4 = FUN_00002430(uVar1);
      return 0;
    }
    if (((&DAT_ffff8ec8)[uVar1 * 0x14] == -1) && (uVar1 != DAT_ffff8fc0)) break;
    uVar1 = uVar1 + 1;
    if (6 < (int)uVar1) {
      return 3;
    }
  }
  _DAT_ffff8fc4 = FUN_00002430(uVar1);
  return 1;
}


