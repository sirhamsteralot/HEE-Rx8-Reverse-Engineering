/* ROM address: 0x0005a188; body bytes: 184; decompiled */

uint FUN_0005a188(void)

{
  char cVar1;
  byte bVar3;
  uint uVar2;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  
  uVar7 = 0;
  fVar4 = (float)rx8_decode_u8_affine(0x39cdc3b7,0,(int)DAT_ffffce24);
  cVar1 = DAT_ffffd1c5;
  bVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8fd8,0);
  DAT_ffffd280 = fVar4 - DAT_ffffd28c;
  if (DAT_ffffd280 < 0.0) {
    DAT_ffffd280 = DAT_ffffd280 + 0.09968603;
  }
  if ((((DAT_ffffd290 == '\0') && (bVar3 == 1)) || (mil_lamp_flag_ffffd286 == '\0')) || (cVar1 == '\x01')) {
    uVar2 = ref_updateMemoryAtAddress_float_VAL_ADDR(uVar7,&distance_mil_on_ffff90f4_ffff90f4);
  }
  else {
    uVar2 = (uint)bVar3;
    if (uVar2 == 1) {
      fVar5 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(uVar7,&distance_mil_on_ffff90f4_ffff90f4);
      fVar6 = fVar5 + DAT_ffffd280;
      if (65535.0 < fVar5 + DAT_ffffd280) {
        fVar6 = 65535.0;
      }
      uVar2 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar6,&distance_mil_on_ffff90f4_ffff90f4);
    }
  }
  DAT_ffffd290 = bVar3;
  DAT_ffffd28c = fVar4;
  return uVar2;
}


