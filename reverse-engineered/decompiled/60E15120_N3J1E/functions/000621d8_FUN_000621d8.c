/* ROM address: 0x000621d8; body bytes: 150; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060ac8 (150 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000621d8(byte param_1,byte param_2)

{
  undefined4 uVar1;
  
  if (param_1 != param_2) {
    if (param_2 == 1) {
      if ((param_1 == 0) || (param_1 == 0x50)) {
        FUN_000618ba();
        uVar1 = FUN_000618b4();
        FUN_0006317c(uVar1);
        FUN_000631fc(0xffff);
        return;
      }
    }
    else if (((param_2 == 0xc0) || (param_2 == 0xc1)) && ((param_1 & 0x80) != 0x80)) {
      FUN_000618ba();
      uVar1 = FUN_000618b4();
      FUN_000631fc(uVar1);
      if ((param_1 == 0) || (param_1 == 0x50)) {
        FUN_0006317c(uVar1);
        return;
      }
    }
  }
  return;
}


