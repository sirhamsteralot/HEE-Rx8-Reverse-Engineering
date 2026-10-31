/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b4a4: Table 2D - 367 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b4b0: Table 2D - 368 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000500b0; body bytes: 352; decompiled */

uint FUN_000500b0(void)

{
  ushort snapshot_DAT_ffffcfaa;
  byte snapshot_DAT_ffffd040;
  uint uVar3;
  float fVar4;
  undefined4 uVar5;
  
  snapshot_DAT_ffffcfaa = DAT_ffffcfaa;
  uVar5 = 0;
  fVar4 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff8684);
  uVar5 = ref_readValue_float_DEFAULTVAL_ADDRESS(uVar5,&DAT_ffff867c);
  DAT_ffffd070 = rx8_lookup_2d_raw_u16(uVar5,&tbl_table_2d_367_check_datatype_0006b4a4);
  DAT_ffffd07a = rx8_lookup_2d_raw_u16(uVar5,&tbl_table_2d_368_check_datatype_0006b4b0);
  snapshot_DAT_ffffd040 = DAT_ffffd040;
  DAT_ffffd048 = 0;
  DAT_ffffd049 = 0;
  if ((DAT_ffffd1c5 == '\x01') || (DAT_ffffd03f == '\x01')) {
    DAT_ffffd041 = '\0';
  }
  else if (((snapshot_DAT_ffffcfaa == DAT_ffffd070) && (fVar4 < DAT_ffffd020)) && (DAT_ffffd040 == 1)) {
    DAT_ffffd041 = '\x01';
  }
  if ((DAT_ffffd1c5 == '\x01') || (DAT_ffffd03f == '\x01')) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86a0,0);
    uVar3 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86a2,0);
  }
  else {
    if (((snapshot_DAT_ffffcfaa == DAT_ffffd07a) && (fVar4 < DAT_ffffd024)) && (DAT_ffffd041 == '\x01')) {
      if (DAT_ffffd040 != 1) {
        DAT_ffffd048 = 0;
        DAT_ffffd049 = 0;
        return (uint)DAT_ffffd040;
      }
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86a0,1);
      DAT_ffffd048 = 1;
    }
    uVar3 = (uint)snapshot_DAT_ffffd040;
    if ((uVar3 == 1) &&
       ((((snapshot_DAT_ffffcfaa <= DAT_ffffd07a && (DAT_ffffd070 < snapshot_DAT_ffffcfaa)) && (DAT_ffffd034 <= fVar4)) ||
        (((snapshot_DAT_ffffcfaa <= DAT_ffffd070 && (DAT_ffffcfa8 < snapshot_DAT_ffffcfaa)) &&
         ((uVar3 = (uint)DAT_ffffcff8, uVar3 == 0 && (DAT_ffffd030 <= fVar4)))))))) {
      uVar3 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86a2,1);
      DAT_ffffd049 = 1;
    }
  }
  return uVar3;
}


