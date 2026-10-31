/* [CROSS-ECU / RX8DEFS REVIEW]
 * Descriptor 0x0006ba44: Table 2D - 382 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ba50: Table 2D - 383 Check DataType (RX8Defs data pointer, axes and dimensions match).
 * Descriptor 0x0006ba5c: Table 2D - 384 Check DataType (RX8Defs data pointer, axes and dimensions match).
 */
/* ROM address: 0x00046404; body bytes: 414; decompiled */

uint FUN_00046404(void)

{
  char cVar2;
  uint uVar1;
  float fVar3;
  float arg0;
  float arg1;
  
  arg0 = DAT_ffffb40c;
  arg1 = DAT_ffffad30;
  fVar3 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x41700000,&DAT_ffff807c);
  DAT_ffffcc20 = arg1 - fVar3;
  DAT_ffffcc24 = arg0 - fVar3;
  fVar3 = rx8_absolute_difference(arg0,arg1);
  DAT_ffffcc2c = (float)lookup_2d_descriptor_scaled(DAT_ffffcc24,&tbl_table_2d_384_check_datatype_0006ba5c);
  if (DAT_ffffcc28 == '\x01') {
    if (fVar3 < DAT_ffffcc2c) {
      if (0xf9 < DAT_ffffcc3a) {
        DAT_ffffcc1c = 1;
      }
      DAT_ffffcc34 = 0;
      DAT_ffffcc36 = 0;
      DAT_ffffcc38 = 0;
      DAT_ffffcc3a = rx8_add_u16_saturate((int)(short)DAT_ffffcc3a,1);
    }
    else if (engine_speed_rpm_ffffb548 < 500.0) {
      if (0x9c3 < DAT_ffffcc38) {
        ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8740,1);
      }
      DAT_ffffcc34 = 0;
      DAT_ffffcc36 = 0;
      DAT_ffffcc38 = rx8_add_u16_saturate((int)(short)DAT_ffffcc38,1);
      DAT_ffffcc3a = 0;
    }
    else {
      if (arg1 < arg0) {
        DAT_ffffcc32 = rx8_lookup_2d_raw_u16(DAT_ffffcc20,&tbl_table_2d_383_check_datatype_0006ba50);
        if (DAT_ffffcc32 <= DAT_ffffcc36) {
          ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8740,1);
        }
        DAT_ffffcc34 = 0;
        DAT_ffffcc36 = rx8_add_u16_saturate((int)(short)DAT_ffffcc36,1);
      }
      else {
        DAT_ffffcc30 = rx8_lookup_2d_raw_u16(&tbl_table_2d_382_check_datatype_0006ba44);
        if (DAT_ffffcc30 <= DAT_ffffcc34) {
          ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8740,1);
        }
        DAT_ffffcc34 = rx8_add_u16_saturate((int)(short)DAT_ffffcc34,1);
        DAT_ffffcc36 = 0;
      }
      DAT_ffffcc38 = 0;
      DAT_ffffcc3a = 0;
    }
  }
  else {
    DAT_ffffcc34 = 0;
    DAT_ffffcc36 = 0;
    DAT_ffffcc38 = 0;
    DAT_ffffcc3a = 0;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8740,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_0005fd38(0x46,1);
    return uVar1;
  }
  if (DAT_ffffcc1c == 1) {
    uVar1 = FUN_0005fd38(0x46,2);
    return uVar1;
  }
  return (uint)DAT_ffffcc1c;
}


