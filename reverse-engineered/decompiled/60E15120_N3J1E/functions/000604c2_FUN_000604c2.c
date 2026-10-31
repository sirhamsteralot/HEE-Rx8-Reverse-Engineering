/* ROM address: 0x000604c2; body bytes: 36; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005edb2 (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000604c2(char param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(short)DAT_ffffd3b4;
  if (param_1 == '\0') {
    uVar1 = (uint)(DAT_ffffd3b4 >> 8);
  }
  else if (param_1 != '\x01') {
    uVar1 = 0;
  }
  return uVar1;
}


