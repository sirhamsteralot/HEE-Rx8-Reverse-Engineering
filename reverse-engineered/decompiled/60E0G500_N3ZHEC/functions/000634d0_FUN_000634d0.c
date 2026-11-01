/* ROM address: 0x000634d0; body bytes: 130; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000634d0(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (((&DAT_ffff87d8)[uVar1 * 8] == param_1) && (uVar1 != DAT_ffff8928)) {
      _DAT_ffff892c = FUN_00002430(uVar1);
      return 0;
    }
    if (((&DAT_ffff87d8)[uVar1 * 8] == -1) && (uVar1 != DAT_ffff8928)) break;
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 3;
    }
  }
  _DAT_ffff892c = FUN_00002430(uVar1);
  return 1;
}


