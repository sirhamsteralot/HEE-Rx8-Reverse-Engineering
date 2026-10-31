/* ROM address: 0x00061800; body bytes: 56; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000600f0 (56 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00061800(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00062df8();
  uVar2 = uVar1 & 0xff;
  if ((uVar2 == 0) || (0x3f < uVar2)) {
    if ((0x80 < uVar2) && (uVar2 < 0xc0)) {
      uVar1 = 0x70;
    }
  }
  else {
    uVar1 = 0x60;
  }
  return uVar1;
}


