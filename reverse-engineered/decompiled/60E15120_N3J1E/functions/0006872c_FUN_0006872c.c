/* ROM address: 0x0006872c; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0006701c (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0006872c(void)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((DAT_ffffddeb == '\x04') && (DAT_ffffdded == (DAT_ffffddc8 & 0xf))) {
    if ((DAT_ffffddc8 & 0xf) < 0xf) {
      DAT_ffffdded = DAT_ffffdded + 1;
    }
    else {
      DAT_ffffdded = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


