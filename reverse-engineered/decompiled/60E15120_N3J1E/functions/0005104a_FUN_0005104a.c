/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b4d0: Table 2D - 245 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b520: Table 2D - 369 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b52c: Table 2D - 370 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b5c0: Table 2D - 374 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0005104a; body bytes: 490; decompiled */

uint FUN_0005104a(void)

{
  ushort snapshot_DAT_ffffd0a4;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  
  snapshot_DAT_ffffd0a4 = DAT_ffffd0a4;
  uVar7 = 0;
  uVar4 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff867c);
  fVar5 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(uVar7,&DAT_ffff86a8);
  DAT_ffffd0c4 = (float)lookup_2d_descriptor_scaled(uVar4,&tbl_table_2d_374_check_datatype_0006b5c0);
  DAT_ffffd0c8 = (float)lookup_2d_descriptor_scaled(uVar4,&tbl_table_2d_245_0006b4d0);
  DAT_ffffd0cc = rx8_lookup_2d_raw_u16(uVar4,&tbl_table_2d_369_check_datatype_0006b520);
  DAT_ffffd0ce = rx8_lookup_2d_raw_u16(uVar4,&tbl_table_2d_370_check_datatype_0006b52c);
  cVar3 = DAT_ffffcfca;
  DAT_ffffd0ac = 0;
  DAT_ffffd0ad = 0;
  if ((DAT_ffffd1c5 == '\x01') || (DAT_ffffd03f == '\x01')) {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c0,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c2,0);
  }
  else if (DAT_ffffd0a8 == '\x01') {
    if (((((DAT_ffffd0cc < snapshot_DAT_ffffd0a4) &&
          (fVar6 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff86b8), fVar5 < fVar6))
         && (cVar3 == '\x01')) && ((DAT_ffffd098 < DAT_ffffd0c4 && (DAT_ffffd0c8 < DAT_ffffd094))))
       || ((DAT_ffffcfc5 == '\x01' && (DAT_ffffcfe0 < DAT_ffffcfe4)))) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c0,1);
      DAT_ffffd0ac = 1;
    }
    if (((DAT_ffffd0ce < snapshot_DAT_ffffd0a4) && (DAT_ffffd09c <= fVar5)) && (cVar3 == '\x01')) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c2,1);
      DAT_ffffd0ad = 1;
    }
  }
  FUN_00052f44();
  if (DAT_ffffd03d == '\x01') {
    DAT_ffffd0a9 = 0;
    DAT_ffffd0aa = 0;
    uVar2 = 1;
  }
  else if ((DAT_ffffd039 == '\x01') || (uVar2 = (uint)DAT_ffffcf78, uVar2 == 1)) {
    cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c0,0);
    if ((cVar3 == '\x01') && (cVar3 = ref_getFaultStatus__(0x32), cVar3 == '\0')) {
      DAT_ffffd0a9 = 1;
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c0,0);
    }
    uVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c2,0);
    uVar2 = uVar2 & 0xff;
    if (uVar2 == 1) {
      uVar2 = ref_getFaultStatus__(0x32);
      uVar2 = uVar2 & 0xff;
      if (uVar2 == 0) {
        DAT_ffffd0aa = 1;
        uVar2 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c2,0);
      }
    }
  }
  return uVar2;
}


