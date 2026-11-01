/* ROM address: 0x0000d44c; body bytes: 32; decompiled */

uint FUN_0000d44c(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffa3fb;
  if (uVar1 == 1) {
    uVar1 = thunk_FUN_00011404();
    DAT_ffff8000 = 0xaa55;
  }
  return uVar1;
}


