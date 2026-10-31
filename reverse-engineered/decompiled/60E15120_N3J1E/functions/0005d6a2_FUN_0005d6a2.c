/* ROM address: 0x0005d6a2; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005be92 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005d6a2(short param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xff;
  uVar1 = 0;
  while (((uVar1 & 0xff) < 0x1a && ((uVar2 & 0xff) == 0xff))) {
    if ((&DAT_0005f728)[(uVar1 & 0xff) * 8] == param_1) {
      uVar2 = uVar1;
    }
    uVar1 = uVar1 + 1;
  }
  return uVar2;
}


