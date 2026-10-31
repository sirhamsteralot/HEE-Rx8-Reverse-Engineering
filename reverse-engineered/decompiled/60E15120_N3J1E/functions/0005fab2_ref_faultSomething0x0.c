/* ROM address: 0x0005fab2; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e3be (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_faultSomething0x0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_00061450(0x80,0);
  if ((uVar1 & 0xffff) != 0) {
    uVar2 = FUN_0005f8fa();
    if ((uVar2 & 0xffff) != 0) {
      uVar1 = (uVar1 - uVar2) + 1;
    }
    if (0xff < (uVar1 & 0xffff)) {
      uVar1 = 0xff;
    }
  }
  return uVar1;
}


