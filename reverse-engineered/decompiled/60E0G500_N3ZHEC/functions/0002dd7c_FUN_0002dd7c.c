/* ROM address: 0x0002dd7c; body bytes: 60; decompiled */

void FUN_0002dd7c(void)

{
  undefined4 uVar1;
  
  if ((DAT_ffffbd45 < 5) && (DAT_ffffbd46 < 5)) {
    DAT_ffffbd44 = '\0';
  }
  else {
    DAT_ffffbd44 = '\x01';
  }
  if (DAT_ffffbd44 == '\x01') {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  FUN_000604dc(0x40,uVar1);
  return;
}


