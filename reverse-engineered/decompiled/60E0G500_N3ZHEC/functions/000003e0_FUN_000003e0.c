/* ROM address: 0x000003e0; body bytes: 24; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_000003e0(void)

{
  int iVar1;
  
  iVar1 = (uint)_DAT_ffffdfb4 - (uint)DAT_ffffdfb6;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 100;
  }
  return iVar1;
}


