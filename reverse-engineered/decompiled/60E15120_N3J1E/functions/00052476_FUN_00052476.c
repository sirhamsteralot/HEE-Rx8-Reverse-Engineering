/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00052476; body bytes: 492; decompiled */

uint FUN_00052476(void)

{
  ushort snapshot_DAT_ffffcfa8;
  ushort snapshot_DAT_ffffcfaa;
  char cVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  float snapshot_DAT_ffffcfe0;
  
  snapshot_DAT_ffffcfaa = DAT_ffffcfaa;
  snapshot_DAT_ffffcfa8 = DAT_ffffcfa8;
  snapshot_DAT_ffffcfe0 = DAT_ffffcfe0;
  bVar4 = ref_getKnownBooleanValue__();
  cVar3 = DAT_ffffd03d;
  if (DAT_ffffd03d == '\x01') {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d6,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d8,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86da,0);
  }
  else if ((DAT_ffffcfbf == '\x01') &&
          ((((DAT_ffffcfa6 < snapshot_DAT_ffffcfaa && (snapshot_DAT_ffffcfaa <= snapshot_DAT_ffffcfa8)) && (DAT_ffffcff8 == '\0')) ||
           ((snapshot_DAT_ffffcfa8 < snapshot_DAT_ffffcfaa &&
            (((DAT_ffffcfc6 == '\x01' && (DAT_ffffcfc5 == '\0')) ||
             ((DAT_ffffd0f2 == '\x01' && (snapshot_DAT_ffffcfaa < 0x88)))))))))) {
    if (snapshot_DAT_ffffcfe0 < 0.001) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d6,1);
    }
    if (0.03207 < snapshot_DAT_ffffcfe0) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d8,1);
    }
    if ((snapshot_DAT_ffffcfe0 <= 0.03207) && (0.001 <= snapshot_DAT_ffffcfe0)) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86da,1);
    }
  }
  if ((DAT_ffffd039 == '\x01') || (DAT_ffffcf78 == '\x01')) {
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  if (DAT_ffffd03e == '\x01') {
    DAT_ffffd10f = 0;
    DAT_ffffd110 = 0;
  }
  else if (uVar6 == 1) {
    cVar5 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86d6,0);
    if ((cVar5 == '\x01') && (cVar5 = ref_getFaultStatus__(0x75), cVar5 == '\0')) {
      DAT_ffffd10f = 1;
    }
    cVar5 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86d8,0);
    if ((cVar5 == '\x01') && (cVar5 = ref_getFaultStatus__(0x76), cVar5 == '\0')) {
      DAT_ffffd110 = 1;
    }
  }
  if (cVar3 == '\x01') {
    DAT_ffffd111 = 0;
    uVar6 = 1;
  }
  else if (uVar6 == 1) {
    uVar6 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86da,0);
    uVar6 = uVar6 & 0xff;
    if (uVar6 == 1) {
      uVar6 = ref_getFaultStatus__(0x75);
      uVar6 = uVar6 & 0xff;
      if (uVar6 == 0) {
        uVar6 = ref_getFaultStatus__(0x76);
        uVar6 = uVar6 & 0xff;
        if (uVar6 == 0) {
          DAT_ffffd111 = 1;
        }
      }
    }
  }
  if ((DAT_ffffd129 == '\0') && (uVar6 = (uint)bVar4, uVar6 == 1)) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d6,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d8,0);
    uVar6 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86da,0);
  }
  DAT_ffffd129 = bVar4;
  return uVar6;
}


