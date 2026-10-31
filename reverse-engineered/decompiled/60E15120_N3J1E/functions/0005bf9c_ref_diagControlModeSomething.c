/* ROM address: 0x0005bf9c; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005a78c (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_diagControlModeSomething(void)

{
  uint uVar1;
  
  uVar1 = (uint)engine_stopped_latch_ffffa41c;
  if (uVar1 == 1) {
    if ((DAT_ffffd36c & 0x60) == 0) {
      if (DAT_ffffd314 == 0x17e0) {
        DAT_ffffd319 = 2;
      }
      DAT_ffffd31b = 0;
    }
    uVar1 = 0x198;
    if ((DAT_ffffd36c & 0x60) == 0) {
      if (DAT_ffffd314 == 0x17df) {
        DAT_ffffd319 = 2;
      }
      uVar1 = 0x19c;
      DAT_ffffd334 = 0;
    }
  }
  return uVar1;
}


