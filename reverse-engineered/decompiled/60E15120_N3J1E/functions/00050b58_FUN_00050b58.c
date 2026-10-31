/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b4e4: Table 2D - 246 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b4f8: Table 2D - 247 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b50c: Table 2D - 248 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00050b58; body bytes: 170; decompiled */

uint FUN_00050b58(void)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  float fVar4;
  
  fVar4 = 0.0;
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff867c);
  DAT_ffffd0bc = (float)lookup_2d_descriptor_scaled(uVar3,&tbl_table_2d_247_0006b4f8);
  DAT_ffffd0c0 = (float)lookup_2d_descriptor_scaled(uVar3,&tbl_table_2d_248_0006b50c);
  DAT_ffffd0b8 = (float)lookup_2d_descriptor_scaled(DAT_ffffd014,&tbl_table_2d_246_0006b4e4);
  cVar1 = DAT_ffffcff8;
  if (DAT_ffffd1c5 == '\x01') {
    uVar2 = ref_updateMemoryAtAddress_float_VAL_ADDR(fVar4,&DAT_ffff86b8);
    DAT_ffffd09c = fVar4;
  }
  else {
    uVar2 = (uint)DAT_ffffd0a8;
    if ((((uVar2 == 1) && (uVar2 = (uint)DAT_ffffcfaa, (uint)(int)DAT_ffffcfa8 < uVar2)) &&
        (uVar2 = (uint)DAT_ffffd0d2, uVar2 != 0)) && (DAT_ffffcff8 == '\0')) {
      uVar2 = ref_updateMemoryAtAddress_float_VAL_ADDR(DAT_ffffd0b8 * DAT_ffffd0bc,&DAT_ffff86b8);
      DAT_ffffd09c = DAT_ffffd0b8 * DAT_ffffd0c0;
    }
  }
  DAT_ffffd0d2 = cVar1;
  return uVar2;
}


