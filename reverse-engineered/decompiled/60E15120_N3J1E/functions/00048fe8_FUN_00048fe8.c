/* ROM address: 0x00048fe8; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00048074 (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00048fe8(void)

{
  uint uVar1;
  float fVar2;
  
  fVar2 = rx8_absolute_difference(DAT_ffffb4bc,0.0);
  uVar1 = (uint)DAT_ffffccbb;
  if (uVar1 == 1) {
    if (fVar2 < 80.0) {
      DAT_ffffccce = 0;
    }
    else {
      uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873e,0);
      uVar1 = uVar1 & 0xff;
      if (uVar1 == 0) {
        uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffccce,1);
        DAT_ffffccce = (ushort)uVar1;
      }
    }
  }
  else {
    DAT_ffffccce = 0;
  }
  DAT_ffffccc8 = 4 < DAT_ffffccce;
  return uVar1;
}


