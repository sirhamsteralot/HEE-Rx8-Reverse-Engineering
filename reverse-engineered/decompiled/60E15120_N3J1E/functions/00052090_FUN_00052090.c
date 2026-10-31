/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b54c: Table 2D - 371 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00052090; body bytes: 398; decompiled */

uint FUN_00052090(void)

{
  bool bVar1;
  char cVar2;
  byte snapshot_DAT_ffffd10c;
  byte bVar4;
  char cVar5;
  uint uVar6;
  undefined4 uVar7;
  
  snapshot_DAT_ffffd10c = DAT_ffffd10c;
  uVar7 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff867c);
  DAT_ffffd124 = rx8_lookup_2d_raw_u8(uVar7,&tbl_table_2d_371_check_datatype_0006b54c);
  bVar4 = ref_getKnownBooleanValue__();
  cVar2 = DAT_ffffd03d;
  if (DAT_ffffd03d == '\x01') {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d0,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86ce,0);
  }
  else {
    if (((DAT_ffffcfbf == '\x01') && (DAT_ffffcfa8 < DAT_ffffcfaa)) && (DAT_ffffd125 != snapshot_DAT_ffffd10c)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (((bVar1) && (snapshot_DAT_ffffd10c < DAT_ffffd124)) || (DAT_ffffd147 == '\x01')) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86ce,1);
    }
    if ((bVar1) && (DAT_ffffd124 <= snapshot_DAT_ffffd10c)) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d0,1);
    }
  }
  if ((DAT_ffffd039 == '\x01') || (DAT_ffffcf78 == '\x01')) {
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  if (DAT_ffffd03e == '\x01') {
    DAT_ffffd117 = 0;
  }
  else if (((uVar6 == 1) &&
           (cVar5 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86ce,0), cVar5 == '\x01')) &&
          (cVar5 = ref_getFaultStatus__(0x77), cVar5 == '\0')) {
    DAT_ffffd117 = 1;
  }
  if (cVar2 == '\x01') {
    DAT_ffffd118 = 0;
    uVar6 = 1;
  }
  else if (uVar6 == 1) {
    uVar6 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86d0,0);
    uVar6 = uVar6 & 0xff;
    if (uVar6 == 1) {
      uVar6 = ref_getFaultStatus__(0x77);
      uVar6 = uVar6 & 0xff;
      if (uVar6 == 0) {
        DAT_ffffd118 = 1;
      }
    }
  }
  if ((DAT_ffffd127 == '\0') && (uVar6 = (uint)bVar4, uVar6 == 1)) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86ce,0);
    uVar6 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d0,0);
  }
  DAT_ffffd125 = snapshot_DAT_ffffd10c;
  DAT_ffffd127 = bVar4;
  return uVar6;
}


