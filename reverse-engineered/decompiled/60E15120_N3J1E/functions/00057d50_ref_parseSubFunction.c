/* ROM address: 0x00057d50; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00056220 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_parseSubFunction(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_1 == '\x01') {
    if (DAT_ffffd1cc == '\x01') {
      uVar1 = 0;
    }
  }
  else if (param_1 == '\x04') {
    if (DAT_ffffd1cd == '\x01') {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


