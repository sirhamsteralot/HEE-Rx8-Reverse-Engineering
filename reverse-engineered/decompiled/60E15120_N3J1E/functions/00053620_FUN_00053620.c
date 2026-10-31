/* ROM address: 0x00053620; body bytes: 76; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000515a4 (76 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00053620(void)

{
  undefined4 uVar1;
  float fVar2;
  
  fVar2 = (float)rx8_decode_u16_affine(0x3f800000,0,(int)DAT_ffffc4c2);
  if (DAT_ffffd00c != 0) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fbc,0);
    return uVar1;
  }
  if (360.0 < fVar2) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fbc,1);
    return uVar1;
  }
  return 0;
}


