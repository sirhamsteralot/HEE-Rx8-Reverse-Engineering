/* ROM address: 0x00000364; body bytes: 76; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00000364(void)

{
  int iVar1;
  
  if (DAT_ffffdfa8 == '\0') {
    iVar1 = FUN_00000210();
  }
  else {
    iVar1 = FUN_00000450(&DAT_ffffd4e0 + (uint)_DAT_ffffdfb4 * 8);
  }
  if ((iVar1 == 1) && (_DAT_ffffdfb4 = _DAT_ffffdfb4 + 1, 99 < _DAT_ffffdfb4)) {
    _DAT_ffffdfb4 = 0;
  }
  return;
}


