/* ROM address: 0x000522bc; body bytes: 332; decompiled */

uint FUN_000522bc(void)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  float fVar5;
  
  fVar5 = DAT_ffffcfe4 - DAT_ffffcfe8;
  bVar2 = ref_getKnownBooleanValue__();
  cVar1 = DAT_ffffd03d;
  if (DAT_ffffd03d == '\x01') {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d2,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d4,0);
  }
  else if (((DAT_ffffcfbf == '\x01') && (DAT_ffffcfa8 < DAT_ffffcfaa)) && (DAT_ffffcff8 == '\0')) {
    if (fVar5 < 0.0019) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d2,1);
    }
    if (0.0019 <= fVar5) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d4,1);
    }
  }
  if ((DAT_ffffd039 == '\x01') || (DAT_ffffcf78 == '\x01')) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  if (DAT_ffffd03e == '\x01') {
    DAT_ffffd115 = 0;
  }
  else if (((uVar4 == 1) &&
           (cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86d2,0), cVar3 == '\x01')) &&
          (cVar3 = ref_getFaultStatus__(0x30), cVar3 == '\0')) {
    DAT_ffffd115 = 1;
  }
  if (cVar1 == '\x01') {
    DAT_ffffd116 = 0;
    uVar4 = 1;
  }
  else if (uVar4 == 1) {
    uVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86d4,0);
    uVar4 = uVar4 & 0xff;
    if (uVar4 == 1) {
      uVar4 = ref_getFaultStatus__(0x30);
      uVar4 = uVar4 & 0xff;
      if (uVar4 == 0) {
        DAT_ffffd116 = 1;
      }
    }
  }
  if ((DAT_ffffd128 == '\0') && (uVar4 = (uint)bVar2, uVar4 == 1)) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d2,0);
    uVar4 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d4,0);
  }
  DAT_ffffd128 = bVar2;
  return uVar4;
}


