/* ROM address: 0x00045b3c; body bytes: 208; decompiled */

uint FUN_00045b3c(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_getFaultStatus__(0x67);
  if (((cVar2 == '\0') && (DAT_ffffccc2 == '\x01')) &&
     (cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8730,0), cVar2 == '\0')) {
    if (DAT_ffffa110 == '\x01') {
      DAT_ffffcbf6 = rx8_add_u16_saturate((int)(short)DAT_ffffcbf6,1);
      DAT_ffffcbf8 = 0;
      if (0x18 < DAT_ffffcbf6) {
        ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8730,1);
      }
    }
    else {
      DAT_ffffcbf8 = rx8_add_u16_saturate((int)(short)DAT_ffffcbf8,1);
      if (0x18 < DAT_ffffcbf8) {
        DAT_ffffcbf4 = 1;
        DAT_ffffcbf6 = 0;
      }
    }
  }
  else {
    DAT_ffffcbf8 = 0;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8730,0);
  if (cVar2 == '\x01') {
    uVar1 = dtc_set_fault_x0(0x67,1);
    return uVar1;
  }
  if (DAT_ffffcbf4 == 1) {
    uVar1 = dtc_set_fault_x0(0x67,2);
    return uVar1;
  }
  return (uint)DAT_ffffcbf4;
}


