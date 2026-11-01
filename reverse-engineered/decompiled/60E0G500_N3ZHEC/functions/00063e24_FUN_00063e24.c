/* ROM address: 0x00063e24; body bytes: 134; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00063e24(short param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (((&DAT_ffff8930)[uVar1 * 0x1a] == param_1) && (uVar1 != DAT_ffff8d74)) {
      _DAT_ffff8d78 = FUN_00002430(uVar1);
      return 0;
    }
    if (((&DAT_ffff8937)[uVar1 * 0x34] == '\0') && (uVar1 != DAT_ffff8d74)) break;
    uVar1 = uVar1 + 1;
    if (0x14 < (int)uVar1) {
      return 3;
    }
  }
  _DAT_ffff8d78 = FUN_00002430(uVar1);
  return 1;
}


