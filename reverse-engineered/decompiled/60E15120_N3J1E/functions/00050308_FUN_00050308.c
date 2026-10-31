/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b4a4: Table 2D - 367 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b4b0: Table 2D - 368 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00050308; body bytes: 368; decompiled */

uint FUN_00050308(void)

{
  ushort snapshot_DAT_ffffcfaa;
  byte snapshot_DAT_ffffd040;
  uint uVar3;
  char cVar4;
  float fVar5;
  undefined4 uVar6;
  
  snapshot_DAT_ffffcfaa = DAT_ffffcfaa;
  uVar6 = 0;
  fVar5 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff8684);
  uVar6 = ref_readValue_float_DEFAULTVAL_ADDRESS(uVar6,&DAT_ffff867c);
  DAT_ffffd072 = rx8_lookup_2d_raw_u16(uVar6,&tbl_table_2d_367_check_datatype_0006b4a4);
  DAT_ffffd07c = rx8_lookup_2d_raw_u16(uVar6,&tbl_table_2d_368_check_datatype_0006b4b0);
  snapshot_DAT_ffffd040 = DAT_ffffd040;
  DAT_ffffd04a = 0;
  DAT_ffffd04b = 0;
  if ((DAT_ffffd1c5 == '\x01') || (DAT_ffffd03f == '\x01')) {
    DAT_ffffd044 = '\0';
  }
  else if (((snapshot_DAT_ffffcfaa == DAT_ffffd072) && (fVar5 < DAT_ffffd018)) && (DAT_ffffd040 == 1)) {
    DAT_ffffd044 = '\x01';
  }
  if ((DAT_ffffd1c5 == '\x01') || (DAT_ffffd03f == '\x01')) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86a4,0);
    uVar3 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86a6,0);
  }
  else {
    if (((snapshot_DAT_ffffcfaa == DAT_ffffd07c) && (fVar5 < DAT_ffffd01c)) && (DAT_ffffd044 == '\x01')) {
      if (DAT_ffffd040 != 1) {
        DAT_ffffd04a = 0;
        DAT_ffffd04b = 0;
        return (uint)DAT_ffffd040;
      }
      cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a0,0);
      if (cVar4 == '\0') {
        ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86a4,1);
        DAT_ffffd04a = 1;
      }
    }
    uVar3 = (uint)snapshot_DAT_ffffd040;
    if ((uVar3 == 1) &&
       ((((snapshot_DAT_ffffcfaa <= DAT_ffffd07c && (DAT_ffffd072 < snapshot_DAT_ffffcfaa)) && (DAT_ffffd02c <= fVar5)) ||
        (((snapshot_DAT_ffffcfaa <= DAT_ffffd072 && (DAT_ffffcfa8 < snapshot_DAT_ffffcfaa)) &&
         ((uVar3 = (uint)DAT_ffffcff8, uVar3 == 0 && (DAT_ffffd028 <= fVar5)))))))) {
      uVar3 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86a6,1);
      DAT_ffffd04b = 1;
    }
  }
  return uVar3;
}


