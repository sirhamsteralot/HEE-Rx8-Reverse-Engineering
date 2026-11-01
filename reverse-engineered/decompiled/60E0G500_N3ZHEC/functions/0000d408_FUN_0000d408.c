/* ROM address: 0x0000d408; body bytes: 68; decompiled */

uint FUN_0000d408(void)

{
  uint uVar1;
  
  if (DAT_ffff8000 != -0x55ab) {
    DAT_ffffa3fb = 1;
  }
  if (DAT_ffffa3fb == 0) {
    thunk_FUN_000114de();
  }
  if (DAT_ffffa3fb == 1) {
    DAT_ffff8000 = 0x55aa;
    uVar1 = thunk_FUN_0000abfa();
    return uVar1;
  }
  return (uint)DAT_ffffa3fb;
}


