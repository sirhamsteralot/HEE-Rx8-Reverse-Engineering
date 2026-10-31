/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b558: Table 2D - 250 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b56c: Table 2D - 251 (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00051eae; body bytes: 380; decompiled */

uint FUN_00051eae(void)

{
  byte bVar2;
  uint uVar1;
  char cVar3;
  float snapshot_DAT_ffffcfec;
  float snapshot_DAT_ffffcff0;
  
  snapshot_DAT_ffffcfec = DAT_ffffcfec;
  snapshot_DAT_ffffcff0 = DAT_ffffcff0;
  DAT_ffffd120 = (float)lookup_2d_descriptor_scaled(inferred_battery_voltage_ffffb590,&tbl_table_2d_251_0006b56c);
  DAT_ffffd11c = (float)lookup_2d_descriptor_scaled(inferred_battery_voltage_ffffb590,&tbl_table_2d_250_0006b558);
  bVar2 = ref_getKnownBooleanValue__();
  if (DAT_ffffd03d == '\x01') {
    DAT_ffffd112 = 0;
    DAT_ffffd113 = 0;
    DAT_ffffd114 = 0;
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c8,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86ca,0);
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86cc,0);
  }
  else {
    if ((DAT_ffffcfbf == '\x01') && (DAT_ffffcfaa == DAT_ffffcfa8)) {
      if (snapshot_DAT_ffffcff0 < DAT_ffffd120) {
        ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c8,1);
      }
      if (DAT_ffffd11c < snapshot_DAT_ffffcfec) {
        ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86ca,1);
      }
      if ((snapshot_DAT_ffffcfec <= DAT_ffffd11c) && (DAT_ffffd120 <= snapshot_DAT_ffffcff0)) {
        ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86cc,1);
      }
    }
    if ((DAT_ffffd039 == '\x01') || (uVar1 = (uint)DAT_ffffcf78, uVar1 == 1)) {
      cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c8,0);
      if ((cVar3 == '\x01') && (cVar3 = ref_getFaultStatus__(0x78), cVar3 == '\0')) {
        DAT_ffffd112 = 1;
      }
      cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86ca,0);
      if ((cVar3 == '\x01') && (cVar3 = ref_getFaultStatus__(0x79), cVar3 == '\0')) {
        DAT_ffffd113 = 1;
      }
      uVar1 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86cc,0);
      uVar1 = uVar1 & 0xff;
      if (uVar1 == 1) {
        uVar1 = ref_getFaultStatus__(0x78);
        uVar1 = uVar1 & 0xff;
        if (uVar1 == 0) {
          uVar1 = ref_getFaultStatus__(0x79);
          uVar1 = uVar1 & 0xff;
          if (uVar1 == 0) {
            DAT_ffffd114 = 1;
          }
        }
      }
    }
    if ((DAT_ffffd126 == '\0') && (uVar1 = (uint)bVar2, uVar1 == 1)) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c8,0);
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86ca,0);
      uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86cc,0);
    }
  }
  DAT_ffffd126 = bVar2;
  return uVar1;
}


