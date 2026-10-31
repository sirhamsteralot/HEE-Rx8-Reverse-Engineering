/* ROM address: 0x0005fa74; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e380 (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_faultSomething0x2(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00061450(0x80);
  if ((uVar1 & 0xffff) != 0) {
    uVar2 = FUN_0005f8fa();
    if ((uVar2 & 0xffff) != 0) {
      uVar1 = (uVar1 - uVar2) + 1;
    }
    if (0x7f < (uVar1 & 0xffff)) {
      uVar1 = 0x7f;
    }
  }
  return uVar1;
}


