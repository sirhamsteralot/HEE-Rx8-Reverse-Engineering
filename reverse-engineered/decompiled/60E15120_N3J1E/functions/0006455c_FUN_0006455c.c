/* ROM address: 0x0006455c; body bytes: 126; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062e4c (126 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0006455c(void)

{
  uint uVar1;
  char cVar2;
  
  DAT_ffffd7b2 = FUN_000630b8(1);
  uVar1 = (uint)DAT_ffff8e7c;
  if (uVar1 == 1) {
    cVar2 = FUN_000678b4(0);
    if (cVar2 != '\0') {
      FUN_000623a0(0);
      FUN_00062668();
      FUN_0006789e(0);
      FUN_000628f4();
      FUN_000627a0();
    }
    uVar1 = FUN_000678b4(1);
    if ((uVar1 & 0xff) != 0) {
      FUN_000623a0(1);
      FUN_00062668();
      FUN_0006789e(0);
      FUN_000628f4();
      uVar1 = FUN_000627a0();
    }
  }
  DAT_ffffd7b3 = 0;
  DAT_ffffd7b4 = 0;
  return uVar1;
}


