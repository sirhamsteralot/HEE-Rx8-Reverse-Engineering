/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b4b0: Table 2D - 368 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00050018; body bytes: 152; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004dc34 (152 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00050018(void)

{
  ushort snapshot_DAT_ffffcfaa;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  snapshot_DAT_ffffcfaa = DAT_ffffcfaa;
  uVar4 = 0;
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff867c);
  DAT_ffffd078 = rx8_lookup_2d_raw_u16(uVar3,&tbl_table_2d_368_check_datatype_0006b4b0);
  if (DAT_ffffd1c5 == '\x01') {
    puVar2 = (undefined1 *)ref_updateMemoryAtAddress_float_VAL_ADDR(uVar4,&DAT_ffff8684);
    return puVar2;
  }
  if (((DAT_ffffd040 != '\x01') || (DAT_ffffd078 < snapshot_DAT_ffffcfaa)) &&
     ((DAT_ffffcf85 < 0x28 || ((snapshot_DAT_ffffcfaa <= DAT_ffffcfa8 || (DAT_ffffcff8 != '\0')))))) {
    return &DAT_0007dd8d;
  }
  puVar2 = (undefined1 *)
           ref_updateMemoryAtAddress_float_VAL_ADDR(DAT_ffffcfe0 - DAT_ffffcfe8,&DAT_ffff8684);
  return puVar2;
}


