/* ROM address: 0x0006123a; body bytes: 104; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0006123a(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = FUN_00063a2e(0);
  while (cVar1 == '\x01') {
    if (DAT_ffffd7d3 == -0x40) {
      if (iVar2 == 0) {
        iVar2 = 0xc0;
      }
    }
    else if (DAT_ffffd7d3 == -0x80) {
      iVar2 = 0x80;
    }
    cVar1 = FUN_00063a2e(1);
  }
  _DAT_ffff87a8 = FUN_00002420(iVar2);
  return;
}


