/* ROM address: 0x0000d408; body bytes: 68; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000d408 (68 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0000d408(void)

{
  uint uVar1;
  
  if (DAT_ffff8000 != -0x55ab) {
    DAT_ffffa3fb = 1;
  }
  if (DAT_ffffa3fb == 0) {
    thunk_FUN_00011492_00009f4c();
  }
  if (DAT_ffffa3fb == 1) {
    DAT_ffff8000 = 0x55aa;
    uVar1 = thunk_FUN_0000abfa_00009f58();
    return uVar1;
  }
  return (uint)DAT_ffffa3fb;
}


