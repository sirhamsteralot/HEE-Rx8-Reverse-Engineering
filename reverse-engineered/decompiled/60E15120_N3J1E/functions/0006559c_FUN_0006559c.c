/* ROM address: 0x0006559c; body bytes: 44; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063e8c (44 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0006559c(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xff;
  if ((uVar1 == 0) || (0x3f < uVar1)) {
    if ((0x80 < uVar1) && (uVar1 < 0xc0)) {
      param_1 = 0x70;
    }
  }
  else {
    param_1 = 0x60;
  }
  return param_1;
}


