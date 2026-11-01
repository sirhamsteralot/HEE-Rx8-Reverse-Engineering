/* ROM address: 0x00062e0c; body bytes: 108; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00062e0c(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 1;
  if (DAT_ffff87d2 == '\x02') {
    iVar3 = (int)DAT_ffff87c4;
    _DAT_ffff87d2 = FUN_00002420(1);
    cVar1 = FUN_00067cbc(iVar3);
    if (cVar1 == '\0') {
      FUN_00067d66(iVar3);
    }
    else if (cVar1 == '\x01') {
      FUN_000680c0(iVar3);
    }
  }
  else if (DAT_ffff87d2 == '\x01') {
    uVar2 = 0;
  }
  else {
    _DAT_ffff87d2 = FUN_00002420(1);
  }
  return uVar2;
}


