/* ROM address: 0x00011d88; body bytes: 256; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00011e00 (256 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00011d88(void)

{
  uint uVar1;
  char cVar3;
  uint uVar2;
  
  if ((DAT_ffff9ec8 & 1) == 0) {
    uVar1 = FUN_00009c8e(0);
    if (uVar1 != 0) {
      if ((uVar1 & 0x2000) == 0) {
        if ((uVar1 & 0x4000) != 0) {
          uVar1 = ref_placeCANRX(&DAT_0004dffc);
        }
      }
      else {
        uVar1 = ref_placeCANRX(&DAT_0004dfec);
      }
    }
  }
  else {
    uVar1 = FUN_00009c8e(0);
    if (uVar1 != 0) {
      if ((uVar1 & 0x2000) == 0) {
        if ((uVar1 & 0x4000) != 0) {
          cVar3 = ref_placeCANRX();
          uVar2 = FUN_00009c34(&DAT_0004dffc);
          uVar1 = (uint)cVar3;
          if ((uVar1 == 0) && (uVar1 = uVar2 & 0xff, uVar1 == 8)) {
            uVar1 = FUN_000680a0(0x7e0);
            return uVar1;
          }
        }
      }
      else {
        cVar3 = ref_placeCANRX();
        uVar2 = FUN_00009c34(&DAT_0004dfec);
        uVar1 = (uint)cVar3;
        if ((uVar1 == 0) && (uVar1 = uVar2 & 0xff, uVar1 == 8)) {
          uVar1 = FUN_000680a0(0x7df);
          return uVar1;
        }
      }
    }
  }
  return uVar1;
}


