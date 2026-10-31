/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b3bc: Table 2D - 366 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x0004f1f8; body bytes: 54; decompiled */

ushort FUN_0004f1f8(void)

{
  bool bVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff867c);
  uVar2 = rx8_lookup_2d_raw_u16(uVar3,&tbl_table_2d_366_check_datatype_0006b3bc);
  DAT_ffffcfcc = uVar2;
  bVar1 = DAT_ffffcfaa < uVar2;
  if (bVar1) {
    uVar2 = 0;
  }
  DAT_ffffcfc5 = !bVar1;
  return uVar2;
}


