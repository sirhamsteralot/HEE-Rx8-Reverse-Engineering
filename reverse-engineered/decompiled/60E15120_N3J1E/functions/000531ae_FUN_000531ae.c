/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006b580: Table 2D - 252 (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006b594: Table 2D - 253 (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x000531ae; body bytes: 198; decompiled */

uint FUN_000531ae(void)

{
  ushort uVar2;
  uint uVar1;
  undefined4 uVar3;
  
  uVar3 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff867c);
  DAT_ffffd150 = (float)lookup_2d_descriptor_scaled(uVar3,&tbl_table_2d_252_0006b580);
  DAT_ffffd154 = (float)lookup_2d_descriptor_scaled(uVar3,&tbl_table_2d_253_0006b594);
  uVar2 = rx8_add_u16_saturate((int)DAT_ffffcfa8,1);
  if ((DAT_ffffd1c5 != '\x01') && (DAT_ffffcf78 != '\x01')) {
    if (DAT_ffffcfc6 != 1) {
      return (uint)DAT_ffffcfc6;
    }
    if (uVar2 <= DAT_ffffcfaa) {
      if (DAT_ffffd148 == '\x01') {
        if (DAT_ffffd150 < DAT_ffffd140) {
          uVar1 = rx8_add_u8_saturate((int)DAT_ffffd145,1);
          DAT_ffffd145 = (char)uVar1;
          return uVar1;
        }
      }
      else {
        if (DAT_ffffd149 != 1) {
          return (uint)DAT_ffffd149;
        }
        if ((DAT_ffffd150 < DAT_ffffd140) || (DAT_ffffd140 < DAT_ffffd154)) {
          uVar1 = rx8_add_u8_saturate((int)DAT_ffffd145,1);
          DAT_ffffd145 = (char)uVar1;
          return uVar1;
        }
      }
    }
  }
  DAT_ffffd145 = 0;
  return 1;
}


